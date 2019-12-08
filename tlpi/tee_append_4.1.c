
#include <unistd.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

#ifndef BUF_SIZE 
#define BUF_SIZE 1024

int main (int argc, char *argv[]) {
	
  bool append=false;
  int opt;

  while ((opt = getopt(argc, argv, "a")) != -1) {
    if ((unsigned char) opt == 'a') {
	    append = true; 
    }
  }

  if (optind >= argc) {
    usageErr("%s [-a] file\n", argv[0]);
  }

  int fd; 
  fd= open(argv[optind],O_CREAT | O_WRONLY |(append?O_APPEND:O_TRUNC),0666);
  if (fd == -1) 
	  errExit("opening file %s", argv[optind]);

  ssize_t numRead;
  char buf[BUF_SIZE];

  while ((numRead = read(STDIN_FILENO, buf, BUF_SIZE)) > 0) {
    if (write(fd, buf, numRead) != numRead) {
      errExit("couldn't write whole buffer!");
    }
    if (write(STDOUT_FILENO, buf, numRead) != numRead) {
      errExit("couldn't write whole buffer!");
    }
  }
  if (numRead == -1) {
    errExit("read");
  }
  if (close(fd) == -1) {
    errExit("close input");
  }

  exit(EXIT_SUCCESS);
}


#endif /* BUF_SIZE */
