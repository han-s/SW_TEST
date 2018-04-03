#include<stdio.h>
#include<string.h>
int main(void)
{
	char arr1[100], arr2[100];
	int i=0, cnt=1, j=0;
	
	scanf("%s",arr1);
	for(i=0; arr1[i]; i++){
		if(arr1[i] == arr1[i+1]){
			cnt++;
		}
		else
		{
			arr2[j++] = arr1[i];
			sprintf(&arr2[j++],"%d",cnt);
			cnt=1;
		}
	}

	if(strlen(arr1) <= strlen(arr2)){
		for(i=0; arr1[i]; i++)
			printf("%c", arr1[i]);

		return 0;
	}

	printf("%s", arr2);

	return 0;
}
	
