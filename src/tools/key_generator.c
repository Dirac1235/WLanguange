#include "../../include/hash_table.h"

/**
 * hash_djb2 - implementation of the djb2 algorithm
 * @str: string used to generate hash value
 *
 * RETURN: hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}

/**
 * key_index - creates index from key given by the hash function
 * @size: size of the hash table to be created
 * @key: the value to be converted to an index
 *
 * RETURN: the index of given key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_result;

	hash_result = hash_djb2(key);
	return (hash_result % size);
}
