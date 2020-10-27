// Declares everything related to input and output of matrices
// meaning input of matrix from user and printing to the terminal

#ifndef MAT_IO_H
#define MAT_IO_H

// Gets a matrix through the command-line
// User must input one row at a time from left to right, top to bottom
void get_mat(void);

// Print a specific matrix with padding
void print_mat(int n);

// Formatted print of a matrix (for output of operations)
void fprint_mat(int n);

#endif