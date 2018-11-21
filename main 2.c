#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4
#define M 3

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

print_bingo(int BINGO[][N], int NAME) 
{
	int i, j;
	
	if (NAME == 1) // 알아보기 쉽게 이름을 정해주려고,,,, 
	{
		printf("<YOU>\n");
	}
	else
	{
		printf("<COM>\n");
	}
	
	// 실제 배열을 프린트 하는 코드  
	for( i=0 ; i<N ; i++)
	{
		for( j=0 ; j<N ; j++)
		{
			printf(" %3d ", BINGO[i][j]);
		}
		printf("\n");
	}
	printf("\n");
 } 
