/*************************************************************************
	> File Name: my_mkdir.c
	> Author: Chenfan
	> Mail:994735640@qq.com 
	> Created Time: Thu 19 Jun 2014 06:38:26 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
int main (int argc, char *argv[]) 
{
	int iret ;
	if( argc == 1 )
	{
		printf("too few arg ! \n") ;
		exit( 0 ) ;
	}
	else
	{
		iret = mkdir (argv[1], 0777 ) ;
	}
}
