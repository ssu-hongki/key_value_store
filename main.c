#include "kvs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	kvs_t* kvs = open();

	if(!kvs) {
		printf("Failed to open kvs\n");
		return -1;
	}

	// workload execution  
	
	// 1) 	file read 
	// 2) 	if put, insert (key, value) into kvs.
	// 		if get, seach the key in kvs and return the value. 
	//		Return -1 if the key is not found  

	FILE *input = fopen("query.dat","r");
	FILE *output = fopen("answer.dat","w");
	if(!input || !output){
		printf("Failed to open file\n");
		close(kvs);
		if(input) fclose(input);
		if(output) fclose(output);
		return -1;
	}

	char line[256];
	while(fgets(line,sizeof(line),input)){
		char command[10], key[100], value[100];
		int result;

		command[0] = key[0] = value[0] = "";

		int num_tokens = sscanf(line,"%9[^,],%99[^,],%99s",command,key,value);


		if(num_tokens < 2){
			printf("Invaild input format: %s\n",line);
			continue;
		}


		if(strcmp(command, "set") == 0 && num_tokens == 3){
			result = put(kvs,key,value);
			if(result==-1){
				fprintf(output, "Failed to put : %s\n",key);
			}
		}
		else if(strcmp(command,"get") == 0 && num_tokens >= 2){
			char* value_get = get(kvs,key);
			if(value_get){
				fprintf(output,"%s\n",value_get);
				free(value_get);
			}
			else{
				fprintf(output,"-1\n");
			}
		}
		else{
			printf("Unknown command\n");
		}
	}
	fclose(input);
	fclose(output);

	close(kvs);
	
	return 0;
}
