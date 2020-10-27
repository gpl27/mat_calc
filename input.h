// Declares functions for safe input of strings and integers by the user

#ifndef INPUT_H
#define INPUT_H

// Safe way to get integer from user
// Takes in a string to print as a prompt
int get_int(char *text);

// Safe way to get positive integer from user
// Takes in a string to print as a prompt
int get_pint(char *text);

// Safer way to get a string from the user
// Takes in a string to print as a prompt
// The string (or rather pointer) that is returned MUST be freed
char *get_string(char* text);

#endif