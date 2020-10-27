# Matrix Calculator
## Basics
This is a command-line matrix calculator written in C. To install simply
open a terminal window and change to the source code directroy and 
type `make` 

It allows users to:
- Add matrices
- Subtract matrices
- Multiply matrices
- Multiply a matrix by an integer
- Transpose a matrix

By typing 'help' upon starting the program you'll see a list with all
the available commands. To input a matrix, use the command `get`. 
It will first prompt you for the dimensions of the matrix.
Then, it'll prompt you all the values, one by one, and you must enter 
it, starting on the first row, left to right, top to bottom.

Since the result of any operation is stored on a new matrix, it is possible
to add, subtract, multiply(if applicable) any matrix by itself. There is a
`sum` function that allows the addition of `n` matrices, and theses could
be the same matrix.

## How Matrices are stored in memory
Since I wanted to have multiple matrices of different orders available at
the same time, I opted for a global array called 'All' of custom type
matrix.
```
#define MAX 20

typedef struct mat
{
    int row;
    int col;
    int **ptr;
}
matrix;

extern matrix All[MAX];
```
The pointer to an int pointer `(int **ptr)` points to an array of pointers
with a length equal to the number of rows of the matrix. Each element of
this array of pointers holds one row of the matrix. This allows me to use
syntax like `All[i].ptr[j][k]` and was just easier to visualise when 
considering the other options I had.

## Header Files
When I first started writing this, I was just on week 3 or 4 of CS50 and
wasn't aware of how quickly things could grow. When my .c file got to 500
lines I realized it was time to break things up. I ended up spliting
everything into 6 source files:

- mat.c has `main()` and `user_input()` that handles interpreting
comman-lin prompts
- mat_mem.c takes care of implementing memory related details, so
allocating the right amount of space, freeing up memory, checking for
matrices existence, and handling memory related errors
- mat_io.c contains the functions to get matrices from the user and to
print matrices to the terminal
- mat_op.c handles all (almost all) the operations cited above in 'Basics'
- mat_misc.c has miscellaneous functions whose main purpose were helping
to test the program for errors. 
- input.c contains functions for getting strings and integers in a safe and
error free way

Since the number of files grew quite a bit, I made a makefile to make the
debug, compile, test process faster.


---

## Future support for determinant and inverse?
I planned on adding a way to calculate the determinant and the inverse, 
but half way through I realised I didn't know enough math to do it. I tried
reading the Wikipedia page to see if I could wing it, but it just didn't
happen. Anyway, maybe someday I'll come back and implement it.
