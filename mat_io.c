// Definitions for "mat_io.h"
#include "mat_io.h"

#include "mat_mem.h"
#include "input.h"
#include <stdio.h>

// Gets a matrix through user input
void get_mat(void)
{
    int r, c, i;
    // Asks for matrix dimensions
    do
    {
        r = get_int(":: Rows: ");
        if (r < 1)
        {
            printf("\n/// Input Error: expected n > 0 ///\n\n");
        }
    }
    while (r < 1);
    do
    {
        c = get_int(":: Cols: ");
        if (c < 1)
        {
            printf("\n/// Input Error: expected n > 0 ///\n\n");
        }
    }
    while (c < 1);
    // Allocates memory for it
    i = alloc_mem(r, c);
    if (i < 0)
    {
        return;
    }
    // Takes in input for every element
    for (int j = 0; j < All[i].row; j++)
    {
        for (int k = 0; k < All[i].col; k++)
            {
                char string[100];
                sprintf(string, ":: a . %i . %i  =  ", j + 1, k + 1);
                All[i].ptr[j][k] = get_int(string);
            }
    }
    // Prints out the matrix and All index
    printf("\n");
    print_mat(i);
    printf("| Matrix stored at location %i |\n\n", i);
    return;
}

// Prints out a specific matrix
void print_mat(int n)
{
    // Checks if matrix actually exists
    if (All[n].ptr == NULL)
    {
        printf("\n// No matrix stored at location %i //\n\n", n);
        return;
    }
    // Finds the largest number digit-wise
    int tmp, count;
    int digits = 0;
    // Creates an array storing the num of digits of each element
    int meta[All[n].row][All[n].col];
    for (int i = 0; i < All[n].row; i++)
    {
        for (int j = 0; j < All[n].col; j++)
        {
            tmp = All[n].ptr[i][j];
            // In case tmp = 0, count = 1 (or else count would be wrong)
            count = (tmp == 0) ? 1 : 0;
            while (tmp != 0)
            {
                tmp /= 10;
                count++;
            }
            meta[i][j] = count;
            // If count > digits, digits = count, else, digits = digits
            digits = (count > digits) ? count : digits;
        }
    }
    // Prints it out
    for (int i = 0; i < All[n].row; i++)
    {
        for (int j = 0; j < All[n].col; j++)
        {
            if (meta[i][j] < digits)
            {
                printf("%i  ", All[n].ptr[i][j]);
                // Prints out the necessary padding
                for (int k = 0; k < (digits - meta[i][j]); k++)
                {
                    printf(" ");
                }
                continue;
            }
            printf("%i  ", All[n].ptr[i][j]);
        }
        printf("\n\n");
    }
    return;
}

// Formatted print of a matrix (used for output of operations)
void fprint_mat(int n)
{
    printf("\n");
    print_mat(n);
    printf("| Output matrix stored at location %i |\n\n", n);
    return;
}