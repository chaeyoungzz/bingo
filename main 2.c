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
 	int G[N*N]; // 1~N*N ���� �ҷ����� ���� �迭  
 	int p;
 	
 	// 1~N*N ���� �ҷ���  
 	for (x=0 ; x<N*N ; x++)
 	{
 		G[x]=y;
 		y++;
	}
	 
	for( i=0 ; i<N ; i++)
	{
	    for( j=0 ; j<N ; j++)
		{
			BINGO[i][j] = G[T=rand()%(N*N-k)];	//�ҷ��� ���ڸ� BINGO �迭�� ���� �Ҵ�  
			
			// ���õ� �迭�� �� ���� �迭�� ���� �ٲ���
			// ex) G[2]�� ���õǾ��ٰ� �ϸ� G[N*N-1] �� ���� �ٲ��� �� ������ G[N*N-2] �� ���� �ٲ�  
			p = G[w];
	        G[w] = G[T];
	        G[T] = p;
	        k++;  // rand �� ������ �ٲ��� �̹� ���õ� ���� ���� ���� ���ϰ� ����  
	        w--;  // �迭 �� �� ���� ���������� �Ҵ��ϱ� ����  G[N*N-1] , G[N*N-2], G[N*N-3] ----   
		}
	}
	
}

