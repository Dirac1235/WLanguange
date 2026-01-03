#include "../../include/global.h"

/**
 * input_accept - accepts input from the command line
 * @intc: length of the arguments
 * @argv: arguments
 *
 * RETURN: File
 */
FILE *input_accept(int argc, char **argv)
{
  char *file_path;
  char *arguments;
  char *path_tok;
  char **path;
  char *file_name;
  char *ext_tok;
  char **ext_arr;

  FILE *fp;

  int p_count = 0;
  int f_count = 0;

  if (argc < 2)
  {
    fprintf(stderr, "Usage: wlang -[args] [./location/to/filename].wl");
    exit(0);
  }
  if (argc == 3)
  {
    arguments = argv[1];
    file_path = argv[2];
  }
  else
  {
    file_path = argv[1];
  }
  char *path_cpy = strdup(file_path);
  path_tok = strtok(path_cpy, "/");

  path = malloc(sizeof(char *) * 200);
  while (path_tok != NULL)
  {
    path[p_count++] = path_tok;
    path_tok = strtok(NULL, "/");
  }

  file_name = path[p_count - 1];
  ext_tok = strtok(file_name, ".");
  ext_arr = malloc(sizeof(char *) * 10);

  while (ext_tok != NULL)
  {
    ext_arr[f_count++] = ext_tok;
    ext_tok = strtok(NULL, ".");
  }

  if (strcmp(ext_arr[f_count - 1], "w") != 0)
  {
    fprintf(stderr, "Unknown Extension: %s \n", ext_arr[f_count - 1]);
    exit(0);
  }

  fp = fopen(file_path, "r");
  return fp;
}

/**
 * makeObj - initializes object type with type
 * @type: type of the object
 *
 * RETURN: Object with initalized type
 */
Object *makeObj(ObjectType type)
{
  Object *obj = (Object *)malloc(sizeof(Object));
  obj->type = type;
  return obj;
}

/**
 * concat - concatenates two strings together
 * @left: the left character to be concatenated
 * @right: the right character to be concatenated
 *
 * RETURN:concatenated String
 */
char *concat(char *left, char *right)
{
  size_t t_len = strlen(left) + strlen(right);
  char *hold = malloc(sizeof(char) * (t_len + 1));
  snprintf(hold, t_len + 1, "%s%s", left, right);
  return hold;
}

/**
 * mul_str - multiplies string with integer
 * @s: string to be multiplied
 * @val: the mulitplier
 *
 * RETURN: multiplied string
 */
char *mul_str(char *s, int val)
{
  char *res = "";
  while (val > 0)
  {
    res = concat(res, s);
    val--;
  }
  return res;
}

Object *is_true(Object *obj)
{
  Object *bobj = makeObj(TYPE_BOOL);
  bool val = false;
  if (obj->type == TYPE_INT)
  {
    if (obj->data.i != 0)
      val = true;
    else
      val = false;
  }
  else if (obj->type == TYPE_DOUBLE)
  {
    if (obj->data.d != 0)
      val = true;
    else
      val = false;
  }
  else if (obj->type == TYPE_STR)
  {
    if (strcmp(obj->data.s, "") != 0)
      val = true;
    else
      val = false;
  }
  else if (obj->type == TYPE_BOOL)
  {
    if (obj->data.b == true)
      val = true;
    else
      val = false;
  }
  bobj->data.b = val;
  return bobj;
}

bool is_number(Object *o)
{
  return o->type == TYPE_INT || o->type == TYPE_DOUBLE;
}
bool is_str(Object *o)
{
  return o->type == TYPE_STR;
}

bool is_truthy(Object *obj) {
    if (obj == NULL) return false;

    switch (obj->type) {
        case TYPE_INT:    return obj->data.i != 0;
        case TYPE_DOUBLE: return obj->data.d != 0.0;
        case TYPE_BOOL:   return obj->data.b;
        case TYPE_STR:    
            return (obj->data.s != NULL && obj->data.s[0] != '\0');
        default:
            return false; // Unknown types are false
    }
}

/**
 * create_env - creates environment for the block
 * @parent: the parent symbol table
 *
 * RETURN: new environment
 */
Environment *create_env(Environment *parent)
{
  Environment *env = (Environment *)malloc(sizeof(Environment));
  env->table = hash_table_create(TABLE_SIZE);
  env->parent = parent;
  return env;
}

Object *env_get(Environment *env, char *key)
{
  while (env != NULL)
  {
    Object *obj = hash_table_get(env->table, key);
    if (obj)
      return obj;
    env = env->parent;
  }
  return NULL;
}

void env_assign(Environment *env, char *name, Object *value)
{
  while (env != NULL)
  {
    Object *obj = hash_table_get(env->table, name);
    if (obj != NULL)
    {
      hash_table_set(env->table, name, value);
      break;
    }
    env = env->parent;
  }
}

void free_env(Environment *env)
{
  if (env == NULL)
  {
    fprintf(stderr, "Error while freeing memory NULL environment");
    exit(1);
  }
  if (env->table != NULL)
  {
    hash_table_delete(env->table);
  }
}

/**
 * tt_to_str - change TokenType to string
 * @type: Token Type
 *
 * RETURN: type name
 */

char *tt_to_str(TokenType type)
{
  switch (type)
  {
  case TKN_LITERAL:
    return "Literal";
  case TKN_STRING:
    return "String";
  case TKN_INT:
    return "Int";
  case TKN_DOUBLE:
    return "Double";
  case TKN_OP_ADD:
    return "+";
  case TKN_OP_SUB:
    return "-";
  case TKN_OP_MUL:
    return "*";
  case TKN_OP_DIV:
    return "/";
  case TKN_OP_MOD:
    return "%%";

  case TKN_OP_TRUE:
    return "true";
  case TKN_OP_FALSE:
    return "false";

  case TKN_OP_BANG_EQUAL:
    return "!=";
  case TKN_OP_EQUALEQUAL:
    return "==";
  case TKN_OP_GREATEREQUAL:
    return ">=";
  case TKN_OP_LESSEQUAL:
    return "<=";
  case TKN_OP_LESS:
    return "<";
  case TKN_OP_GREATER:
    return ">";
  case TKN_OP_OR:
    return "or";
  case TKN_OP_AND:
    return "and";

  default:
    fprintf(stderr, "Unknown TokenType\n");
    exit(1);
  }
}

char *nt_to_str(NODE_TYPE type)
{
  switch (type)
  {
  case EXPR_BINARY:
    return "Binary";
  case EXPR_UNARY:
    return "Unary";
  case EXPR_GROUP:
    return "Group";
  case EXPR_TOKEN:
    return "Token";
  case STMT_PRINT:
    return "Print";
  case STMT_DECL:
    return "Statment";
  case STMT_INT:
    return "Integer";
  case STMT_DOUBLE:
    return "Double";
  case STMT_STR:
    return "String";
  case STMT_BOOL:
    return "Bool";
  case STMT_ASS:
    return "Assignment";
  case STMT_IFELSE:
    return "If";
  default:
    fprintf(stderr, "Unknown NodeType\n");
    exit(1);
  }
}
char *ot_to_str(ObjectType type)
{
  switch (type)
  {
  case TYPE_INT:
    return "type int";
  case TYPE_DOUBLE:
    return "type double";
  case TYPE_STR:
    return "type string";
  case TYPE_BOOL:
    return "type bool";
  default:
    fprintf(stderr, "Unknown ObjectType\n");
    exit(1);
  }
}