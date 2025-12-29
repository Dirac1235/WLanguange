#include "../../include/global.h"

FILE* input_accept(int argc, char **argv)
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

Object *makeObj(ObjectType type)
{
  Object *obj = (Object *)malloc(sizeof(Object));
  obj->type = type;
  return obj;
}

char *concat(char *left, char *right) {
  size_t t_len = strlen(left) + strlen(right);
  char *hold = malloc(sizeof(char) * t_len);
  snprintf(hold, t_len, "%s%s", left, right);
  return hold;
}