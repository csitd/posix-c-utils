#include <stdio.h> 
#include <mntent.h> 
#include <sys/vfs.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/* (Copyright) 2014, MIT license, "df.c", csitd */


void df_exit(char *, int);

int main(int argc, char *argv[])
{ 

	// needs to have mutiple pathname functionality 
	int o;
	int blocksz = 512;
	int opt[2] = { 0, 0 }; // -kP

	while ((o = getopt (argc, argv, "kPh")) != -1)
                switch (o) { 
                        case 'k': blocksz = 1024 ;
				  opt[1] = 1;
				  break;
			case 'P': opt[2] = 1;
				  break; 
			case 'h': break;
                        case '?': break;
			default: break;
                }


	unsigned long long size, avail, used;
	
	FILE* f = setmntent("/etc/mtab", "r"); 
	struct mntent *ent; 
	struct statfs fs; 


	printf("%-13s ", "Filesystem"); 
	if ( opt[1] == 1 )
        	printf("%-13s ", "1024-blocks"); 
	else
		printf("%-13s ", "512-blocks");
	printf("%-13s ", "Used");
        printf("%-s ", "Available"); 
	printf("%-s ", "Capacity ");
        printf("%-s ", "Mounted on");
	printf("\n");
     
	while ( ( ent = getmntent(f)) ) { 
		statfs(ent->mnt_dir, &fs); 
		size = fs.f_blocks * fs.f_bsize / blocksz; 
                avail = fs.f_bavail * fs.f_bsize / blocksz; 
		used = fs.f_blocks - fs.f_bfree;
		used *= (fs.f_bsize / blocksz); 
		printf("%-13s ", ent->mnt_fsname);
		if ( strlen(ent->mnt_fsname) > 13 ) 
			printf("\n%-13s ",""); 
		printf("%-13llu ", size);
                printf("%-13llu ", used);
                printf("%-13llu ", avail); 
		printf("%3.0f%%  ", (100*(float)used) / (size + 1) + .5 );
		printf("%-13s ", ent->mnt_dir);
		printf("\n"); 
 	} 
	endmntent(f); 
	return 0;
}

void df_exit(char *message, int i)
{
	fprintf (stderr, "%s", message);
	exit (i);
}

