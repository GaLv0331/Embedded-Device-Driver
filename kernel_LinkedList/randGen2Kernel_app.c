#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <errno.h>

#define NUMBER_COUNT	1000
#define DEV		"/dev/rohitDev"

int main()
{
	int fd = open(DEV, O_RDWR);
	if(fd<0){
		perror("Cannot open device file");
		exit(EXIT_FAILURE);
	}
	
	for(int i=0; i<NUMBER_COUNT; i++){
		int randNum = rand();
		int ret = write(fd, (void *)&randNum, sizeof(randNum));
		if(ret != sizeof(randNum)){
			perror("write to dev failed");
			exit(EXIT_FAILURE);
		}
		
	}
	printf("%d Random Number Sent Successfuly", NUMBER_COUNT);

	close(fd);

	return (EXIT_SUCCESS);
}


