#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4
#define M 2


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
initiate_bingo(int BINGO[][N])      //
{
	int x, y=1, i, j;
 	int k=0, w=15, T;
 	int G[N*N];
 	int p;
 	
 	for (x=0 ; x<N*N ; x++)
 	{
 		G[x]=y;
 		y++;
	}
	
	srand(time(NULL)); 
	for( i=0 ; i<N ; i++)
	{
	    for( j=0 ; j<N ; j++)
		{
			BINGO[i][j] = G[T=rand()%(N*N-k)];	
			p = G[w];
	        G[w] = G[T];
	        G[T] = p;
	        k++; 
	        w--;
	        
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
 	int num;         // 선택한 빙고 번 호  
 	int overlap = 1; // 중복 선택 방지  
 	
 	while ( overlap != 0)
 	{
 		printf("input number = ");
	    scanf("%i", &num);
	
 	    if ( num < 1 || num > N*N)         // 범위 내 숫자 선택  
	    {
		    printf(" 범위 외의 숫자 입니다 \n");
	    }
 	
        else 
        {
    	    for( i=0 ; i<N ; i++)          // 중복 선택 방지  
	        {
		        for( j=0 ; j<N ; j++)
		        {
			        if( B[i][j] == num )
			        {
		                overlap=0;
				    }
		        }
	        }  
	        
	        if (overlap==1)
	            printf(" 이미 선택된 숫자 입니다\n "); 
	    }         
	 }	
	return num;
}

get_number_byCom(int B[][N])
{
	int num;
	int i,j;
	int overlap = 1; // 중복 선택 방지  
 	
 	while ( overlap != 0)
 	{
 		num=rand()%N*N+1;
        
        for( i=0 ; i<N ; i++)          // 중복 선택 방지  
	    {
		    for( j=0 ; j<N ; j++)
		    {
			    if( B[i][j] == num )
			    {
		            overlap=0;
				}
		    }
	    }            
	 }	      
	printf(" c input = %i\n",num);
	
	return num;
} 

process_bingo(int BINGO[][N], int num) // num : 선택한 빙고 번호  
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

count_bingo(int B[][N])
{
	int i, j;
	int count3 = 0, count4 = 0; // 3 : 오른쪽 방향 대각선  4 : 왼쪽방향 대각선  
	int CR1=0, CR2=0, C1=0, C2=0; // 1:가로  2:세로  3:오른쪽 방향 대각선   4: 왼쪽 방향 대각선   
	int m;
	
	
	for( i=0 ; i<N ; i++) 
 	{
 	    int count1 =0, count2 = 0;
 	    
		if(B[i][i]==-1)               //오른쪽방향 대각선  
		{
			count3 ++;
		}
		
		if ( B[i][N-1-i]== -1 )       //왼쪽방향 대각선  
	    {
			count4 ++;
		}
 			
		for( j=0 ; j<N ; j++)
		{
			if ( B[i][j]== -1 )       //가로  
			{
			 	count1 ++;
			}
			if ( B[j][i]== -1 )      //세로  
	    	{
			 	count2 ++;
			}
			if ( count1 !=0 && count1%N == 0)
                CR1=count1/N;
            if ( count2 !=0 && count2%N == 0)
                CR2=count2/N;
		}
        if ( count3 !=0 && count3%N == 0)
            C1=1;
        if ( count4 !=0 && count4%N == 0)
            C2=1;
	}
	printf(" 가로  %i\n", CR1);
	printf(" 세로  %i\n", CR2);
	printf(" 대  %i\n", C1);
	printf(" 대2  %i\n",C2 );
	m=CR1+CR2+C1+C2;
	
	return m;
}


int main(int argc, char *argv[]) 
{
	int bingo_game[N][N];    // 내꺼 
	int C_bingo_game[N][N];  // 컴퓨터  
	int bingo, Cbingo;               // 나의 빙고 수, 컴퓨터 빙고 수  
	int NUM;                 // 선택한 빙고 번호  
	int turn=0;              
	
	initiate_bingo(bingo_game) ;
	int i, j, k=1;
	
	for( i=0 ; i<N ; i++)
	{
		for( j=0 ; j<N ; j++)
		{
			C_bingo_game[i][j] = k;
			k++;
		}
	}
	
	
	print_bingo(bingo_game);
	print_bingo(C_bingo_game);
	
	while ( bingo < M && Cbingo < M)
    {
	   
	    NUM = get_number_byMe(bingo_game);
	    process_bingo(bingo_game, NUM);
	    process_bingo(C_bingo_game, NUM);
	    
	    print_bingo(bingo_game);
	    print_bingo(C_bingo_game);
	    
	    bingo = count_bingo(bingo_game);
	    Cbingo = count_bingo(C_bingo_game);
	    printf("bingo %i\n", bingo);
	    printf("Cbingo %i\n", Cbingo);
	    turn++;	    
	    
	    if(bingo < M && Cbingo < M) 
		{
			NUM = get_number_byCom(C_bingo_game);
	        process_bingo(bingo_game, NUM);
	        process_bingo(C_bingo_game, NUM);
	    
	        print_bingo(bingo_game);
	        print_bingo(C_bingo_game);
	    
	        bingo = count_bingo(bingo_game);
	        Cbingo = count_bingo(C_bingo_game);
	        printf("bingo %i\n", bingo);
	        printf("Cbingo %i\n", Cbingo);
	        turn++;	
	
		}    
    }
	
	printf("  WIN!!!!, %iturn",turn );
	
	return 0;
}









