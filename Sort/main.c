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
    printf("%s\n", __FUNCTION__);
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int p[], int n)
{
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
    // insert code here...
    printf("Hello, World!\n");

    int p[10] = {34, 18, 76, 37, 96, 45, 82, 23, 53, 68};

    Print(p, 10);

    BubbleSort(p, 10);

    Print(p, 10);
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

