/*************************************************************************
	> File Name: my_pwd.c
	> Author: Chenfan
	> Mail:994735640@qq.com 
	> Created Time: Thu 19 Jun 2014 06:18:41 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
int main(int argc, char *argv[] )
{
	printf("Current direction is : %s \n" ,  getcwd(NULL, 0 )) ;

	return 0 ;
}

