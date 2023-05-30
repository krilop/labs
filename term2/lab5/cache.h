//
// Created by krilop on 5/26/23.
//

#ifndef _CACHE_H_
#define _CACHE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
typedef struct Node {

    char* key;
    char* value;

    struct Node* next;
    struct Node* prev;
    struct Node* collision;

} Node;

typedef struct HashTable {

    int capacity;
    Node** values;

} HashTable;

typedef struct {

    int size;
    int capacity;

    Node* head;
    Node* tail;

} List;

typedef struct {

    HashTable* hashtable;
    List* list;

} Cache;


int hashFunction(const char *key, int capacity);
Node* createNode(char* key, char* value);
List* createList(int capacity);
HashTable* createHashTable(int size);
Cache* createCache(int size);
char* get(Cache *cache, char* key);
void printCache(Cache* cache);
void findInFile(Cache* cache, char* string, FILE* in);
void destroyCache(Cache* cache);
#endif //_CACHE_H_
