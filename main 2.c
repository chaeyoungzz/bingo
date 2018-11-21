#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4
#define M 3

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

initiate_bingo(int BINGO[][N])  
{
	int x, y=1, i, j;
 	int k=0, w=N*N-1, T;
 	int G[N*N]; // 1~N*N 숫자 불러오기 위한 배열  
 	int p;
 	
 	// 1~N*N 숫자 불러옴  
 	for (x=0 ; x<N*N ; x++)
 	{
 		G[x]=y;
 		y++;
	}
	 
	for( i=0 ; i<N ; i++)
	{
	    for( j=0 ; j<N ; j++)
		{
			BINGO[i][j] = G[T=rand()%(N*N-k)];	//불러온 숫자를 BINGO 배열에 각각 할당  
			
			// 선택된 배열을 맨 뒤의 배열과 값을 바꿔줌
			// ex) G[2]가 선택되었다고 하면 G[N*N-1] 의 값과 바꿔줌 그 다음은 G[N*N-2] 와 값을 바꿈  
			p = G[w];
	        G[w] = G[T];
	        G[T] = p;
	        k++;  // rand 의 범위를 바꿔줌 이미 선택된 숫자 선택 하지 못하게 해줌  
	        w--;  // 배열 맨 뒤 부터 순차적으로 할당하기 위해  G[N*N-1] , G[N*N-2], G[N*N-3] ----   
		}
	}
	
}

