/*
 *  Copyright (c) 2017 Hiroshi Yamada <hiroshiy@cc.tuat.ac.jp>
 *
 *  a simple shell
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/wait.h>

#define BUFSIZE  1024
#define ARGVSIZE 100

const char whitespace[] = " \t\r\n\v";

//int parsecmd(char **argv, char *buf, char *ebuf)
//{
//	int  i = 0;
//	
//	if(ebuf <= buf){
//		return -1;
//	}
//	printf("a: %p\n", buf);
//
//	while (buf < ebuf) {
//		while (buf < ebuf && strchr(whitespace, *buf)) buf++;
//		if (ebuf <= buf) return -1;
//
//		if(*buf == '>'){
//			while (buf < ebuf && !strchr(whitespace, *buf)) buf++;
//			*buf = '\0'; 
//			buf++;
//			return 2;
//		}
//		argv[i++] = buf;
//		while (buf < ebuf && !strchr(whitespace, *buf)) buf++;
//		*buf = '\0'; 
//		buf++;
//	}
//
//	return 1;
//}

int parsecmd(char **argv, char *buf, char *ebuf, int *idx)
{
        char *s;
        int  i = 0;
		int c = 0;

        s = &buf[*idx];
		//s = buf;
		//printf("&buf[*idx]: %p\n", &buf[*idx]);
		//printf("s: %p\n", s);
		if(ebuf <= s){
			return -1;
		}

        while (s < ebuf) {
                while (s < ebuf && strchr(whitespace, *s)){
				s++;
				c++;
				}
                if (ebuf <= s){
				return -1;
				}

				if(*s == '>'){
					while (s < ebuf && !strchr(whitespace, *s)){
					s++;
					c++;
					}
					*s = '\0'; 
					s++;
					c++;
					(*idx) = c;
					//printf("idx: %d\n", *idx);
					return 2;
				}
                argv[i++] = s;
                while (s < ebuf && !strchr(whitespace, *s)){
				s++;
				c++;
				}
                *s = '\0';
                s++;
		c++;
        }

        return 1;
}

void runcmd(char *buf)
{
	char *argv[ARGVSIZE];
	char *name[ARGVSIZE];
	int rtn, filedes[2], pid, fd;
	int idx = 0;
	
	memset(argv, 0, ARGVSIZE);
	//printf("add: %d\n", idx);
	rtn = parsecmd(argv, buf, &buf[strlen(buf)], &idx);
	//printf("add: %d\n", idx);
	if (rtn == 1){
		if (execvp(argv[0], argv) < 0)
			perror("execvp");		
	}else if(rtn == 2){
		rtn = parsecmd(name, buf, &buf[strlen(buf)], &idx);
		printf("filename: %s\n", name[0]);
		if((fd = open("ho", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR)) < 0){
			perror("open");
		}
		close(1);
		dup(fd);
		close(fd);
		//pid = fork();
		//if(pid == 0){
			if (execvp(argv[0], argv) < 0)
				perror("execvp");		
		//	exit(-1);
		//}else if(pid > 0){
		//}else{
		//	perror("fork");
		//}
		//wait(NULL);
	}
	exit(-1);
}

int getcmd(char *buf, int len)
{
	printf("> ");
	fflush(stdin);
	memset(buf, 0, len);
	fgets(buf, len, stdin);

	if (buf[0] == 0)
		return -1;
	return 0;
}

int main(int argc, char**argv)
{
	static char buf[BUFSIZE];

	while(getcmd(buf, BUFSIZE) >= 0) {
		if (fork() == 0)
			runcmd(buf);
		wait(NULL);
	}

	exit(0);
}
