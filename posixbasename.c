#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 
	(Copyright) 2014, MIT license, "posixbasename.c", csitd
*/


int main(int argc, char *argv[])
{ 

	if ( argc < 2 ) 
		return 1;
	size_t len = strlen(argv[1]); 
	size_t lena;
	char end[1024][1024];
	char buffer[1024];
	size_t i, c, d, e;
	i = c = d = e = 0; 
	memset(end[0], 0, 1024); 
		
	if (argv[1][len - 1] == '/' )
	{
		argv[1][len - 1] = '\0';
		len = strlen(argv[1]); 
	}

	if ( argc == 3 ) 
	{
		lena = strlen(argv[2]); 
		while ( i < lena )
		{
			buffer[i] = argv[1][len - lena + i];
			buffer[++i] = '\0'; 
		} 
		if ( strcmp(argv[2], buffer ) == 0 ) 
			len -= lena + 1; 
	} 
	
	
	while ( c <= len )
	{ 
		if ( argv[1][c] != '/' )
		{
			end[d][e + 1] = '\0';
			end[d][e++] = argv[1][c++]; 
		}
		else
		{
			++c;
			++d;
			e = 0; 
		} 
	}
	if ( strlen ( end[d] ) == 0 ) 
	{
		if ( strlen ( end[0] ) != 0 )
			printf("%s\n", end[0]);
		else 	
			printf("/\n");
	}
	else 
	{
		printf("%s\n", end[d]);
	}
	
	return(0);
}

