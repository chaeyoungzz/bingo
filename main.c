#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
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

print_bingo(int BINGO[][N], int NAME) 
{
	int i, j;
	
	if (NAME == 1) // 알아보기 쉽게 이름을 정해주려고,,,, 
	{
		printf("<YOU>\n");
	}
	else
	{
		printf("<COM>\n");
	}
	
	// 실제 배열을 프린트 하는 코드  
	for( i=0 ; i<N ; i++)
	{
		for( j=0 ; j<N ; j++)
		{
			printf(" %3d ", BINGO[i][j]);
		}
		printf("\n");
	}
	printf("\n");
 } 
 
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


int main(int argc, char *argv[]) 
{
	int bingo_game[N][N], C_bingo_game[N][N];    // 내꺼  컴퓨터 
	int bingo=0, Cbingo=0; // 나의 빙고 수, 컴퓨터 빙고 수  
	int NUM, CNUM; // 선택한 빙고 번호  
	int CN[N*N], i;// 컴튜터 빙고 번호 불러오기 위한 배열  
	int y=1;  // CN[] 배열                  
	int turn=0;  
	srand(time(NULL)); 
	           
	           
	initiate_bingo(bingo_game) ;
	initiate_bingo(C_bingo_game);
	 
	for (i=0 ; i<N*N ; i++)  // 컴퓨터가 선택할 빙고 번호 중복 방지를 위해  
 	{
 		CN[i]=y;
 		y++;
	}
	
	print_bingo(bingo_game,1);
	print_bingo(C_bingo_game,2);
	
	while ( bingo < M && Cbingo < M)  
    {
	   
	    NUM = get_number_byMe(bingo_game);// 숫자 선 택  
	    process_bingo(bingo_game, NUM);   // 선택된 숫자 -1로 처리  
	    process_bingo(C_bingo_game, NUM);
	    
	    print_bingo(bingo_game,1);         // 화면에 출력  
	    print_bingo(C_bingo_game,2);
	    
	    bingo = count_bingo(bingo_game);   // 빙고 수 확인  
	    Cbingo = count_bingo(C_bingo_game);
	    printf("bingo %i\n", bingo);
	    printf("Cbingo %i\n", Cbingo);
		printf("\n");	    
	    
	    if(bingo < M && Cbingo < M) 
		{
			CNUM = get_number_byCom(CN, turn, NUM);  // 위 과정과 동일  
	        process_bingo(bingo_game, CNUM);
	        process_bingo(C_bingo_game, CNUM);
	    
	        print_bingo(bingo_game,1);
	        print_bingo(C_bingo_game,2);
	    
	        bingo = count_bingo(bingo_game);
	        Cbingo = count_bingo(C_bingo_game);
	        printf("bingo %i\n", bingo);
	        printf("Cbingo %i\n", Cbingo);
	        printf("\n");
	        turn++;	
	
		}    
    }
    
    
    //빙고 승자 판단 , 횟수  
	if (bingo >= M && Cbingo >= M )
	{
		printf(" DRAW , %iturn",turn );  // 비김  
	}
	
	else if (Cbingo >= M)
	{
		printf(" COM WIN !!!!, %iturn",turn );  // cOM 이김  
	}
	
	else if  (bingo >= M)
	{
		printf(" YOU WIN !!!!, %iturn",turn );  // YOU 이김  
	}
	return 0;
}









