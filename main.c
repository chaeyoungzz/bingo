#include <stdio.h>
#include <stdlib.h>
#define N 2

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
initiate_bingo(int B[][N], int CB[][N]) 
{
	int i, j, k=1;
	
	for( i=0 ; i<N ; i++)
	{
		for( j=0 ; j<N ; j++)
		{
			
		    B[i][j] = k;    // 랜덤 배열 설정  
			CB[i][j] = k;
			k++;
		}
	}
}

print_bingo(int BINGO[][N])
{
	int i, j;
	
	for( i=0 ; i<N ; i++)
	{
		for( j=0 ; j<N ; j++)
		{
			printf("%i ", BINGO[i][j]);
		}
		printf("\n");
	}
	printf("\n");
 } 
 
get_number_byMe(int k, int B[][N])
{
 	int i, j ;
 		 
	if(k==-1)
	{
	 	printf("이미 선택한 숫자 입니다 ");
	}
	 
	else if (k>N*N+1)
	{
		printf(" 선택 범위를 넘어선 숫자 입니다 ");
	}
}

get_number_byCom(int B[][N])
{
	int i, j ;
	int k;
	
	srand(time(NULL));
	k = rand() %N*N + 1 ;
	 
	if(k==-1)
	{
	 	printf("이미 선택한 숫자 입니다 ");
	}
	 
	else if (k>N*N+1)
	{
		printf(" 선택 범위를 넘어선 숫자 입니다 ");
	}
} 

process_bingo(int B[][N], int k)
{
	int i, j ;
	
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

int main(int argc, char *argv[]) 
{
	int bingo_game[N][N];
	int C_bingo_game[N][N];
	int num;
	
	initiate_bingo( bingo_game, C_bingo_game ) ;
	
	print_bingo(bingo_game);
	print_bingo(C_bingo_game);
	
	printf("input number = ");
	scanf("%i", &num);
	
	get_number_byMe(num, bingo_game);
	get_number_byCom(C_bingo_game);
	
	process_bingo(bingo_game,num);
	process_bingo(C_bingo_game, num);
	
	print_bingo(bingo_game);
	print_bingo(C_bingo_game);
	
	
	return 0;
}
