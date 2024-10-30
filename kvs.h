#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define MAX_LEVEL 6


typedef struct node {
	char key[100];
	char* value;
	//struct node* next;
	struct node* next[MAX_LEVEL];
	int level;
} node_t;	


typedef struct kvs{
	struct node* head; // database
	int items; // number of data 
} kvs_t;


kvs_t* open();
int close(kvs_t* kvs); // free all memory space 
int put(kvs_t* kvs, const char* key, const char* value); // return -1 if failed.
char* get(kvs_t* kvs, const char* key); // return NULL if not found. 
int random_level();


