// Definitions for "mat_misc.h"
#include "mat_misc.h"

#include "mat_mem.h"
#include "mat_io.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>

// Makes a copy of a matrix
void copy_mat(void)
{
    // Asks for index and checks for existence
    int *mats = check_mat(1);
    if (mats == NULL)
    {
        return;
    }
    int a = mats[0];
    free(mats);
    // Allocate memory for copy
    int b;
    b = alloc_mem(All[a].row, All[a].col);
    if (b < 0)
    {
        return;
    }
    // Copies each element into new matrix
    for (int i = 0; i < All[b].row; i++)
    {
        for (int j = 0; j < All[b].col; j++)
        {
            All[b].ptr[i][j] = All[a].ptr[i][j];
        }
    }
    // Prints out the copy (which is the same as the original)
    fprint_mat(b);
    return;
}

// Generates a nxn identity matrix
void id_mat(void)
{
    // Asks for order of identity matrix
    int n;
    do
    {
        n = get_int(">> Order: ");
        if (n < 1)
        {
            printf("\n/// Input Error: expected n > 0 ///\n\n");
        }
    }
    while (n < 1);
    // Allocate memory for matrix
    int a;
    a = alloc_mem(n, n);
    if (a < 0)
    {
        return;
    }
    // Assigns values to elements of matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            All[a].ptr[i][j] = (i == j) ? 1 : 0;
        }
    }
    // Prints out the matrix
    fprint_mat(a);
    return;
}