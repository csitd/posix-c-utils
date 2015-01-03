#include <stdio.h>
#include <string.h>

/* 
	(Copyright) 2014, MIT license, "posixbasename.c", Dean Michaelson 
*/


int main(int argc, char *argv[])
{ 

	const char ch = '/';
	char *ret;
	char *parts[1024];
	int c = 0;
	
	

	ret = strchr(argv[1], ch);
	

	//printf("%s\n", ret);
	while (ret  != NULL) 
	{
		//printf ("found at %d\n",ret-str+1);
		//memset(parts[c], 0, 1024);
		//strcpy(parts[c], 
		printf("%*.s\n", , ret + 1);
		ret=strchr(ret + 1, ch);
		
	} 
	
	return(0);
}
