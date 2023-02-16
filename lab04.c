#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

//compile step: "gcc -o lab04 lab04.c"
//execution step: "./lab04 file1.txt file2.txt"

#define	BUFFSIZE 4096

int main(int argc, char *argv[]) {
	int  readFileDescriptor, writeFileDescriptor;
	long int n;
	char buf[BUFFSIZE];
	
	if (argc != 3){
		printf("Usage: %s <source_filename> <destination_filename>\n", argv[0]);
		exit (-1);
	}

	if (*argv[1] == *argv[2]){
		printf("Error: Source file and destination file are the same\n");
		exit (-1);
	}

	readFileDescriptor = open(argv[2], O_RDONLY);
	writeFileDescriptor = open(argv[1], O_WRONLY, 0700);
	
	if (readFileDescriptor == -1 || writeFileDescriptor == -1){
		printf("Error with file open\n");
		exit (-1);
	}


    if (lseek(writeFileDescriptor, 0, SEEK_END) >=0);{
        write(writeFileDescriptor, "\n\n", 2);
        while ((n = read(readFileDescriptor, buf, BUFFSIZE)) > 0){
            if (write(writeFileDescriptor, buf, n) != n){
                printf("Error writing to output file\n");
                exit (-1);
		    }

	    }
    }
	if (n < 0){
		printf("Error reading input file\n");
		exit (-1);
	}

	close(readFileDescriptor);
	close(writeFileDescriptor);

	return 0;
	
}