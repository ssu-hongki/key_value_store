#include <stdlib.h>
#include "kvs.h"

int random_level(){
	int level = 1;
	while(rand()%2 && level < MAX_LEVEL){
		level++;
	}
	return level;
}
