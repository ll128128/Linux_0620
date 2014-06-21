/*************************************************************************
	> File Name: my_ll.c
	> Author: Chenfan
	> Mail:994735640@qq.com 
	> Created Time: Fri 20 Jun 2014 06:51:28 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<pwd.h>
#include<time.h>
#include<unistd.h>
#include<dirent.h>
#include<grp.h>

void mode_to_str( mode_t md, char *str) ;
void format (char *p) ;
int main(int argc, char *argv[]) 
{
	struct stat mystat ;
	struct dirent *myent ;
	DIR *pDIR ;
	char *ptm ;
	char str_mode[11]="" ;
	int col = 0;
	if(argc == 1)
	{
		pDIR = opendir(".") ;
	}
	else
	{
		pDIR = opendir(argv[1]) ;
	}
	if(pDIR == NULL)
	{
		perror("Open failed ! \n") ;
		//exit(-1) ;
	}
	while((myent = readdir(pDIR)) != NULL )
	{
		memset (&mystat, 0, sizeof(mystat)) ;
		stat (myent -> d_name, &mystat) ;
		memset (str_mode, 0, 11) ;
		mode_to_str(mystat.st_mode, str_mode ) ;
		ptm = ctime (&mystat.st_atime) ;
	//	format(ptm) ;
		 if((strcmp(myent -> d_name, ".") != 0) &&(strcmp(myent -> d_name, "..")!=0) )
			{
				printf("%10s.%2d %-5s %-5s %5d %s %s\n",str_mode, mystat.st_nlink, getpwuid(mystat.st_uid) -> pw_name,getgrgid(mystat.st_gid) -> gr_name, mystat.st_size, ptm, myent -> d_name ) ;
			}
	}
	printf("\n") ;
	return 0;
}

void mode_to_str( mode_t md, char *str)
{
	strcpy(str,"---------") ;
	if(S_ISDIR(md))
	{
		str[0] = 'd' ;
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

void format(char *p)
{
	while(*p)
	{
		p++ ;
	}
	while(*p != ':') 
	{
		p-- ;
	}
	*p = '\0' ;
}
