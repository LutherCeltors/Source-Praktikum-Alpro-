#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k;
    scanf("%d\n%d", &n, &k);
    int arr[n], rot[k];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < k; i++)
        scanf("%d", &rot[i]);
    for (int i = 0; i < k; i++)
    {
        printf("[");
        for (int j = 0; j < n; j++)
        {
            int idx = (j - rot[i]) % n;
            if (idx < 0)
                idx += n;
            printf("%d", arr[idx]);
            if (j < n - 1)
                printf(", ");
        }
        printf("]\n");
    }

    return 0;
}