#include "kvs.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int put(kvs_t* kvs, const char* key, const char* value)
{
//	printf("put: %s, %s\n", key, value);

	/* do program here */
	if(!kvs || !key || !value) return -1;

	node_t* update[MAX_LEVEL];
	node_t* current = kvs->head;

	for(int level = MAX_LEVEL - 1; level >= 0; level--){
		while(current->next[level] && strcmp(current->next[level]->key,key) < 0){
			current = current->next[level];
		}
		update[level] = current;
	}
	current = current->next[0];

	if(current && strcmp(current->key,key) == 0){
		free(current->value);
		current->value = strdup(value);
		return 0;
	}
	int level = random_level();
	node_t* new_node = malloc(sizeof(node_t));
	if(!new_node) return -1;

	strcpy(new_node->key,key);
	new_node->value = strdup(value);
	new_node->level = level;

	for(int i=0;i<level;i++){
		new_node->next[i] = update[i]->next[i];
		update[i]->next[i] = new_node;
	}
	kvs->items++;



	return 0;
}
