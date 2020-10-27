// Definitions for "mat_mem.h"
#include "mat_mem.h"

#include "input.h"
#include <stdlib.h>
#include <stdio.h>

// Error handling
static void free_Error(int index, int iter);

// Allocates necessary amount of memory according to matrix size
// Retruns All[] index where mem was alloced if successfull
// Returns a negative number if it fails to allocate
int alloc_mem(int row, int col)
{
    // Tries to find space in All for matrix
    int i;
    int found = 0;
    for (i = 0; i < MAX; i++)
    {
        if (All[i].ptr == NULL)
        {
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("\n///// Memory Error: too many matrices in use /////\n\n");
        return -1;
    }
    // Allocates memory for the matrix and points the All[i].ptr to that memory
    All[i].row = row;
    All[i].col = col;
    All[i].ptr = malloc(sizeof(int *) * All[i].row);
    if (All[i].ptr == NULL)
    {
        printf("\n///// Memory Error: malloc() failed (pointer) at alloc_mem() /////\n\n");
        return -2;
    }
    for (int j = 0; j < All[i].row; j++)
    {
        All[i].ptr[j] = malloc(sizeof(int) * All[i].col);
        // In case one of the mallocs fail free_Error() will free any memory
        if (All[i].ptr[j] == NULL)
        {
            printf("\n///// Memory Error: malloc() failed (int) at alloc_mem() /////\n\n");
            free_Error(i, j);
            return -3;
        }
    }
    return i;
}

// If malloc() runs into an error in the middle of alloc_mem()
// this will free any memory that was allocated before
// the error occurred to avoid any possible memory leak
// Takes in the All index and what iteration of the allocating process it failed
static void free_Error(int index, int iter)
{
    for (int i = 0; i < iter; i++)
    {
        free(All[index].ptr[i]);
        All[index].ptr[i] = NULL;
    }
    free(All[index].ptr);
    All[index].ptr = NULL;
    return;
}

// Deletes all matrices
void free_All(void)
{
    // Iterates through All looking for non-NULL to free
    for (int i = 0; i < MAX; i++)
    {
        if (All[i].ptr == NULL)
        {
            continue;
        }
        for (int j = 0; j < All[i].row; j++)
        {
            free(All[i].ptr[j]);
            All[i].ptr[j] = NULL;
        }
        free(All[i].ptr);
        All[i].ptr = NULL;
    }
    printf("\n| Successfully cleared all matrices |\n\n");
    return;
}

// Deletes a specific matrix
void free_mat(void)
{
    int *mats = check_mat(1);
    if (mats == NULL)
    {
        return;
    }
    int loc = mats[0];
    free(mats);
    // Frees the memory (deletes the matrix)
    for (int i = 0; i < All[loc].row; i++)
    {
        free(All[loc].ptr[i]);
        All[loc].ptr[i] = NULL;
    }
    free(All[loc].ptr);
    All[loc].ptr = NULL;
    printf("\n| Successfully deleted matrix %i |\n\n", loc);
    return;
}

// Checks for a matrix's existence
int *check_mat(int n)
{ 
    int *existent = malloc(sizeof(int) * n);
    if (existent == NULL)
    {
        printf("\n///// Memory Error: malloc() failed at check_mat() /////\n\n");
        return NULL;
    }
    for (int i = 0; i < n; i++)
    {
        // Asks for index and checks for existence
        int tmp;
        char string[100];
        sprintf(string, ":: %c's location: ", (char)(i + 65));
        do
        {
            tmp = get_int(string);
            if (tmp >= MAX || tmp < 0)
            {
                printf("\n/// Input Error: expected 0 <= n < MAX ///\n\n");
            }
        }
        while (tmp >= MAX || tmp < 0);
        if (All[tmp].ptr == NULL)
        {
            printf("\n// No matrix stored at location %i //\n\n", tmp);
            free(existent);
            return NULL;
        }
        existent[i] = tmp;
    }
    return existent;
}