/* moncat.c : imitation simplifiee de la commande cat */

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/stat.h>
#include <unistd.h>

#define LBUF 512
static char buf[LBUF];

int main(int N, char *P[])
{
	int fd, n;

	if (N != 2) {
		fprintf(stderr, "Utilisation : %s nom_du_fichier !\n", P[0]); return 1; 
	}

	if ((fd=open(P[1], O_RDONLY)) == -1) {
		perror(P[1]); return 2;	
	}
	
	while ((n = read(fd, (void*)buf, LBUF)) > 0) {
		write(1, (void*)buf, n);
	}
	close(fd);
	return 0;
}
