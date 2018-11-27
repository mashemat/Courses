#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

typedef struct {
	int x;
	int y;
	int z;
} point;

int main(int argc, char **argv) {
	int fd;
	point p0, p1;

	if (argc != 2) {
		fprintf(stderr, "Not enough parameters have been provided to the program\n");
		return -1;
	}
	
	fd = open (argv[1], O_RDONLY);

	if (fd == -1) {
                fprintf(stderr, "Error while opening file\n");
		return -1;
	}

	printf("Reading p0 from file\n");
	if (read(fd, &p0, sizeof(point)) !=sizeof(point)){
                fprintf(stderr, "Error while writing p0 into file\n");
                return -3;
}


	printf("Reading p1 from file\n");
	if (read(fd, &p1, sizeof(point)) !=sizeof(point)){
                fprintf(stderr, "Error while writing p1 into file\n");
                return -3;
	}
	
	printf("Read %d:%d:%d, %d:%d:%d\n", p0.x,p0.y,p0.z,p1.x,p1.y,p1.z);
	close(fd);		
	return 0;
	
}
