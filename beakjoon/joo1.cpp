#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main(void){
   
   int N, L;
   int** arr;
   int* width;
   int* column;
   cin>>N>>L;
   int unable = 0;
   int count = 0;
   bool down = 0;
   int result = 0;
   
   column = (int*)malloc(sizeof(int)*N);
   width = (int*)malloc(sizeof(int)*N);
   
   arr = (int**)malloc(sizeof(int*)*N);
   for(int i=0; i<N; i++)
   {
      arr[i] = (int*)malloc(sizeof(int)*N);
      width[i] = 0;
      column[i] = 0;
   }
   
   for(int i=0; i<N; i++)
   {
      for(int j=0; j<N; j++)
      {
         cin>>arr[i][j];   
      }
   }
   
   for(int i=0; i<N; i++)
   {
      for(int j=0; j<N; j++)
      {
         if(j == 0)
         {
            count=1;
            down = 0;
         }
         else if(j>0)
         {
            if(arr[i][j]==arr[i][j-1])
            {
               count++;
               if(down==1&&count==L)
               {
                  down = 0;
                  count = 0;
               }
               else if(down==1&&count>L)
               {
                  down = 0;
                  count = count-L;
               }
            }
            else if(arr[i][j]-arr[i][j-1]==1)//올라가는 경우 
            {
               if(down==1)
               {
                  width[i] = 1;
                  down = 0;
               }
               else if(down==0&&count >= L)
               {
                  count = 1+count-L;
               }
               else if(down==0&&count<L)
               {
                  width[i] = 1;
               }
            }
            else if(arr[i][j-1]-arr[i][j]==1)//내려가는 경우
            {
               if(down==1&&count>=L)
               {
                  down = 0;
                  count = count-L;
               }
               else if(down==1&&count<L)
               {
                  width[i] = 1;
               } 
               else
               {
                  down=1;
                  count = 1;
               }
            }
            else if(abs(arr[i][j]-arr[i][j-1])>1)
            {
               width[i] = 1;
               down = 0;
            }
         }
         
         if(j == N-1&&down==1)
         {
            if(down==1&&count>=L)
               {
                  down = 0;
                  count = count-L;
               }
            else{
               width[i] = 1;
            down = 0;
            }
         }   
      }
   }//가로
   
   for(int j=0; j<N; j++)
   {
      for(int i=0; i<N; i++)
      {
         if(i == 0)
         {
            count=1;
            down = 0;
         }
         else if(i>0)
         {
            if(arr[i][j]==arr[i-1][j])
            {
               count++;
               if(down==1&&count==L)
               {
                  down = 0;
                  count = 0;
               }
               else if(down==1&&count>L)
               {
                  down = 0;
                  count = count-L;
               }
            }
            else if(arr[i][j]-arr[i-1][j]==1)//올라가는 경우 
            {
               if(down==1)
               {
                  column[j] = 1;
                  down = 0;
               }
               else if(down==0&&count >= L)
               {
                  count = 1+count-L;
               }
               else if(down==0&&count<L)
               {
                  column[j] = 1;
               }
            }
            else if(arr[i-1][j]-arr[i][j]==1)//내려가는 경우
            {
               if(down==1&&count>=L)
               {
                  down = 0;
                  count = count-L;
               }
               else if(down == 1&&count<L)
               {
                  column[j] = 1;
               }
               else
               {
                  down=1;
                  count = 1;
               }
            }
            else if(abs(arr[i-1][j]-arr[i][j])>1)
            {
               column[j] = 1;
               down = 0;
            }
         }
         
         if(i == N-1&&down==1)
         {
            if(down==1&&count>=L)
               {
                  down = 0;
                  count = count-L;
               }
            else{
               column[j] = 1;
            down = 0;
            }
            
         }   
      }
   } 
   
   for(int i=0; i<N; i++)
   {
      if(column[i] == 0)
         result++;
      if(width[i] == 0)
         result++;
   }
   
   printf("%d", result);
   
   return 0;
}
