//
// Created by krilop on 5/26/23.
//

#ifndef _CACHE_H_
#define _CACHE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *key;
    char *value;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
} LinkedList;

typedef struct LRUCache {
    int capacity;
    int count;
    LinkedList *cache;
    Node **hashmap;
} LRUCache;

Node *createNode(const char *key, const char *value);
LinkedList *createLinkedList();
void addToFront(LinkedList *list, Node *node);
void removeFromList(LinkedList *list, Node *node);
void deleteNode(Node *node);
int hashFunction(const char *key, int capacity);
LRUCache *createLRUCache(int capacity);
void updateLRUCache(LRUCache *cache, int index, Node *node);
char *get(LRUCache *cache, const char *key);
void put(LRUCache *cache, const char *key, const char *value);
void destroyLRUCache(LRUCache *cache)
#endif //_CACHE_H_
