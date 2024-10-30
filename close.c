#include "kvs.h"

int close(kvs_t* kvs)
{
	/* do program */
	if(!kvs) return -1;
	node_t* current = kvs->head;
	while(current){
		node_t* next = current->next[0];
		if(current->value) free(current->value);
		free(current);

		current = next;
	}
	free(kvs);
	return 0;
}
