#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>

#include <linux/usbdevice_fs.h>

int main(int argc, char **argv) {
	const char *filename;
	int fd;
	int rc;

	if (argc != 2) {
		fprintf(stderr, "usage: nusbreset [device file]\n");
		fprintf(stderr, "example: ./nusbreset /dev/bus/usb/001/003\n");
		return 1;
	}
	filename = argv[1];

	fd = open(filename, O_WRONLY);
	if (fd < 0) {
		perror("nusbreset error: can't open device file, exiting.");
		return 1;
	}

	printf("nusbreset: resetting USB device %s\n", filename);
	rc = ioctl(fd, USBDEVFS_RESET, 0);
	if (rc < 0) {
		close(fd);
		perror("nusbreset error: ioctl failure, exiting.");
		return 1;
	}
	close(fd);
	printf("nusbreset: success\n");

	return 0;
}

