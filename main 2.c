#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4
#define M 3

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

print_bingo(int BINGO[][N], int NAME) 
{
	int i, j;
	
	if (NAME == 1) // �˾ƺ��� ���� �̸��� �����ַ���,,,, 
	{
		printf("<YOU>\n");
	}
	else
	{
		printf("<COM>\n");
	}
	
	// ���� �迭�� ����Ʈ �ϴ� �ڵ�  
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
