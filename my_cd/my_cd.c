/*************************************************************************
	> File Name: cd.c
	> Author: Chenfan
	> Mail:994735640@qq.com 
	> Created Time: Thu 19 Jun 2014 06:24:47 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char *argv[ ]) 
{
	int iret ;
	if( argc == 1 )
	{
		printf("to few element \n") ;
		//iret = chdir() ;
	}
	else
	{
		iret = chdir(argv[1]) ;
	}
	if( iret != 0)
	{
		perror( " change chdir failed \n") ;
	}

	return 0 ;
}
