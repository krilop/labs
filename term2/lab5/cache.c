//
// Created by krilop on 5/26/23.
//

#include "cache.h"

Node *createNode(const char *key, const char *value)
{
    Node *newNode = (Node *) malloc(sizeof(Node));
    (*newNode).key = strdup(key);
    (*newNode).value = strdup(value);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

LinkedList *createLinkedList()
{
    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
    (*list).head = createNode("", "");
    (*list).tail = createNode("", "");
    (*(list->head)).next = list->tail;
    (*(list->tail)).prev = list->head;
    return list;
}

void addToFront(LinkedList *list, Node *node)
{
    (*node).next = list->head->next;
    (*node).prev = list->head;
    (*(list->head->next)).prev = node;
    (*(list->head)).next = node;
}

void removeFromList(LinkedList *list, Node *node)
{
    (*(node->prev)).next = node->next;
    (*(node->next)).prev = node->prev;
}

void deleteNode(Node *node)
{
    free(node->key);
    free(node->value);
    free(node);
}

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

LRUCache *createLRUCache(int capacity)
{
    LRUCache *cache = (LRUCache *) malloc(sizeof(LRUCache));
    (*cache).capacity = capacity;
    (*cache).count = 0;
    (*cache).cache = (LinkedList *) malloc(sizeof(LinkedList) * capacity);
    (*cache).hashmap = (Node **) malloc(sizeof(Node *) * capacity);
    for (int i = 0; i < capacity; i++)
    {
        (*cache).cache[i] = *createLinkedList();
        (*cache).hashmap[i] = NULL;
    }
    return cache;
}

void updateLRUCache(LRUCache *cache, int index, Node *node)
{
    LinkedList *list = &(cache->cache[index]);
    removeFromList(list, node);
    addToFront(list, node);

    // Обновляем указатель на список в хеш-таблице
    (*cache).hashmap[index] = list;

    // Обновляем порядок использования элемента в общем списке кеша
    removeFromList((*cache).cache, node);
    addToFront((*cache).cache, node);
}

char *get(LRUCache *cache, const char *key)
{
    int index = hashFunction(key, cache->capacity);
    LinkedList* list = &((*cache).cache[index]);
    Node *node = list->head->next;
    while (node != list->tail)
    {
        if (strcmp(node->key, key) == 0)
        {
            removeFromList(list, node);
            addToFront(list, node);
            removeFromList((*cache).cache, node);
            addToFront((*cache).cache, node);
            return (*node).value;
        }
        node = node->next;
    }
    return NULL;
}

void put(LRUCache *cache, const char *key, const char *value)
{
    if ((*cache).count == (*cache).capacity)
    {
        // Найти последний непустой список
        int lastNonEmptyListIndex = -1;
        for (int i = cache->capacity - 1; i >= 0; i--)
        {
            if (cache->cache[i].head->next != cache->cache[i].tail)
            {
                lastNonEmptyListIndex = i;
                break;
            }
        }

        if (lastNonEmptyListIndex != -1)
        {
            // Найти последний узел в последнем непустом списке
            LinkedList *lastList = &(cache->cache[lastNonEmptyListIndex]);
            Node *lastNode = lastList->head->next;
            while (lastNode->next != lastList->tail)
            {
                lastNode = lastNode->next;
            }

            // Удалить последний узел
            removeFromList(lastList, lastNode);
            cache->hashmap[hashFunction(lastNode->key, cache->capacity)] = NULL;
            deleteNode(lastNode);
            (*cache).count--;
        }
    }
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

    Node *newNode = createNode(key, value);
    addToFront(list, newNode);
    cache->hashmap[index] = newNode;
    (*cache).count++;
}


void destroyLRUCache(LRUCache *cache)
{
    for (int i = 0; i < (*cache).capacity; i++)
    {
        LinkedList *list = &((*cache).cache[i]);
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

void printLRUCache(LRUCache* cache) {
    int maxKeyLength = 0;
    int maxValueLength = 0;
    int maxHashLength = 0;

    for (int i = 0; i < (*cache).capacity; i++) {
        LinkedList* list = &((*cache).cache[i]);
        Node* node = list->head->next;
        while (node != list->tail) {
            int keyLength = strlen(node->key);
            int valueLength = strlen(node->value);
            int hashLength = snprintf(NULL, 0, "%d", i) + 1;  // +1 для учета нулевого символа
            if (keyLength > maxKeyLength) {
                maxKeyLength = keyLength;
            }
            if (valueLength > maxValueLength) {
                maxValueLength = valueLength;
            }
            if (hashLength > maxHashLength) {
                maxHashLength = hashLength;
            }
            node = node->next;
        }
    }


    printf("+----+-%-*s-+-%-*s-+-%-*s-+\n", maxHashLength, "Hash", maxKeyLength, "Key", maxValueLength, "Value");
    printf("| No.| %-*s | %-*s | %-*s |\n", maxHashLength, "Hash", maxKeyLength, "Key", maxValueLength, "Value");
    printf("+----+-%-*s-+-%-*s-+-%-*s-+\n", maxHashLength, "----", maxKeyLength, "---------", maxValueLength, "---------");

    for (int i = 0; i < (*cache).capacity; i++) {
        LinkedList* list = &((*cache).cache[i]);
        Node* node = list->head->next;
        int entryNumber = 1;
        while (node != list->tail) {
            printf("| %-3d| %-*d | %-*s | %-*s |\n", entryNumber, maxHashLength, hashFunction(node->key,cache->capacity), maxKeyLength, node->key, maxValueLength, node->value);
            node = node->next;
            entryNumber++;
        }
    }

    printf("+----+-%-*s-+-%-*s-+-%-*s-+\n", maxHashLength, "----", maxKeyLength, "---------", maxValueLength, "---------");
}




