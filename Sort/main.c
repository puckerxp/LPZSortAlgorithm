//
//  main.c
//  Sort
//
//  Created by Puzhi Li on 2017/4/6.
//  Copyright © 2017年 Puzhi Li. All rights reserved.
//

#include <stdio.h>

void Print(int *p, int n);

void Swap(int p[], int i, int j)
{
    printf("%s %d %d\n", __FUNCTION__, p[i], p[j]);
    int temp = p[i];
    p[i] = p[j];
    p[j] = temp;
}

void BinaryInsertionSort(int p[], int n)
{
    printf("\n%s\n", __FUNCTION__);
    Print(p, n);

    for (int i = 1; i < n; ++i)
    {
        int low = 0, high = i - 1, temp = p[i];
        printf("low = %d, high = %d\n", low, high);

        while (low <= high)
        {
            int mid = (high + low) / 2;
            if (p[mid] <= temp)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }

            printf("low = %d, high = %d\n", low, high);
        }

        for (int j = i; j > low; --j)
        {
            p[j] = p[j - 1];
            Print(p, n);
        }

        if (low != i)
        {
            p[low] = temp;
        }

        printf("Round %d\n", i - 1);
        Print(p, n);
    }
}

void InsertionSort(int p[], int n)
{
    printf("\n%s\n", __FUNCTION__);
    int j, temp;
    for (int i = 1; i < n; ++i)
    {
        if (p[i] < p[i - 1])
        {
            temp = p[i];

            for (j = i - 1; j >= 0 && p[j] > temp; --j)
            {
                p[j + 1] = p[j];
            }

            p[j + 1] = temp;
        }

        printf("Round %d\n", i - 1);
        Print(p, n);
    }
}

void SelectionSort(int p[], int n)
{
    printf("\n%s\n", __FUNCTION__);
    int minIndex;
    for (int i = 0; i < n; ++i)
    {
        minIndex = i;

        for (int j = i + 1; j < n; ++j)
        {
            if (p[minIndex] > p[j])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            Swap(p, i, minIndex);
        }

        printf("Round %d\n", i);
        Print(p, n);
    }
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
                Swap(p, j - 1, j);
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
                Swap(p, j - 1, j);
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

    int c[10] = {34, 18, 76, 37, 96, 45, 82, 23, 53, 68};
    Print(c, 10);
    SelectionSort(c, 10);

    int d[10] = {34, 18, 76, 37, 96, 45, 82, 23, 53, 68};
    Print(d, 10);
    InsertionSort(d, 10);

    int e[10] = {34, 18, 76, 37, 96, 45, 82, 23, 53, 68};
    Print(e, 10);
    BinaryInsertionSort(e, 10);

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

