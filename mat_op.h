// Declares all matrix operations (multiplication, addition, etc) 

#ifndef MAT_OP_H
#define MAT_OP_H

// Adds or subtracts two matrices and stores sum/difference in a third matrix
// Addition -> op = 1
// Subtraction -> op = 0
// (A + B) = C
void add_sub_mat(int op);

// Sums n matrices
// (A + B + ... + F) = G
void sum_mat(void);

// Multiplies two matrices and stores product in a third matrix
// A(mxn)  x  B(nxp) = C(mxp) 
void mult_mat(void);

// Multiplies a matrix by k
// k(A) = B
void multk_mat(void);

// Transposes a matrix
// A(mxn) = B(nxm)
void transpose_mat(void);

#endif