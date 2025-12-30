#ifndef HELPER_H_
#define HELPER_H_


FILE* input_accept(int argc, char **argv);
Object *makeObj(ObjectType type);

char *concat(char *left, char *right);
char *mul_str(char *s, int val);
Object *isTrue(Object *obj);
bool is_number(Object *o);
bool is_str(Object *o);


char *tt_to_str(TokenType type);
char *nt_to_str(NODE_TYPE type);
char *ot_to_str(ObjectType type);


#endif 