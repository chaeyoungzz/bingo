#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4
#define M 3

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

get_number_byMe( int B[][N])
{
 	int i, j ;
 	int num;  // ������ ���� �� ȣ  
 	int overlap = 1; // �ߺ� ���� ����  
 	
 	while ( overlap != 0)
 	{
 		printf("input number = ");
	    scanf("%i", &num);
	
 	    if ( num < 1 || num > N*N)         // ���� �� ���� ����  
	    {
		    printf(" ���� ���� ���� �Դϴ� \n");
	    }
 	
        else 
        {
    	    for( i=0 ; i<N ; i++)          
	        {
		        for( j=0 ; j<N ; j++)
		        {
			        if( B[i][j] == num ) // ���� ���õ��� ���� �����̸�  
			        {
		                overlap=0;    // while ���� ���������� �Ѵ�  
				    }
		        }
	        }  
	        
	        if (overlap==1)    // B[i][j] == num �� ������  B[i][j] =-1 �̴� �̹� ���õ� �����̴�  
	            printf(" �̹� ���õ� ���� �Դϴ�\n "); 
	            // overlap != 0 �̴� ���ڸ� �ٽ� �����ϰ� �Ѵ�  
	    }         
	 }	 
	return num;
}

get_number_byCom(int cn[], int t ,int before_num) // before_num : ���� ������ ����  
{                          //t= turn  
	int x;
 	int w=N*N-1, T;
 	int p;
 	int num;
 	
	srand(time(NULL)); 
	
	// ���� ������ ���ڸ� ��ǻ�Ͱ� �������� ���ϰ�   
	for (x=0 ; x<N*N ; x++)
	{
		if (cn[x]==before_num)
	    {	
	        p = cn[w-2*t];   //  initiate_bingo �� ���� �������  
	        cn[w-2*t] = cn[x];  
	        cn[x] = p; 
	    }
	}
	
	num = cn[T=rand()%(N*N-2*t-1)];	// initiate_bingo �� ���� ���  
	p = cn[w-2*t-1];
	cn[w-2*t-1] = cn[T];
	cn[T] = p; 
	// 1turn �� ���� ���� ������ ���� cn[15], ��ǻ�� ������ ���� cn[14] �� �ٲ�ϱ�
	// �״����� (13,12) (11,10)---- �׷��� t*2�� ����� �Ѵ�  
	
	printf(" c input = %i\n",num);
	return num;
} 
