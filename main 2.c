#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4
#define M 3

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

count_bingo(int B[][N])
{
	int i, j;
	int count3 = 0, count4 = 0; // 3 : ������ ���� �밢��  4 : ���ʹ��� �밢��  
	int CR1=0, CR2=0, C1=0, C2=0; // 1:����  2:����  3:������ ���� �밢��   4: ���� ���� �밢��   
	int m;
	
	
	for( i=0 ; i<N ; i++) 
 	{
 	    int count1 =0, count2 = 0;
 	    
		if(B[i][i]==-1)               //�����ʹ��� �밢��  (0,0) (1,1) ---
		{
			count3 ++;  
		}
		
		if ( B[i][N-1-i]== -1 )       //���ʹ��� �밢��  
	    {
			count4 ++;
		}
 			
		for( j=0 ; j<N ; j++)
		{
			if ( B[i][j]== -1 )       //����  
			{
			 	count1 ++;      
			}
			if ( B[j][i]== -1 )      //����  
	    	{
			 	count2 ++;
			}
			if ( count1 !=0 && count1%N == 0)
                CR1=count1/N;                // B[i][j]== -1 �̸� count �� ���ؼ�
				                            // N ���� ���� �� �� ��ü�� -1���� Ȯ��  (�������� ����) 
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

