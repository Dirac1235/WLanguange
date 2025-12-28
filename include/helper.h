#ifndef HELPER_H
#define HELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * input_accept - accepts command line args and process it
 * @argc: The length of the command line arg
 * @argv: List containing hte command line args
 * RETURN: Void
 */
FILE* input_accept(int argc, char **argv);

#endif