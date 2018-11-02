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
	
	fd = open (argv[1], O_WRONLY | O_CREAT , S_IRUSR | S_IWUSR | S_IRGRP );

	if (fd == -1) {
		fprintf(stderr, "Error opening the %s file\n", argv[1]);
		return -1;
	}


	printf("Insert the coordinates of point 0 (x y z): ");
	scanf("%d %d %d", &p0.x, &p0.y, &p0.z);

	printf("Writing p0 into file\n");
	if (write(fd, &p0, sizeof(point)) != sizeof(point)) {
		fprintf(stderr, "Error while writing p0 into file\n");
		return -3;
	}

	printf("Insert the coordinates of point 1 (x y z): ");
	scanf("%d %d %d", &p1.x, &p1.y, &p1.z);

	printf("Writing p1 into file\n");
	if (write(fd, &p1, sizeof(point)) != sizeof(point)) {
		fprintf(stderr, "Error while writing p1 into file\n");
		return -3;
	}
	
	close(fd);		
	return 0;
	
}
