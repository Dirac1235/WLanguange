#include "../../include/hash_table.h"

/**
 * hash_table_create - it creates hash table
 * @size: the size of the hash table
 *
 * Return: hash table with the given size
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *table = NULL;

	if (size == 0)
		return (NULL);

	table = malloc(sizeof(hash_table_t));

	if (table == NULL)
		return (NULL);

	table->size = size;
	table->array = malloc(sizeof(hash_node_t *) * size);

	if (table->array == NULL)
		return (NULL);

	return (table);
}

/**
 * hash_table_set - inserts data into the hash table
 * @ht: the hashtable which we insert data into
 * @key: the data to be translated to index by the hash function
 * @value: is the data that is ascociated with the key
 *
 * Return: 1 if success 0 if not
 */
int hash_table_set(hash_table_t *ht, const char *key, Object *value)
{
	unsigned long int index;
	hash_node_t *new_node = NULL;
	hash_node_t *current_node = NULL;

	if (ht == NULL || key == NULL || value == NULL || strcmp(key, "") == 0)
		return (0);

	index = key_index((unsigned char *)key, ht->size);
	current_node = ht->array[index];

	for (; current_node != NULL; current_node = current_node->next)
	{
		if (strcmp(current_node->key, key) == 0)
		{
			current_node->value = value;
			return (1);
		}
	}

	new_node = c_node(key, value);
	if (new_node == NULL)
		return (0);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}

/**
 * c_node - function that creates a new_node node.
 * @key: pointer to key.
 * @value: pointer to value of the key.
 *
 * Return: pointer to new_node node else NULL.
 */
hash_node_t *c_node(const char *key, Object *value)
{
	hash_node_t *new_node;

	if (key == NULL || strcmp(key, "") == 0 || value == NULL)
		return (NULL);

	new_node = malloc(sizeof(hash_node_t));

	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);

	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->value = value;

	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}

	new_node->next = NULL;
	return (new_node);
}

/**
 * hash_table_get - retrieves a value associated with a key.
 * @ht: hash table which we retrieve the value from
 * @key: the key which we find the value
 *
 * Return: NULL if ke not found else value associated with the key
 */
Object *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *current_node = NULL;

	if (ht == NULL || key == NULL || strcmp(key, "") == 0)
		return (0);

	index = key_index((unsigned char *)key, ht->size);
	current_node = ht->array[index];

	if (current_node == NULL)
		return (NULL);

	for (; current_node != NULL; current_node = current_node->next)
	{
		if (strcmp(current_node->key, key) == 0)
			return (current_node->value);
	}
	return (NULL);
}

/**
 * hash_table_print - prints a hash table.
 * @ht: hash table
 *
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node = NULL;
	unsigned long int j;
	int n = 0;

	if (ht == NULL)
		return;
	printf("{");
	for (j = 0; j < ht->size; j++)
	{
		node = ht->array[j];
		if (node == NULL)
			continue;
		for (; node != NULL; node = node->next)
		{
			printf("%s'%s': '%s'", n == 0 ? "" : ", ",
						 node->key, format_obj(node->value)),
					n++;
			n++;
		}
	}
	printf("}\n");
}
/**
 * format_obj - prints the data in object
 * @obj: object to be printed
 */
char *format_obj(Object *obj)
{
	if (!obj)
		return NULL;

	char *hold = malloc(128);
	if (!hold)
		return NULL;

	switch (obj->type)
	{
	case TYPE_INT:
		snprintf(
				hold,
				128,
				"int : %d ",
				obj->data.i);
		break;
	case TYPE_DOUBLE:
		snprintf(
				hold,
				128,
				"double : %f ",
				obj->data.d);
		break;
	case TYPE_STR:
		snprintf(
				hold,
				128,
				"string : %s ",
				obj->data.s);
		break;
	default:
			fprintf(stderr, "Unknown type");
			exit(1);
	}

	return hold;
}
/**
 * hash_table_delete - deletes a hash table.
 * @ht: hash table to be deleted
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int j;
	hash_node_t *holder = NULL;
	hash_node_t *node = NULL;

	if (ht == NULL)
		return;

	for (j = 0; j <= ht->size; j++)
	{
		node = ht->array[j];
		if (node == NULL)
			continue;
		while (node)
		{
			holder = node;
			node = holder->next;
			free(holder->key);

			if (holder->value->data.s)
				free(holder->value->data.s);
			free(holder);
		}
		free(node);
	}
	free(ht->array);
	free(ht);
}
