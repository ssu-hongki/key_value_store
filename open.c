#include "kvs.h"
#include <stdlib.h>

kvs_t* open()
{
	kvs_t* kvs = (kvs_t*) malloc (sizeof(kvs_t));
	if(!kvs){
		printf("Failed to allocate memory for kvs\n");
		return NULL;
	}
	if(kvs)
		kvs->items = 0;
	
	
	kvs->head = (node_t*)malloc(sizeof(node_t));
        if (!kvs->head) {
		printf("Failed to allocate memory for head node\n");
		free(kvs);
		return NULL;
	}

	kvs->head->level = MAX_LEVEL;
	for (int i = 0; i < MAX_LEVEL; i++) {
		kvs->head->next[i] = NULL;
	}
	kvs->items = 0;

	printf("Open: kvs has %d items\n", kvs->items);
	return kvs;
}
