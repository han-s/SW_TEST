#include<stdio.h>
asd
int main(void)
{
	int M,N,i,j;
	int tf=0;
	scanf("%d, %d", &M, &N);
	int arr[M][N];
	int arr2[M][N];

	for(i=0; i<M; i++)
		for(j=0; j<N; j++)
			scanf("%d", &arr[i][j]);

	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			if(arr[i][j]==0){
				arr2[i][j]=1;
			}
		}
	}

	int k;
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			if(arr2[i][j]){
				for(k=0; k<M;k++){
					arr[k][j]=0;
				}
				for(k=0; k<N; k++){
					arr[i][k]=0;
				}
			}
		}
	}

	return 0;
}
