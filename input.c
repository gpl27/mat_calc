// Definitions for "input.h"
#include "input.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Safe way to get integer from user
// Big thanks to http://sekrit.de/webdocs/c/beginners-guide-away-from-scanf.html
// for the great explanation
int get_int(char *text)
{
    int a;
    char *buf = malloc(sizeof(char) * 1024);
    // Flag for successful conversion of string to integer
    int success;

    do
    {
        // Prints the string provided by the caller
        printf("%s", text);
        if (!fgets(buf, 1024, stdin))
        {
            // fgets() failed
            printf("\n///// Input Error: fgets() failed /////\n\n");
            return 1;
        }

        // Convert the string input by the user into integer
        char *endptr;

        // Reset the error number
        errno = 0;
        a = strtol(buf, &endptr, 10);
        if (errno == ERANGE)
        {
            printf("\n/// Input Error: number too big or too small ///\n\n");
            success = 0;
        }
        else if (endptr == buf)
        {
            // No character was read (no number in the string)
            printf("\n/// Input Error: no character read ///\n\n");
            success = 0;
        }
        else if (*endptr && *endptr != '\n')
        {
            // *endptr is neither end of string nor newline,
            // so we didn't convert the *whole* input
            // Text with numbers was input
            printf("\n/// Input Error: couldn't convert whole input ///\n\n");
            success = 0;
        }
        else
        {
            success = 1;
        }
    } 
    while (!success);
    // Repeat until a valid number is input
    free(buf);
    return a;
}

// Safer way to get strings from user
char *get_string(char *text)
{
    printf("%s", text);
    char *string = malloc(sizeof(char) * 1024) ;
    fgets(string, 1024, stdin);
    int i = 0;
    while (string[i] != 0)
    {
        if (string[i] == '\n')
        {
            string[i] = 0;
            break;
        }
        i++;
    }
    return string;
}

// Safe way to get a positive integer (0+) 
// Just uses get_int() and checks
int get_pint(char *text)
{
    int a;
    do
    {
        a = get_int(text);
        if (a < 0)
        {
            printf("\n/// Input Error: expected n >= 0 ///\n\n");
        }
    } while (a < 0);
    return a;
}