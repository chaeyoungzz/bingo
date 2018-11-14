#include <stdio.h>
#include <stdlib.h>
#define N 4
#define M 3

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
			printf(" %i ", BINGO[i][j]);
		}
		printf("\n");
	}
	printf("\n");
 } 
 
get_number_byMe( int B[][N])
{
 	int i, j ;
 	int NUM;
 	
 	printf("input number = ");
	scanf("%i", &NUM);
	
 	if ( NUM < 1 || NUM > N*N)
	{
		printf(" 범위 외의 숫자 입니다 \n");
	}
 	
    else
    {
    	for( i=0 ; i<N ; i++)
	    {
		    for( j=0 ; j<N ; j++)
		    {
			    if( NUM==B[i][j] )
			    {
			    	printf(" 나의 빙고 \n");
			    	process_bingo( B, NUM);
		            print_bingo( B );
		            break;
				}
				else
				{
					printf("  1 이미 선택한 숫자 입니다.\n");
					break; 
				}
		    }
	    }  
	}    
	
 
}

get_number_byCom(int CB[][N])
{
	int i, j ;
	int k;
	
	srand(time(NULL));
	k = rand() %N*N + 1 ;
	 
	if ( k < 1 || k > N*N)
	{
		printf(" 범위 외의 숫자 입니다 \n");
	}
 	
    else
    {
    	for( i=0 ; i<N ; i++)
	    {
		    for( j=0 ; j<N ; j++)
		    {
			    if( k==CB[i][j] )
			    {
			    	printf(" C 빙고 \n");
					process_bingo( CB, k);
		            print_bingo( CB );
				}
				else
				{
					printf(" 이미 선택한 숫자 입니다.\n");
					break; 
				}
		    }
	    }  
	}    
	
} 

process_bingo(int BINGO[][N], int num)
{
	int i, j ;
	
	for( i=0 ; i<N ; i++)
 		{
 			for( j=0 ; j<N ; j++)
			{
			 	if ( BINGO[i][j]== num )
			 	{
			 		BINGO[i][j]=-1;
				}
			}
		}
} 

count_bingo(int k)
{
	
}

int main(int argc, char *argv[]) 
{
	int bingo_game[N][N];
	int C_bingo_game[N][N];
	
	initiate_bingo( bingo_game, C_bingo_game ) ;
	
	print_bingo(bingo_game);
	print_bingo(C_bingo_game);
	
		
	get_number_byMe(bingo_game);
	get_number_byCom(C_bingo_game);



	get_number_byMe(bingo_game);
	get_number_byCom(C_bingo_game);
	
	
	
	return 0;
}










