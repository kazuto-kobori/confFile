/*
 *  Copyright (c) 2017 Hiroshi Yamada <hiroshiy@cc.tuat.ac.jp>
 *
 *  a simple shell
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFSIZE 1024
#define ARGVSIZE 100

const char whitespace[] = " \t\r\n\v";

int parsecmd(char** argv, char* buf, int len, int* idx) {
  char* s;
  int i = 0;
  int c = 0;

  s = &buf[*idx];
  if (len <= *idx) {
    return -1;
  }

  while (*idx < len) {
    while (*idx < len && strchr(whitespace, *s)) {
      s++;
	  (*idx)++;
    }
    if (len <= *idx) {
      return -1;
    }

    if (*s == '>') {
      while (*idx < len && !strchr(whitespace, *s)) {
        s++;
	    (*idx)++;
      }
      *s = '\0';
      s++;
	  (*idx)++;
      return 2;
    }

    argv[i++] = s;
    while (*idx < len && !strchr(whitespace, *s)) {
      s++;
	  (*idx)++;
    }
    *s = '\0';
    s++;
	  (*idx)++;
  }

  return 1;
}

void runcmd(char* buf) {
  char* argv[ARGVSIZE];
  char* name[ARGVSIZE];
  int rtn, filedes[2], pid, fd;
  int idx = 0;
  int len = strlen(buf);

  memset(argv, 0, ARGVSIZE);
  rtn = parsecmd(argv, buf, len, &idx);
  if (rtn == 1) {
    if (execvp(argv[0], argv) < 0)
      perror("execvp");
  } else if (rtn == 2) {
    parsecmd(name, buf, len, &idx);
    if ((fd = open(name[0], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR)) < 0) {
      perror("open");
    }
    close(1);
    dup(fd);
    close(fd);
    if (execvp(argv[0], argv) < 0)
      perror("execvp");
  }
  exit(-1);
}

int getcmd(char* buf, int len) {
  printf("> ");
  fflush(stdin);
  memset(buf, 0, len);
  fgets(buf, len, stdin);

  if (buf[0] == 0)
    return -1;
  return 0;
}

int main(int argc, char** argv) {
  static char buf[BUFSIZE];

  while (getcmd(buf, BUFSIZE) >= 0) {
    if (fork() == 0)
      runcmd(buf);
    wait(NULL);
  }

  exit(0);
}
