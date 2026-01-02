#ifndef HELPER_H_
#define HELPER_H_

#include "global.h"

#define TABLE_SIZE 128

FILE* input_accept(int argc, char **argv);



Object *makeObj(ObjectType type);

typedef struct Symbol {
    char *name;
    int value; // Or a pointer to a more complex Value struct
    struct Symbol *next;
} Symbol;

typedef struct Environment {
    hash_table_t *table;
    struct Environment *parent;
} Environment;

char *concat(char *left, char *right);
char *mul_str(char *s, int val);
Object *is_true(Object *obj);
bool is_number(Object *o);
bool is_str(Object *o);


char *tt_to_str(TokenType type);
char *nt_to_str(NODE_TYPE type);
char *ot_to_str(ObjectType type);

Environment *create_env(Environment *parent);
Object *env_get(Environment *env, char *key);
void env_assign(Environment *env, char *name, Object *value);
void free_env(Environment *env);



#endif 