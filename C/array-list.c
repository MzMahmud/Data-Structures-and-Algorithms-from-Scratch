#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayList {
    int *data;
    int size;
    int capacity;
} ArrayList;

ArrayList construct(int initialCapacity) {
    ArrayList arrayList;
    
    arrayList.data = (int *) malloc(initialCapacity * sizeof(int));
    arrayList.size = 0;
    arrayList.capacity = initialCapacity;
    
    return arrayList;
}

void reallocate(ArrayList *arrayList, int newCapacity) {
    arrayList->data = (int *) realloc(arrayList->data, newCapacity * sizeof(int));
    arrayList->capacity = newCapacity;
}

void add(ArrayList *arrayList, int value) {
    if(arrayList->size == arrayList->capacity) {
        int newCapacity = arrayList->capacity +  (arrayList->capacity >> 1); // 1.5 * arrayList->capacity
        reallocate(arrayList, newCapacity);
    }
    arrayList->data[arrayList->size++] = value;
}

void print(ArrayList *arrayList) {
    printf("ArrayList(data=[");
    for(int i = 0;i < arrayList->size; ++i) {
        printf("%d", arrayList->data[i]);
        if(i != (arrayList->size - 1)) {
            printf(",");
        }
    }
    printf("], size=%d, capacity=%d)\n", arrayList->size, arrayList->capacity);
}

void destruct(ArrayList *arrayList) {
    if(arrayList->data != NULL) {
        free(arrayList->data);
    }
}

int main(int argc, char const *argv[]) {
    ArrayList arrayList = construct(4);
    print(&arrayList);
    add(&arrayList, 1);
    add(&arrayList, 2);
    add(&arrayList, 3);
    add(&arrayList, 4);
    add(&arrayList, 5);
    add(&arrayList, 6);
    add(&arrayList, 7);
    add(&arrayList, 8);
    add(&arrayList, 9);
    add(&arrayList, 10);
    add(&arrayList, 11);
    print(&arrayList);
    destruct(&arrayList);
    return 0;
}
