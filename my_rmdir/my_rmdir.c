/*************************************************************************
	> File Name: my_rmdir.c
	> Author: Chenfan
	> Mail:994735640@qq.com 
	> Created Time: Thu 19 Jun 2014 07:13:23 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
int main(int argc, char *argv[] ) 
{
	int iret ;
	if ( argc == 1 )
	{
		printf("too few arg ! \n") ;
		exit(0) ;
	}
	else
	{
		iret = rmdir (argv[1]) ;
		if(iret != 0)
		{
			printf("Director is not empty : ") ;
		}
	}

}
