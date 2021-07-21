#include <stdio.h>
int subArraySum(int arr[], int n, int sum)
{
	int csum, i, j;
	for (i = 0; i < n; i++) 
	{
		csum = arr[i];
		for (j = i + 1; j <= n; j++) 
		{
			if (csum == sum) 
			{
				printf("Sum: %d ",csum);
				printf("\nSum found between indexes %d and %d",i, j - 1);
				return 1;
			}
			if (csum > sum || j == n)
				break;
			csum = csum + arr[j];
		}
	}
	printf("No subarray found");
	return 0;
}
int main()
{
	int sum,n,arr[20],i;
   printf("Enter the size of array:");
   scanf("%d",&n);
   printf("Enter array elements:");
   for(i=0;i<n;i++)
   {
   scanf("%d",&arr[i]);
   }
   printf("Enter sum:");
   scanf("%d",&sum);
   subArraySum(arr, n, sum);
	return 0;
}
