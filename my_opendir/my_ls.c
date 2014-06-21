/*************************************************************************
	> File Name: my_ls.c
	> Author: Chenfan
	> Mail:994735640@qq.com 
	> Created Time: Thu 19 Jun 2014 11:56:08 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>
#include<sys/stat.h>
#include<pwd.h>
int main (int argc, char *argv []) 
{
	void mode_to_str( mode_t md, char *str)

	DIR  *pDIR ;
	struct stat mystat ;
	struct dirent *myent ;
	struct mode st_mode ;
	int col = 0 ;

	if( argc == 1 )
	{
		pDIR = opendir ( "." ) ;
	}
	else
	{
		pDIR = opendir(argv[1]) ;
	}
	
	if( pDIR == NULL )
	{
		perror ("File failed !\n") ;
		exit(-1) ;
	}

	while((myent = readdir (pDIR))!= NULL )
	{
		memset( &mystat,1, sizeof(mystat)) ;
		stat (myent -> d_name, &mystat) ;

		memset(str_mode, 0, 11) ;
		mode_to_str(mystat, st_mode, str_mode) ;

		if ( strncmp(myent -> d_name, ".", 1)!= 0&& strncmp(myent ->d_name, ".",2) != 0 )
		{
			printf("%10s,%2d,%d,%d,%5d,%ld,%s\n",str_mode,mystat.st_ino, mystat.st_mode, mystat.st_uid, mystat.st_gid, mystat.st_size, mystat.st_atime, myent -> d_name ) ;
			col ++ ;
			//printf("%2d,%x,%d,%d,%d,%ld,%-10s\n",mystat.st_ino, mystat.st_mode, mystat.st_uid, mystat.st_gid, mystat.st_size, mystat.st_atime, myent -> d_name ) ;
			if(col % 5 == 0)
			{
				printf("\n") ;
			}
		}
	}
	return 0 ;
}

void mode_to_str( mode_t md, char *str)
{
	strcpy(str, "-------------------------------") ;
	if(S_ISDIR(md))
	{
		str [0] = 'd' ;
	}
	if(md & S_IRUSR)
	{
		str[1] = 'r' ;
	}
	if(md & S_IWUSR)
	{
		str[2] = 'w' ;
	}
	if(md & S_IXUSR)
	{
		str[3] = 'x' ;
	}


	if(md & S_IRGRP)
	{
		str[4] = 'r' ;
	}
	if(md & S_IWGRP)
	{
		str[5] = 'w' ;
	}
	if(md & S_IXGRP)
	{
		str[6] = 'x' ;
	}
	

	if(md & S_IROTH)
	{
		str[7] = 'r' ;
	}
	if(md & S_IWOTH)
	{
		str[8] = 'w' ;
	}
	if(md & S_IXOTH)
	{
		str[9] = 'x' ;
	}
}

