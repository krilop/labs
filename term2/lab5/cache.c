//
// Created by krilop on 5/26/23.
//

#include "cache.h"

Node *createNode(const char *key, const char *value)
{
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = strdup(value);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

LinkedList *createLinkedList()
{
    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
    list->head = createNode("", "");
    list->tail = createNode("", "");
    list->head->next = list->tail;
    list->tail->prev = list->head;
    return list;
}

void addToFront(LinkedList *list, Node *node)
{
    node->next = list->head->next;
    node->prev = list->head;
    list->head->next->prev = node;
    list->head->next = node;
}

void removeFromList(LinkedList *list, Node *node)
{
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void deleteNode(Node *node)
{
    free(node->key);
    free(node->value);
    free(node);
}

int hashFunction(const char *key, int capacity)
{
    int hash=0;
    char c;
    while ((c = *key++))
        hash = hash + c;
    return hash % capacity;
}

LRUCache *createLRUCache(int capacity)
{
    LRUCache *cache = (LRUCache *) malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->count = 0;
    cache->cache = (LinkedList *) malloc(sizeof(LinkedList) * capacity);
    cache->hashmap = (Node **) malloc(sizeof(Node *) * capacity);
    for (int i = 0; i < capacity; i++)
    {
        cache->cache[i] = *createLinkedList();
        cache->hashmap[i] = NULL;
    }
    return cache;
}

void updateLRUCache(LRUCache *cache, int index, Node *node)
{
    LinkedList *list = &(cache->cache[index]);
    removeFromList(list, node);
    addToFront(list, node);

    // Обновляем порядок использования элемента в общем списке кеша
    removeFromList(cache->cache, node);
    addToFront(cache->cache, node);
}

char *get(LRUCache *cache, const char *key)
{
    int index = hashFunction(key, cache->capacity);
    LinkedList *list = &(cache->cache[index]);
    Node *node = list->head->next;
    while (node != list->tail)
    {
        if (strcmp(node->key, key) == 0)
        {
            updateLRUCache(cache, index, node);
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}

void put(LRUCache *cache, const char *key, const char *value)
{
    int index = hashFunction(key, cache->capacity);
    LinkedList *list = &(cache->cache[index]);
    Node *node = list->head->next;
    while (node != list->tail)
    {
        if (strcmp(node->key, key) == 0)
        {
            free(node->value);
            node->value = strdup(value);
            updateLRUCache(cache, index, node);
            return;
        }
        node = node->next;
    }
    if (cache->count == cache->capacity)
    {
        int evictIndex = hashFunction(cache->cache->tail->prev->key, cache->capacity);
        Node *evictNode = cache->cache[evictIndex].tail->prev;
        removeFromList(&(cache->cache[evictIndex]), evictNode);
        cache->hashmap[evictIndex] = NULL;
        deleteNode(evictNode);
        cache->count--;
    }
    Node *newNode = createNode(key, value);
    addToFront(list, newNode);
    cache->hashmap[index] = newNode;
    cache->count++;
}

void destroyLRUCache(LRUCache *cache)
{
    for (int i = 0; i < cache->capacity; i++)
    {
        LinkedList *list = &(cache->cache[i]);
        Node *node = list->head->next;
        while (node != list->tail)
        {
            Node *temp = node;
            node = node->next;
            deleteNode(temp);
        }
        free(list->head);
        free(list->tail);
    }
    free(cache->cache);
    free(cache->hashmap);
    free(cache);
}


