#ifndef HELPER_H_
#define HELPER_H_



/**
 * input_accept - accepts command line args and process it
 * @argc: The length of the command line arg
 * @argv: List containing hte command line args
 * RETURN: Void
 */

FILE* input_accept(int argc, char **argv);
char *itoa(long double val);
Object *makeObj(ObjectType type);
char *concat(char *left, char *right);



#endif