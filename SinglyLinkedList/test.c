#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct list_node_tag {
  void *value;
  struct list_node_tag *next;
} list_node;

typedef list_node *(*list_node_create)();
typedef void (*list_node_delete)(list_node *node);

typedef struct list_tag {
  list_node *root;
  list_node_delete deleter;
} list;

typedef void (*list_unary_function)(list_node *node, void *accum);
typedef void (*list_binary_function)(list_node *left, list_node *right);

/* TODO: implement these functions. */
list_node *list_create(list_node_create, list_node_delete);
void list_append(list *list, void *node_value);
void list_prepend(list *list, void *node_value);
int  list_size(list *list);
void list_for_each(list *list, list_unary_function function, void *initial);

void list_delete(list *list) {
 list->deleter(list->root);
}

/* Start example test code. */
typedef struct my_node_tag {
  int length;
  char *string;
} my_node;

list_node *create_node() {
  return (list_node *)malloc(sizeof(my_node));
}

my_node *create_node_arg(const char *text) {
  my_node *node = malloc(sizeof(my_node));
  memset(node, 0, sizeof(my_node));
  if (text == NULL) {
    return node;
  }
  node->length = strlen(text);
  node->string = malloc(node->length);
  memcpy(node->string, text, node->length);
  return node;
}

void delete_node(list_node *input) {
  my_node *node = (my_node *)(input);
  free(node->string);
  node->string = NULL;
}

typedef struct string_concate_result_tag {
  char *result;
} concatenate_result;

void concatenate_string(list_node *vfirst, void *accumulator) {
  my_node *first = (my_node *)vfirst;
  concatenate_result *accum = (concatenate_result *)accumulator; 

  accum->result = strcat(first->string, accum->result);
}

int main() {
  list *list = list_create(create_node, delete_node);

  list_append(list, create_node(", world"));
  list_prepend(list, create_node("hello"));

  concatenate_result *result = malloc(sizeof(concatenate_result));
  memset(result, 0, sizeof(concatenate_result));

  list_for_each(list, concatenate_string, result);
    
  assert(list_size(list) == 2);
  assert(strcmp(result->result, "hello, world") == 0);

  return 0;
}

