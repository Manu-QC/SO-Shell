/*
Copyright (C) 2016-2019 The University of Notre Dame
This software is distributed under the GNU General Public License.
See the file LICENSE for details.
*/

#include "library/syscalls.h"
#include "library/string.h"
#include "library/errno.h"

int main(int argc, char *argv[])
{

	int fd = syscall_open_file(KNO_STDDIR,argv[1],0,0);
	printf("got fd %d\n", fd);
	printf("writing to stdout...\n");

	char buffer[4096];
	for(int i = 0; i < 12; i++) {
		int n;
		n = syscall_object_write(fd, buffer, 128, 0);
		if(n < 0)
			break;
		printf("%s", buffer);
	}
	syscall_object_close(fd);
	syscall_process_exit(0);

	return 0;

}
