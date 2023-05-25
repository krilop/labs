//
// Created by krilop on 5/6/23.
//
#include "functions.h"

int main() {
    FILE* DB = fopen("../term2/lab5/DataBase.txt","r");
    if(DB==NULL)
    {
        printf("Error of opening DB\n");
        return 1;
    }
    menu(DB);

    LRUCache* cache = createLRUCache(3);

    put(cache, "key1", "value1");
    put(cache, "key2", "value2");
    put(cache, "key3", "value3");

    printf("%s\n", get(cache, "key1"));  // Вывод: value1

    put(cache, "key4", "value4");

    printf("%s\n", get(cache, "key2"));  // Вывод: (null)

    destroyLRUCache(cache);

    return 0;
}