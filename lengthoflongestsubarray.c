#include <stdio.h>
#include<stdbool.h>
int LongestSubarray(int a[], int n, int k)
{
    int pre[n],i;
    for (i = 0; i < n; i++) 
	{
        if (a[i] > k)
            pre[i] = 1;
        else
            pre[i] = -1;
    }
    for (i = 1; i < n; i++)
        pre[i] = pre[i - 1] + pre[i];
    int len = 0;
    int lo = 1, hi = n;
    while (lo <= hi)
	 {
        int mid = (lo + hi) / 2;
        bool ok = false;
        for (i = mid - 1; i < n; i++)
		 {
            int x = pre[i];
            if (i - mid >= 0)
                x -= pre[i - mid];
            if (x > 0) 
			{
                ok = true;
                break;
            }
        }
        if (ok == true) 
		{
            len = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return len;
}

int main()
{
    int k,n,a[20],i;
   printf("Enter the size of array:");
   scanf("%d",&n);
   printf("Enter array elements:");
   for(i=0;i<n;i++)
   {
   scanf("%d",&a[i]);
   }
   printf("Enter key:");
   scanf("%d",&k);
    printf("The sum is: %d",LongestSubarray(a, n, k));
    return 0;
}
