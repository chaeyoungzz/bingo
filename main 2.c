#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4
#define M 3

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

count_bingo(int B[][N])
{
	int i, j;
	int count3 = 0, count4 = 0; // 3 : 오른쪽 방향 대각선  4 : 왼쪽방향 대각선  
	int CR1=0, CR2=0, C1=0, C2=0; // 1:가로  2:세로  3:오른쪽 방향 대각선   4: 왼쪽 방향 대각선   
	int m;
	
	
	for( i=0 ; i<N ; i++) 
 	{
 	    int count1 =0, count2 = 0;
 	    
		if(B[i][i]==-1)               //오른쪽방향 대각선  (0,0) (1,1) ---
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
                CR1=count1/N;                // B[i][j]== -1 이면 count 에 더해서
				                            // N 으로 나눠 그 줄 전체가 -1인지 확인  (나머지도 동일) 
            if ( count2 !=0 && count2%N == 0)
                CR2=count2/N;
		}
        if ( count3 !=0 && count3%N == 0)
            C1=1;
        if ( count4 !=0 && count4%N == 0)
            C2=1;
	}
		
	m=CR1+CR2+C1+C2;
	
	return m;
}

