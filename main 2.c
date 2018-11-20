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
	// �ߺ� ���� �迭   
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
    	    for( i=0 ; i<N ; i++)          // �ߺ� ���� ����  
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
	            printf(" �̹� ���õ� ���� �Դϴ�\n "); 
	    }         
	 }	 

	return num;
}

get_number_byCom(int cn[], int t ,int before_num)
{

	int x;
 	int w=N*N-1, T;
 	int p;
 	int num;
 	
	srand(time(NULL)); 
	
	// �ߺ� ���� ����  

	for (x=0 ; x<N*N ; x++)
	{
		if (cn[x]==before_num)
	    {	
	        p = cn[w-2*t];
	        cn[w-2*t] = cn[x];
	        cn[x] = p; 
	    }
	}
	
	num = cn[T=rand()%(N*N-2*t-1)];	
	p = cn[w-2*t-1];
	cn[w-2*t-1] = cn[T];
	cn[T] = p; 
	
	for (x=0 ; x<N*N ; x++)
	    printf("cn[%i] = %i\n", x, cn[x]);
	
	printf(" c input = %i\n",num);
	return num;
} 

process_bingo(int BINGO[][N], int num) // num : ������ ���� ��ȣ  
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
	int count3 = 0, count4 = 0; // 3 : ������ ���� �밢��  4 : ���ʹ��� �밢��  
	int CR1=0, CR2=0, C1=0, C2=0; // 1:����  2:����  3:������ ���� �밢��   4: ���� ���� �밢��   
	int m;

	for( i=0 ; i<N ; i++) 
 	{
 	    int count1 =0, count2 = 0;
 	    
		if(B[i][i]==-1)               //�����ʹ��� �밢��  
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
                CR1=count1/N;
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

int main(int argc, char *argv[]) 
{
	int bingo_game[N][N], C_bingo_game[N][N];    // ����  ��ǻ�� 
	int bingo=0, Cbingo=0; // ���� ���� ��, ��ǻ�� ���� ��  
	int NUM, CNUM; // ������ ���� ��ȣ  
	int CN[N*N], i;// ��Ʃ�� �ߺ� ���� 
	int y=1;  // CN[] �迭                   
	int turn=0;              
	
	srand(time(NULL));
	initiate_bingo(bingo_game) ;
	initiate_bingo(C_bingo_game);
	 
	for (i=0 ; i<N*N ; i++)
 	{
 		CN[i]=y;
 		y++;
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
		printf("\n");	    

	    if(bingo < M && Cbingo < M) 
		{
			CNUM = get_number_byCom(CN, turn, NUM);
	        process_bingo(bingo_game, CNUM);
	        process_bingo(C_bingo_game, CNUM);
	    
	        print_bingo(bingo_game);
	        print_bingo(C_bingo_game);
	    
	        bingo = count_bingo(bingo_game);
	        Cbingo = count_bingo(C_bingo_game);
	        printf("bingo %i\n", bingo);
	        printf("Cbingo %i\n", Cbingo);
	        printf("\n");
	        turn++;	
		}    
    }

    //���� ���� �Ǵ� , Ƚ��  
	if(bingo >= M) 
	{
		printf(" WIN!!!!, %iturn",turn );
    }
	else if (Cbingo >= M)
	{
		printf(" COM WIN!!!!, %iturn",turn );
	}
	return 0;
}