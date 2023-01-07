#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define	BUFFSIZE 4096
#define SEEKSIZE -10

int main(int argc, char *argv[]) {

	int  RWFileDescriptor;
	long int n;
	char buf[BUFFSIZE];
	const char lseekMSG[] = "THIS IS NEW MSG FROM LSEEK!\0";

	if (argc != 2){
		printf("Usage: %s <filename>\n", argv[0]);
		exit (-1);
	}
	
	RWFileDescriptor = open(argv[1], O_RDONLY);
	
	if (RWFileDescriptor == -1){
		printf("Error with file open\n");
		exit (-1);
	}

	if (lseek(RWFileDescriptor, SEEKSIZE, SEEK_END) >= 0){
		if((n = read(RWFileDescriptor, buf, BUFFSIZE)) > 0){
			if (write(STDOUT_FILENO, buf, n) != n) {
				printf("Error writing to file\n");
				exit (-1);
			}
		} else {
			printf("Error reading file\n");
			exit (-1);
		}
	} else {
		printf("lseek error (Part 1)\n");
		exit (-1);
	}
	close(RWFileDescriptor);


	RWFileDescriptor = open(argv[1], O_WRONLY);
	if (lseek(RWFileDescriptor, 0, SEEK_SET) >= 0){
		if (write(RWFileDescriptor, lseekMSG, strlen(lseekMSG)) != strlen(lseekMSG)) {
			printf("Error writing to file\n");
		}
	} else {
		printf("lseek error (Part 2)\n");
	}

	close(RWFileDescriptor);

	return 0;
}
