#include <stdio.h>
#include <fcntl.h> 
#include <unistd.h> 

/* 
	C 2014, MIT license, "posixcat.c" csitd 
*/


void concatenate(int, int);

int main(int argc, char *argv[])
{ 
	int o, u;
        o = u = 0;

        while ((o = getopt (argc, argv, "u")) != -1)
                switch (o) {
                	case 'u': u = 1; break;
			case '?': break; 
                        default: break;
                }

        argv += optind;
        argc -= optind;

	if ( argc == 0 ) 
		concatenate(STDIN_FILENO, u); 

        while  (*argv) 
		concatenate(open(*argv++, O_RDONLY), u); 

	return 0; 
}

void concatenate(int source, int u) 
{
	int n = 0;
	char buf[BUFSIZ];
	if ( u != 1 )
		u = BUFSIZ; 
	
	while ((n = read(source, buf, u)) > 0) 
		write(STDOUT_FILENO, buf, n);
} 
