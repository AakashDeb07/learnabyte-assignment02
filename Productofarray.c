#include <stdio.h>
int min(int x, int y) 
{ 
return x < y ? x : y; 
}
int max(int x, int y) 
{ 
return x > y ? x : y;
 }
int maxSubarrayProduct(int arr[], int n)
{
	int maxend = 1;
	int minend = 1;
	int maxnow = 0;
	int flag = 0,i;
	for (i = 0; i < n; i++)
	 {
		if (arr[i] > 0) 
		{
			maxend = maxend * arr[i];
			minend= min(minend * arr[i], 1);
			flag = 1;
		}

		else if (arr[i] == 0) 
		{
			maxend = 1;
			minend = 1;
		}
		else 
		{
			int temp = maxend;
			maxend= max(minend * arr[i], 1);
			minend = temp * arr[i];
		}
		if (maxnow < maxend)
			maxnow = maxend;
	}
	if (flag == 0 && maxnow == 0)
		return 0;
	return maxnow;

	return maxnow;
}
int main()
{
	int n,arr[20],i;
   printf("Enter the size of array:");
   scanf("%d",&n);
   printf("Enter array elements:");
   for(i=0;i<n;i++)
   {
   scanf("%d",&arr[i]);
   }
	printf("Maximum Sub array product is %d",maxSubarrayProduct(arr, n));
	return 0;
}
