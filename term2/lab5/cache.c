//
// Created by krilop on 5/26/23.
//

#include "cache.h"
#include "functions.h"

int hashFunction(const char *key, int capacity)
{
    int hash = 0;
    int i = 0;
    while (key[i] != '\0')
    {
        hash = hash + key[i];
        i++;
    }
    return hash % capacity;
}

Node *createNode(char *key, char *value)
{

    Node *node = (Node *) malloc(sizeof(Node));

    node->key = key;
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    node->collision = NULL;

    return node;

}

List *createList(int capacity)
{
    List *list = (List *) malloc(sizeof(List));
    list->size = 0;
    list->capacity = capacity;
    list->head = list->tail = NULL;
    return list;
}

HashTable *createHashTable(int size)
{
    HashTable *hashTable = (HashTable *) malloc(sizeof(HashTable));
    hashTable->capacity = size;
    hashTable->values = (Node **) malloc(sizeof(Node) * size);
    for (int i = 0; i < size; i++) hashTable->values[i] = NULL;
    return hashTable;
}

Cache *createCache(int size)
{
    Cache *cache = (Cache *) malloc(sizeof(Cache));
    HashTable *hashTable = createHashTable(size);
    List *list = createList(size);
    cache->hashtable = hashTable;
    cache->list = list;
    return cache;
}


void removeOldest(Cache *cache) {

    HashTable *table = cache->hashtable;
    List *list = cache->list;

    Node *entry = list->head;

    if (list->head == NULL)
        return;

    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
    } else {
        list->head = entry->next;
        list->size = list->size - 1;
        list->head->prev = NULL;
    }

    Node **node = &table->values[hashFunction(entry->key,table->capacity)];
    while ((*node) != entry)
        node = &(*node)->next;
    *node = entry->next;
    free(entry);
}


void cacheShift(Cache *cache, char *key)
{
    List *list = cache->list;
    if (list->size == 1) return;
    Node *curr = cache->hashtable->values[hashFunction(key, HASH_TABLE_SIZE)];
    while (curr)
    {
        if (strcmp(curr->key, key) == 0) break;
        curr = curr->collision;
    }
    if (curr == NULL) return;
    if (curr->prev == NULL)
    {
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

char *get(Cache *cache, char *key)
{
    Node *needle = cache->hashtable->values[hashFunction(key, HASH_TABLE_SIZE)];

    while (needle)
    {
        if (strcmp(needle->key, key) == 0)
        {
            cacheShift(cache, key);
            return needle->value;
        }
        needle = needle->collision;
    }
    return NULL;
}

void printCache(Cache *cache)
{
    Node *temp = cache->list->head;

    for (int i = cache->list->size - 1; i >= 0; i--)
    {
        printf("[%d] %s %s \n", i + 1, temp->key, temp->value);
        temp = temp->next;

    }

}

void addToList(Cache *cache, Node *node) {

    List *list = cache->list;

    if (list->size == list->capacity) removeOldest(cache);

    if (list->head == NULL) {
        list->head = list->tail = node;
        list->size = 1;
        return;
    }

    node->prev = list->tail;
    list->tail->next = node;
    list->tail = node;
    list->size = list->size + 1;
}

int addToTable(HashTable *table, Node *node) {

    if (table->values[hashFunction(node->key,table->capacity)] != NULL) {

        Node *curr = table->values[hashFunction(node->key,table->capacity)];

        while (curr->collision != NULL) {
            if (strcmp(curr->key, node->key) == 0) {
                curr->value = node->value;
                return 1;
            }
            curr = curr->collision;
        }

        if (strcmp(curr->key, node->key) == 0) {
            curr->value = node->value;
            return 1;
        }

        curr->collision = node;
        return 0;
    } else {
        table->values[hashFunction(node->key,table->capacity)] = node;
        return 0;
    }
}

void put(Cache *cache, char *key, char *value)
{
    Node *node = createNode(key, value);
    if (addToTable(cache->hashtable, node))
        cacheShift(cache, node->key);
    else
        addToList(cache, node);
}

void findInFile(Cache *cache, char *string, FILE *in)
{
    char *buffer;
    char* answer;
    fseek(in, 0, SEEK_SET);
    while (!feof(in))
    {
        buffer = readLineFromFile(in);
        if (strstr(buffer, string) != NULL)
        {
            if (strstr(buffer, INA) != NULL)
            {
                put(cache,strdup(string),strdup(strrchr(buffer,' ')+1));
                return;
            }else
            if (strstr(buffer, "IN CNAME") != NULL&&strcmp(strrchr(buffer,' ')+1,string)!=0)
            {
                answer= strdup(strrchr(buffer,' ')+1);
                free(buffer);
                fseek(in,0,SEEK_SET);
                while(!feof(in))
                {
                    buffer = readLineFromFile(in);
                    if (strstr(buffer, INA) != NULL && strstr(buffer, answer) != NULL)
                    {
                        put(cache, strdup(string), strdup(strrchr(buffer, ' ') + 1));
                        free(buffer);
                        return;
                    }
                    free(buffer);
                }
                buffer=answer;
            }
        }
        free(buffer);
    }
}

void destroyCache(Cache *cache)
{
    HashTable *table = cache->hashtable;
    List *list = cache->list;
    Node *tmp = list->head;
    while (tmp)
    {
        Node *next = tmp->next;
        free(tmp->key);
        free(tmp->value);
        free(tmp);
        tmp = next;
    }
    free(table->values);
    free(table);
    free(list);
}