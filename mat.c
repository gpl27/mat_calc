// This is a simple general-purpose matrix calculator
#include "mat_mem.h"
#include "mat_io.h"
#include "mat_op.h"
#include "mat_misc.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Global array of matrices
matrix All[MAX];

// Interprets user input
void user_input(void);

int main(void)
{
    // Sets all matrices in All to NULL
    for (int i = 0; i < MAX; i++)
    {
        All[i].ptr = NULL;
    }
    printf("// Matrix Calculator\n");
    printf("// Memory Locations Available: %i\n", MAX);
    printf("// Type 'help' for more information.\n");
    // Gets input and determines what function to call
    user_input();
    // Frees all matrices at exit
    printf("Exiting...\n");
    free_All();
    return 0;
}

// Interprets user input
// This function is on big if statement that handles the commands
void user_input(void)
{
    char *string;
    do
    {
        string = get_string(">> ");
        if (!strcasecmp(string, "help"))
        {
            printf("// HELP:\n");
            printf("// get    ==== Gets a matrix by user input (left to right/top to bottom)\n");
            printf("// del    ==== Deletes a matrix stored at location 'i'\n");
            printf("// delall ==== Deletes all matrices currently stored in memory\n");
            printf("// mem    ==== Prints all locations in memory where there is a matrix\n");
            printf("// print  ==== Prints a matrix stored at location 'i'\n");
            printf("// exit   ==== Deletes all matrices and exits the program\n");
            printf("// add    ==== Adds two matrices\n");
            printf("// sub    ==== Subtracts two matrices\n");
            printf("// sum    ==== Sums 'n' matrices\n");
            printf("// mult   ==== Multiplies two matrices\n");
            printf("// multk  ==== Multiplies a matrix by 'k' (int)\n");
            printf("// trans  ==== Transposes a matrix\n");
            printf("// id     ==== Creates an identity matrix of order 'n'\n");
            printf("// copy   ==== Creates a copy of a matrix\n");

        }
        else if (!strcasecmp(string, "get"))
        {
            get_mat();
        }
        else if (!strcasecmp(string, "del"))
        {
            free_mat();
        }
        else if (!strcasecmp(string, "delall"))
        {
            free_All();
        }
        else if (!strcasecmp(string, "mem"))
        {
            printf("\nIn Memory:\n");
            // Counts how many matrices are in use and print their location
            int counter = 0;
            for (int i = 0; i < MAX; i++)
            {
                if (All[i].ptr != NULL)
                {
                    printf("%i ", i);
                    counter++;
                }
            }
            printf("\nMemory Locations Available: %i", MAX - counter);
            printf("\n\n");
        }
        else if (!strcasecmp(string, "add"))
        {
            add_sub_mat(1);
        }
        else if (!strcasecmp(string, "sub"))
        {
            add_sub_mat(0);
        }
        else if (!strcasecmp(string, "sum"))
        {
            sum_mat();
        }
        else if (!strcasecmp(string, "mult"))
        {
            mult_mat();
        }
        else if (!strcasecmp(string, "multk"))
        {
            multk_mat();
        }
        else if (!strcasecmp(string, "trans"))
        {
            transpose_mat();
        }
        else if (!strcasecmp(string, "print"))
        {
            // Asks for index and check existence
            int *mats = check_mat(1);
            if (mats == NULL)
            {
                continue;
            }
            int loc = mats[0];
            free(mats);
            printf("\n");
            print_mat(loc);
        }
        else if (!strcasecmp(string, "copy"))
        {
            copy_mat();
        }
        else if (!strcasecmp(string, "id"))
        {
            id_mat();
        }
        else if (!strcasecmp(string, "exit"))
        {
            free(string);
            break;
        }
        else
        {
            printf("\n/// Invalid Command ///\n\n");
        }
        free(string);
    }
    while (1);
    // Will loop until user decides to close program
    return;
}