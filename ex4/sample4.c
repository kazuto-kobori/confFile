#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define __init__
#define PHYS_SIZE (1 << 29) /* 512 MB */
#define PAGE_SIZE (1 << 12) /*   4 KB */

#define addr_to_fn(x)     ((x >> 12) & 0xfffff)
#define fn_to_addr(x)     (x << 12)
#define pfn_from_entry(x) ((x >> 12) & 0xfffff)

#define PRESENT_BIT  0x1
#define WRITABLE_BIT 0x2
#define USER_BIT     0x4

#define OFFSET_MASK  0xfff

#define KERN_BASE    0x80000000
#define KERN_SIZE    0x00400000

static int *org_addr;

static int read_entry(int pfn, int offset)
{
	int *entry;

	entry = (int*)((fn_to_addr(pfn) + (offset << 2)) + (int)org_addr);
	return *entry;
}

static int write_entry(int pfn, int offset, int value)
{
	int *entry;

	entry  = (int*)((fn_to_addr(pfn) + (offset << 2)) + (int)org_addr);
	*entry = value;
	return 0;
}

static int get_freepfn()
{
	static int freepfn = 0x10000;

	if (freepfn > (PHYS_SIZE >> 12)) {
		printf("memory leaked\n");
		exit(-1);
	}

	return freepfn++;
}

void __init__ init_physical_frames(int size)
{
	if ((org_addr = (int*)malloc(size)) == NULL) {
		perror("malloc");
		exit(-1);
	}

	memcpy(org_addr, org_addr+size, 0);
	return ;
}

int create_entry(int to_pfn, int flag)
{
	int entry = 0;

	entry |= to_pfn << 12;
	entry |= flag;
	return entry;
}

void __init__ init_page_table(int pd_addr)
{
	int entry, pd_pfn, pt_pfn, i, offset, pfn;

	pd_pfn = addr_to_fn(pd_addr);

	/* create kernel area mappings */
	pt_pfn = get_freepfn();
	entry  = create_entry(pt_pfn, PRESENT_BIT);
	offset = (KERN_BASE >> 22) & 0x3ff;
	write_entry(pd_pfn, offset, entry);

	for (i = 0; i < (KERN_SIZE >> 12); i++) {
		entry = create_entry(i, PRESENT_BIT);
		write_entry(pt_pfn, i, entry);
	}

	/* create user are mappings (text, data, stack)*/
	pt_pfn = get_freepfn();
	entry  = create_entry(pt_pfn, PRESENT_BIT);
	offset = 0;
	write_entry(pd_pfn, 0, entry);
	
	for (i = 0; i < 5; i++) {
		pfn   = get_freepfn();
		entry = create_entry(pfn, PRESENT_BIT);
		write_entry(pt_pfn, i, entry);
	}
}

int create_pd()
{
	int pd_addr;

	pd_addr = fn_to_addr(get_freepfn());

	return pd_addr;
}

int create_new_mappings(int va_start, int va_end, int pd_addr)
{
	int entry, pd_pfn, pt_pfn, pd_offset, pt_offset, pfn;
	int vfn_start, vfn_end;
	int i;

	pd_pfn    = addr_to_fn(pd_addr);
	vfn_start = addr_to_fn(va_start);
	vfn_end   = addr_to_fn(va_end);

	for (i = vfn_start; i <= vfn_end; i++) {
		pd_offset = (i >> 10) & 0x3ff;
		entry     = read_entry(pd_pfn, pd_offset);

		if ((entry & PRESENT_BIT)) {
			pt_pfn = (entry >> 12) & 0xfffff;
		} else {
			pt_pfn = get_freepfn();
			entry  = create_entry(pt_pfn, USER_BIT | PRESENT_BIT);
			write_entry(pd_pfn, pd_offset, entry);
		}
		
		pt_offset = i & 0x3ff;

		pfn   = get_freepfn();
		entry = create_entry(pfn, USER_BIT | PRESENT_BIT);
		write_entry(pt_pfn, pt_offset, entry);
	}

	return 0;
}

int virt_to_phys(int va, int pd_addr){
	int pd_pfn, va_pfn, pd_offset, entry;
	int pt_pfn, pt_offset, pfn, offset, address;

	printf("Virtual  Address: %p\n", (int*)va);
	pd_pfn = addr_to_fn(pd_addr);
	va_pfn = addr_to_fn(va);
	pd_offset = (va_pfn >> 10) & 0x3ff;
	entry = read_entry(pd_pfn, pd_offset);
	if((entry & PRESENT_BIT)){
		pt_pfn = (entry >> 12) & 0xfffff;
	}else{
		fprintf(stderr, "no Page Table\n");
		return(-1);
	}
	pt_offset = va_pfn & 0x3ff;
	entry = read_entry(pt_pfn, pt_offset);
	if((entry & PRESENT_BIT)){
		pfn = (entry >> 12) & 0xfffff;
	}else{
		fprintf(stderr, "no PFN\n");
		return(-1);
	}
	offset = va & 0xfff;
	address  = fn_to_addr(pfn) + offset;
	printf("Physical Address: %p\n\n", (int*)address);
}

int main()
{
	int  cr3;

	init_physical_frames(PHYS_SIZE);

	cr3 = create_pd();
	init_page_table(cr3);

	create_new_mappings(0x11111000, 0x11115000, cr3);
	create_new_mappings(0x45334000, 0x45340000, cr3);
	create_new_mappings(0x65533000, 0x65550000, cr3);

	virt_to_phys(0x80011155, cr3);
	virt_to_phys(0x20, cr3);
	virt_to_phys(0x11111111, cr3);
	virt_to_phys(0x65534333, cr3);

	return 0;
}
