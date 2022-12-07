// Max Min Recursive
#include <stdio.h>
int a[10], n, max, min;
int maxmin(int i, int j)
{
    int max1, min1, mid;
    if (i == j)
    {
        max = a[i];
        min = a[i];
    }
    else if (i == j - 1)
    {
        if (a[i] > a[j])
        {
            max = a[i];
            min = a[j];
        }
        else
        {
            max = a[j];
            min = a[i];
        }
    }
    else
    {
        mid = (i + j) / 2;
        maxmin(i, mid);
        max1 = max;
        min1 = min;
        maxmin(mid + 1, j);
        if (max1 > max)
            max = max1;
        if (min1 < min)
            min = min1;
    }
}
int main()
{
    int i, n;
    printf("Enter array size: ");
    scanf("%d", &n);
    printf("\nEnter elements in array: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    maxmin(0, n - 1);
    printf("\nMax element = %d ", max);
    printf("\nMin element = %d ", min);
}

//using divide and conquer the time complexity for finding min and max is O(n).
