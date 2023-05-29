//
// Created by krilop on 5/26/23.
//

#include "cache.h"

int hashFunction(const char *key, int capacity)
{
    int hash = 0;
    int i=0;
    while ( key[i]!=NULL)
    {
        hash = hash + key[i];
        i++;
    }
    return hash % capacity;
}

Node* createNode(char* key, char* value) {

    Node* node = (Node*)malloc(sizeof(Node));

    node->key = key;
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    node->collision = NULL;

    return node;

}

List* createList(int capacity) {

    List* list = (List*)malloc(sizeof(List));

    list->size = 0;
    list->capacity = capacity;
    list->head = list->tail = NULL;

    return list;

}

HashTable* createHashTable(int size) {

    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));

    hashTable->capacity = size;
    hashTable->values = (Node**)malloc(sizeof(Node) * size);

    for (int i = 0; i < size; i++) hashTable->values[i] = NULL;

    return hashTable;

}

Cache* createCache(int size) {

    Cache* cache = (Cache*)malloc(sizeof(Cache));
    HashTable* hashTable = createHashTable(size * 2);
    List* list = createList(size);

    cache->hashtable = hashTable;
    cache->list = list;

    return cache;

}

void cacheShift(Cache* cache, char* key) {

    List* list = cache->list;
    if (list->size == 1) return;
    Node* curr = cache->hashtable->values[hashFunction(key,HASH_TABLE_SIZE)];
    while (curr) {

        if (strcmp(curr->key, key) == 0) break;
        curr = curr->collision;
    }
    if (curr == NULL) return;
    if (curr->prev == NULL) {
        curr->prev = list->tail;
        list->head = curr->next;
        list->head->prev = NULL;
        list->tail->next = curr;
        list->tail = curr;
        list->tail->next = NULL;
        return;
    }
    if (curr->next == NULL) return;
    curr->next->prev = curr->prev;
    curr->prev->next = curr->next;
    curr->next = NULL;
    list->tail->next = curr;
    curr->prev = list->tail;
    list->tail = curr;

}

char* get(Cache* cache, char* key)
{
    Node* needle=cache->hashtable->values[hashFunction(key,HASH_TABLE_SIZE)];

    while(needle)
    {
        if(strcmp(needle->key, key)==0)
        {
            cacheShift(cache,key);
            return needle->key;
        }
        needle=needle->collision;
    }
    return NULL;
}

void findInFile(Cache* cache, char* string, file in)
{
    char*buffer;
    char* answer;
    fseek(in.file,0,SEEK_SET);
    while((buffer=readLineFromFile(in))!=NULL)
    {
        if(strstr(string,buffer)!=NULL)
        {
            if(strstr(INA,buffer)!=NULL&&strstr(string,buffer)==buffer)
            {
                put(cache,strdup(strchr(buffer,' ')));
                return;
            }
            if(strstr("IN CNAME",buffer)!=NULL&&strstr(string,buffer)==buffer)
            {
                findInFile(cache,strchr(buffer,' '),in);
                return;
            }
        }
    }
    return;
}