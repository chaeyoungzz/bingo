#include <stdio.h>
#include <stdlib.h>
#define N 5

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
initiate_bingo(int k[][N]) 
{
	int i, j;
	
	for( i=0 ; i<N ; i++)
	{
		for( j=0 ; j<N ; j++)
		{
			// 빙고 랜덤 배열 설정  
		}
	}
}

print_bingo(int k[][N])
{
	int i, j;
	
	for( i=0 ; i<N ; i++)
	{
		for( j=0 ; j<N ; j++)
		{
			printf("%i", k[i][j]);
		}
		printf("\n");
	}
 } 
 
get_number_byMe(int k, int B[][N])
{
 	int i, j ;
 	
 	printf(" 숫자를 입력하세요 ");
 	scanf("%i", &k);
 	
	 
	if(k==-1)
	{
	 	printf("이미 선택한 숫자 입니다 ");
	}
	 
	else if (k>N*N+1)
	{
		printf(" 선택 범위를 넘어선 숫자 입니다 ");
	}
	
 	else
 	{
 		for( i=0 ; i<N ; i++)
 		{
 			for( j=0 ; j<N ; j++)
			{
			 	if ( B[i][j]==k )
			 	{
			 		B[i][j]=-1;
				}
			}
		 }
	 }
}

get_number_byCom(int k, int B[][N])
{
	int i, j ;
	
	k = rand() %N*N + 1 ;
	 
	if(k==-1)
	{
	 	printf("이미 선택한 숫자 입니다 ");
	}
	 
	else if (k>N*N+1)
	{
		printf(" 선택 범위를 넘어선 숫자 입니다 ");
	}
	
 	else
 	{
 		for( i=0 ; i<N ; i++)
 		{
 			for( j=0 ; j<N ; j++)
			{
			 	if ( B[i][j]==k )
			 	{
			 		B[i][j]=-1;
				}
			}
		 }
	 }
} 

int main(int argc, char *argv[]) {
	int bingo_game[N][N];
	return 0;
}
