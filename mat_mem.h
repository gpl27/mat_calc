// Declares everything related to memory management of storing a matrix

#ifndef MAT_MEM_H
#define MAT_MEM_H

// Max number of matrices that can be stored 
#define MAX 20

// Custom type for holding a matrix
// Includes the number of rows and columns
// as well as a pointer to the location in memory
typedef struct mat
{
    int row;
    int col;
    int **ptr;
}
matrix;

// Global array of matrices
extern matrix All[MAX];

// Allocates necessary amount of memory according to matrix size
// Retruns All[] index where mem was alloced if successfull
// Returns a negative number if it fails to allocate
int alloc_mem(int row, int col);

// Free the memory used by all matrices (deletes everything)
void free_All(void);

// Free a specific matrix (deletes one matrix)
// It takes no argument, since this function is only used by the user
// So it incorporates taking input for the All index
void free_mat(void);

// Checks for a matrices existence, takes in the number matrices to check
// It is also used as the main way to get input from the user about a specific
// matrix
// Will return NULL if ANY of the matrices it checks does not exist
// If ALL exist, it returns an array with the All indices
// IMPORTANT: the array that is returned MUST be freed
int *check_mat(int n);

#endif