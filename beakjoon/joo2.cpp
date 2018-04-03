#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int gear[4][8]={0};

void right_spin(int gear[4][8], int n)
{
   int tmp;
   tmp =  gear[n][7];
   for(int i=7; i>0; i--)
   {
      gear[n][i] = gear[n][i-1];
   }
   gear[n][0] = tmp;
   
   
}

void left_spin(int gear[4][8], int n)
{
   int tmp;
   tmp = gear[n][0];
   for(int i=0; i<7; i++)
   {
      gear[n][i] = gear[n][i+1];
   }   
   gear[n][7] = tmp;
   
}
void spin(int gear[4][8], int n, int flag, int gearflag)
{ 
   if(flag == 0)// 양쪽으로 다 돌릴 때 
   {
      if(n==0)
      {
         if(gearflag == 0)
         {
            if(gear[0][2]==gear[1][6])
            {
               left_spin(gear,0);
               return;
            }
            else
            {
               spin(gear, 1, 2, 1);
               left_spin(gear,0);
            }
         }
         else if(gearflag == 1)
         {
            if(gear[0][2]==gear[1][6])
            {
               right_spin(gear,0);
               return;
            }
            else
            {
               spin(gear, 1, 2, 0);
               right_spin(gear,0);
            }
         }
      }
      else if(n==7)
      {
         if(gearflag == 0)
         {
            if(gear[7][6]==gear[6][2])
            {
               left_spin(gear,7);
               return;
            }
            else
            {
               spin(gear, 6, 1, 1);
               left_spin(gear,7);
            }
         }
         else if(gearflag == 1)
         {
            if(gear[7][6]==gear[6][2])
            {
               right_spin(gear,7);
               return;
            }
            else
            {
               spin(gear, 6, 1, 0);
               right_spin(gear,7);
            }
         }
      }
      else
      {
         if(gearflag == 0)//left spin
         {
            if(gear[n][2]==gear[n+1][6])
            {
            }
            else
            {
               spin(gear, n+1, 2, 1);
            }
            
            if(gear[n][6]==gear[n-1][2])
            {
            }
            else
            {
               spin(gear, n-1, 1, 1);
            }
            left_spin(gear,n);
         }
         if(gearflag == 1)//right spin
         {
            if(gear[n][2]==gear[n+1][6])
            {
            }
            else
            {
               spin(gear, n+1, 2, 0);
            }
            
            if(gear[n][6]==gear[n-1][2])
            {
            }
            else
            {
               spin(gear, n-1, 1, 0);
            }
            right_spin(gear,n);
         }
      }
   
   }
   
   if(flag == 1)// 작은 기어쪽으로 갈 때 
   {
      if(n==0)
      {
         if(gearflag==0)
         {
            left_spin(gear,0);
         }
         else if(gearflag==1)
         {
            right_spin(gear,0);
         }
         return;
      }
      else if(n>0)
      {
         if(gearflag==0)
         {
            if(gear[n][6]==gear[n-1][2])
            {
            }
            else
            {
               spin(gear, n-1, 1, 1);
            }
            left_spin(gear,n);
         }
         else if(gearflag==1)
         {
            if(gear[n][6]==gear[n-1][2])
            {
            }
            else
            {
               spin(gear, n-1, 1, 0);
            }
            right_spin(gear,n);
         }
      }
   }
   
   if(flag == 2)// 큰 기어 쪽으로 갈 때 
   {
      if(n==7)
      {
         if(gearflag==0)
         {
            left_spin(gear,7);
         }
         else if(gearflag==1)
         {
            right_spin(gear,7);
         }
         return;
      }
      else if(n<7)
      {
         if(gearflag==0)
         {
            if(gear[n][2]==gear[n+1][6])
            {
            }
            else
            {
               //Sleep(1000);
               spin(gear, n+1, 2, 1);
            }
            left_spin(gear,n);
         }
         else if(gearflag==1)
         {
            if(gear[n][2]==gear[n+1][6])
            {
            }
            else
            {
               //Sleep(1000);
               spin(gear, n+1, 2, 0);
            }
            right_spin(gear,n);
         }
      }
   }
}


int main(void)
{
   int k;
   int result = 0;
   int* g;//gear번호 
   int* d;//시계방향인지 반시계인지
   
   for(int i=0; i<4; i++)
   {
      for(int j=0; j<8; j++)
      {
         scanf("%1d", &gear[i][j]);
      }
   }
   
   
   cin>>k;
   g = (int*)malloc(sizeof(int)*k);
   d = (int*)malloc(sizeof(int)*k);
   
   for(int i=0; i<k; i++)
   {
      cin>>g[i];
      cin>>d[i];
      if(d[i] == -1)
      {
         d[i] = 0;
      }
      g[i]--;
   }
   
   for(int i=0; i<k; i++)
   {
      spin(gear,g[i],0,d[i]);
   }
   
   for(int i=0; i<4; i++)
   {
      if(gear[i][0]==1)
         result+=pow(2,i);
   }
   
   
   printf("%d", result);
   
   return 0;
   
} 
