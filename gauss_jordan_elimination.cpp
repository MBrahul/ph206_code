#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
#define N 4

void print(double mat[N][N + 1])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            printf("%4.3lf ", mat[i][j]);
        }
        printf("\n");
    }
}
void print2(double mat[N][2 * N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2 * N; j++)
        {
            printf("%4.3lf ", mat[i][j]);
        }
        printf("\n");
    }
}

void convertToDiagonal(double mat[N][N + 1])
{
    for (int i = 0; i < N; i++)
    {
        if (mat[i][i] == 0)
        {
            //     c = 1;
            //     while ((i + c) < n && a[i + c][i] == 0)
            //         c++;
            //     if ((i + c) == n)
            //     {
            //         flag = 1;
            //         break;
            //     }
            //     for (j = i, k = 0; k <= n; k++)
            //         swap(a[j][k], a[j + c][k]);
        }
        for (int j = 0; j < N; j++)
        {
            if (i != j)
            {
                double f = mat[j][i] / mat[i][i];
                for (int k = 0; k <= N; k++)
                {
                    mat[j][k] -= mat[i][k] * f;
                }
            }
        }
    }
}

void inverse(double mat[N][2 * N])
{
    for (int i = 0; i < N; i++)
    {
        if (mat[i][i] == 0)
        {
            //  break;
        }
        for (int j = 0; j < N; j++)
        {
            if (i != j)
            {
                double f = mat[j][i] / mat[i][i];
                for (int k = 0; k < 2 * N; k++)
                {
                    mat[j][k] -= mat[i][k] * f;
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        double f = mat[i][i];
        for (int j = 0; j < 2 * N; j++)
        {
            mat[i][j] = mat[i][j] / f;
        }
    }
}

void printResult(double mat[N][N + 1])
{
    double x[N];
    for (int i = 0; i < N; i++)
    {
        x[i] = mat[i][N] / mat[i][i];
    }
    printf("solutions are:\n");
    for (int i = 0; i < N; i++)
    {
        printf("%4.3lf\n", x[i]);
    }
}

int main()
{

    // double mat[N][N + 1] = {{3, 2, 1, 4},
    //                         {1, 10, 2, 6},
    //                         {2, 1, 1, 7}};
    double mat2[N][2 * N] = {{5, -2, 2, 7, 1, 0, 0, 0},
                             {1, 0, 0, 3, 0, 1, 0, 0},
                             {-3, 1, 5, 0, 0, 0, 1, 0},
                             {3, -1, -9, 4, 0, 0, 0, 1}};
    // convertToDiagonal(mat);
    // print(mat);
    // printResult(mat);
    inverse(mat2);
    print2(mat2);
    return 0;
}