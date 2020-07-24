#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

// 1_3
#include <string.h>
// 1_3

const int rchar_size = 94;

void usage(char *cmd)
{
	printf("usage: %s filename filesize[KB]\n", cmd);
	exit(-1);
}

void init_rand_char(char *array)
{
	char c;	int  i = 0;
	for (c = '!'; c <= '~'; c++) array[i++] = c;

	return ;
}

int main(int argc, char **argv)
{
	int  fd, size, i, k, len;
	char rchar[rchar_size];
	char name[256];

	if (argc != 3) usage(argv[0]);

	len = strlen(argv[1]);
	if(253 < len){
		fprintf(stderr, "file name is too long\n");
		exit(-1);
	}
	for(i = 0; i < len; i++){
		name[i] = argv[1][i];
	}

	for(k = 0; k < 100; k ++){
		if(k < 10){
			name[len] = '0' + k;
			name[len + 1] = '\0';
		}else{
			name[len] = '0' + (k / 10);
			name[len + 1] = '0' + (k % 10);
			name[len + 2] = '\0';
		}
		fd = open(name, O_RDONLY);
		if(fd > 0){
			fprintf(stderr, "%s already exists\n", name);
			continue;
		}
		close(fd);

		if ((fd = open(name, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR)) < 0) {
			perror("open");
			exit(-1);
		}

		size = atoi(argv[2]);
		init_rand_char(rchar);
		srand((unsigned int)time(NULL));

		for (i = 0; i < 1024 * size; i++) {
			write(fd, &rchar[rand()%(rchar_size+1)], 1);
			
		}

		close(fd);
	}

	return 0;
}
