#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 4
#define M 3

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

get_number_byMe( int B[][N])
{
 	int i, j ;
 	int num;  // 선택한 빙고 번 호  
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
    	    for( i=0 ; i<N ; i++)          
	        {
		        for( j=0 ; j<N ; j++)
		        {
			        if( B[i][j] == num ) // 아직 선택되지 않은 숫자이면  
			        {
		                overlap=0;    // while 문을 빠져나가게 한다  
				    }
		        }
	        }  
	        
	        if (overlap==1)    // B[i][j] == num 이 없으면  B[i][j] =-1 이니 이미 선택된 숫자이다  
	            printf(" 이미 선택된 숫자 입니다\n "); 
	            // overlap != 0 이니 숫자를 다시 선택하게 한다  
	    }         
	 }	 
	return num;
}

get_number_byCom(int cn[], int t ,int before_num) // before_num : 내가 선택한 숫자  
{                          //t= turn  
	int x;
 	int w=N*N-1, T;
 	int p;
 	int num;
 	
	srand(time(NULL)); 
	
	// 내가 선택한 숫자를 컴퓨터가 선택하지 못하게   
	for (x=0 ; x<N*N ; x++)
	{
		if (cn[x]==before_num)
	    {	
	        p = cn[w-2*t];   //  initiate_bingo 와 같은 방법으로  
	        cn[w-2*t] = cn[x];  
	        cn[x] = p; 
	    }
	}
	
	num = cn[T=rand()%(N*N-2*t-1)];	// initiate_bingo 와 같은 방법  
	p = cn[w-2*t-1];
	cn[w-2*t-1] = cn[T];
	cn[T] = p; 
	// 1turn 을 돌면 내가 선택한 숫자 cn[15], 컴퓨터 선택한 숫자 cn[14] 로 바뀌니까
	// 그다음은 (13,12) (11,10)---- 그러니 t*2를 해줘야 한다  
	
	printf(" c input = %i\n",num);
	return num;
} 
