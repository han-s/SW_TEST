#include<stdio.h>

int main(void)
{
	int n=10, check=0, k=0;
	char arr[10]="a b c";
	char arr2[10];
	//scanf("%s", arr);
	//scanf("%d", &n);

	for(int i=0; i<n; i++)
	{
		if(arr[i] != ' ')
		{

			if(check ==1)
			{
				arr2[k++] = '%';
				arr2[k++] = '2';
				arr2[k++] = '0';
				check =0;
			}

			arr2[k] = arr[i];
			k++;
		}
		else
		{
			printf("qwe\n");
			check =1;
		}
	}
	printf("%s\n", arr2);
	return 0;
}
