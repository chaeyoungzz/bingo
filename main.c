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
 	int overlap = 1;
 	
 	while ( overlap != 0)
 	{
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
			        if( B[i][j] == NUM )
			        {
			    	    printf(" 나의 빙고 \n");
			    	    process_bingo( B, NUM);
		                print_bingo( B );
		                overlap=0;
				    }
		        }
		    
	        }  
	        
	        if (overlap==1)
	            printf(" 이미 선택된 숫자 입니다\n "); 
	    }         
	 }	
 
}

get_number_byCom(int B[][N])
{
	int i, j ;
	int NUM;
	
	srand(time(NULL));
	NUM = rand() %N*N + 1 ; //겹치지 않는 난수 생성 방법 
	
	printf(" C 빙고 \n");
	process_bingo( B, NUM);
	print_bingo( B );
	
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










