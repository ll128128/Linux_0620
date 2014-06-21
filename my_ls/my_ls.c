/*************************************************************************
	> File Name: my_ls.c
	> Author: Chenfan
	> Mail:994735640@qq.com 
	> Created Time: Thu 19 Jun 2014 08:21:22 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
int main( int argc, char *argv[])
{
	DIR *pDIR ;
	struct dirent *myent ;
	if ( argc == 1 )
	{
		pDIR = opendir (".") ;
	}
	else
	{
		pDIR = opendir ( argv[1] ) ;
	}
	if( pDIR == NULL )
	{
		perror("Open falied\n ") ;
		exit( -1 ) ;
	}
	 
	//read director 
	while( ( myent = readdir ( pDIR )) != NULL ) 
	{
		if(strcmp( myent -> d_name,"." )!=0 && strcmp(myent -> d_name,"..") != 0 )
		{
			printf("%s\t", myent -> d_name ) ;
		}
		//printf("size : %d\ttype : %c\tName : %s\n",myent -> d_reclen, myent -> d_type, myent -> d_name ) ;
	}
	printf("\n") ;

	return 0 ;
}

