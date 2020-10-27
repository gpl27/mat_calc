// Definitions for "mat_op.h"
#include "mat_op.h"

#include "mat_mem.h"
#include "mat_io.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>

// Adds or subtracts two matrices and stores sum/difference in a third matrix
// Addition -> op = 1
// Subtraction -> op = 0
void add_sub_mat(int op)
{
    // Asks for indices and checks for existence
    int *mats = check_mat(2);
    if (mats == NULL)
    {
        return;
    }
    int a = mats[0];
    int b = mats[1];
    free(mats);
    // Makes sure it is possible to add/subtract those two matrices
    if (All[a].row != All[b].row || All[a].col != All[b].col)
    {
        printf("\n// Unable to add: matrices are not of the same order //\n\n");
        return;
    }
    // Allocates memory for sum/difference
    int c;
    c = alloc_mem(All[a].row, All[a].col);
    if (c < 0)
    {
        return;
    }
    // Does the addition/subtraction operation
    for (int j = 0; j < All[a].row; j++)
    {
        for (int k = 0; k < All[a].col; k++)
        {
            All[c].ptr[j][k] = (op == 1) ? All[a].ptr[j][k] + All[b].ptr[j][k] : All[a].ptr[j][k] - All[b].ptr[j][k];
        }
    }
    // Prints out the sum/difference
    fprint_mat(c);
    return;
}

// Sums n matrices
void sum_mat(void)
{
    // Asks how many matrices will be summed
    int n;
    do
    {
        n = get_int(":: Number of matrices to sum: ");
        if (n < 2)
        {
            printf("\n/// Input Error: expected n > 1 ///\n\n");
        }
    } 
    while (n < 2);
    // Checks for matrices existence and stores their location
    int *mats = check_mat(n);
    if (mats == NULL)
    {
        return;
    }
    // Checks for compatibility
    int c, d;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            continue;
        }
        c = mats[i - 1];
        d = mats[i];
        if (All[c].row != All[d].row || All[c].col != All[d].col)
        {
            printf("\n// Unable to sum: matrices are not of the same order //\n\n");
            return;
        }
    }
    // Allocates memory for sum matrix
    int sum;
    int tmp = mats[0];
    sum = alloc_mem(All[tmp].row, All[tmp].col);
    if (sum < 0)
    {
        return;
    }
    // Does the sum operation
    int index;
    int i = 0;
    while (i < n)
    {
        index = mats[i];
        for (int j = 0; j < All[sum].row; j++)
        {
            for (int k = 0; k < All[sum].col; k++)
            {
                if (i == 0)
                {
                    All[sum].ptr[j][k] = All[index].ptr[j][k];
                    continue;
                }
                All[sum].ptr[j][k] += All[index].ptr[j][k];
            }
        }
        i++;
    }
    free(mats);
    // Prints out the sum
    fprint_mat(sum);
    return;
}

// Multiplies two matrices and stores product in a third matrix
void mult_mat(void)
{
    // Asks for indices and checks for existence
    int *mats = check_mat(2);
    if (mats == NULL)
    {
        return;
    }
    int a = mats[0];
    int b = mats[1];
    free(mats);
    // Makes sure it's possible to multiply those two matrices
    if (All[a].col != All[b].row)
    {
        printf("\n// Unable to multiply: colA != rowB //\n\n");
        return;
    }
    // Allocates memory for product
    int c;
    c = alloc_mem(All[a].row, All[b].col);
    if (c < 0)
    {
        return;
    }
    int sum = 0;
    // Does the multiplication (sum of rowA * colB)
    for (int i = 0; i < All[c].row; i++)
    {
        for (int j = 0; j < All[c].col; j++)
        {
            for (int k = 0; k < All[a].col; k++)
            {
                sum += (All[a].ptr[i][k] * All[b].ptr[k][j]);
            }
            All[c].ptr[i][j] = sum;
            sum = 0;
        }
    }
    // Prints out the product
    fprint_mat(c);
    return;
}

// Multiplies a matrix by k
void multk_mat(void)
{
    // Asks for index and checks for existence
    int *mats = check_mat(1);
    if (mats == NULL)
    {
        return;
    }
    int a = mats[0];
    free(mats);
    // Gets k
    int k;
    k = get_int(":: k = ");
    // Allocates memory for product
    int b;
    b = alloc_mem(All[a].row, All[a].col);
    if (b < 0)
    {
        return;
    }
    // Multiplies by k
    for (int i = 0; i < All[a].row; i++)
    {
        for (int j = 0; j < All[a].col; j++)
        {
            All[b].ptr[i][j] = All[a].ptr[i][j] * k;
        }
    }
    // Prints out the product
    fprint_mat(b);
    return;
}

// Transposes a matrix
void transpose_mat(void)
{
    // Asks for index and checks for existence
    int *mats = check_mat(1);
    if (mats == NULL)
    {
        return;
    }
    int a = mats[0];
    free(mats);
    // Allocates memory for transposed matrix
    int b;
    b = alloc_mem(All[a].col, All[a].row);
    if (b < 0)
    {
        return;
    }
    // Transposes the matrix
    for (int i = 0; i < All[a].row; i++)
    {
        for (int j = 0; j < All[a].col; j++)
        {
            All[b].ptr[j][i] = All[a].ptr[i][j];
        }
    }
    // Prints out the transposed matrix
    fprint_mat(b);
    return;
}