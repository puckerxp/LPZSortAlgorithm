//
//  main.c
//  Sort
//
//  Created by Puzhi Li on 2017/4/6.
//  Copyright © 2017年 Puzhi Li. All rights reserved.
//

#include <stdio.h>

void Print(int *p, int n);

void Swap(int *a, int *b)
{
    printf("%s %d %d\n", __FUNCTION__, *a, *b);
    int temp = *a;
    *a = *b;
    *b = temp;
}

void OptimizedBubbleSort(int p[], int n)
{
    printf("\n%s\n", __FUNCTION__);
    int alreadySorted = 1;
    for (int i = 0; i < n - 1 && alreadySorted; ++i)
    {
        alreadySorted = 0;
        for (int j = n - 1; j > i; --j)
        {
            if (p[j - 1] > p[j])
            {
                Swap(p + j - 1, p + j);
                alreadySorted = 1;
            }
        }

        printf("Round %d\n", i);
        Print(p, n);
    }
}

void BubbleSort(int p[], int n)
{
    printf("\n%s\n", __FUNCTION__);
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = n - 1; j > i; --j)
        {
            if (p[j - 1] > p[j])
            {
                Swap(p + j - 1, p + j);
            }
        }

        printf("Round %d\n", i);
        Print(p, n);
    }
}

int main(int argc, const char *argv[])
{
    int a[10] = {34, 18, 76, 37, 96, 45, 82, 23, 53, 68};
    Print(a, 10);
    BubbleSort(a, 10);

    int b[10] = {34, 18, 76, 37, 96, 45, 82, 23, 53, 68};
    Print(b, 10);
    OptimizedBubbleSort(b, 10);

    return 0;
}

void Print(int p[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
}

