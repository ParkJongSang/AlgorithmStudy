#include <stdio.h>
#define MAX_ELEMENT 200

typedef struct{
    int key;
} element;

typedef struct{
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

HeapType heap;

void insert_max_heap(HeapType *h, element item){
    int i;
    i = (h -> heap_size)++;

    while((i != 1) && (item.key > h->heap[i/2].key)){
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = item;
}

element delete_max_heap(HeapType *h){
    int parent, child;
    element ret, temp;

    ret = h -> heap[1];
    temp = h -> heap[(h->heap_size)--];

    parent = 1;
    child = 2;

    while(child <= h->heap_size){
        if((child < h->heap_size) && ((h->heap[child].key) < h -> heap[child+1].key)){
            child += 1;
        }

        if(temp.key >= h->heap[child].key){
            break;
        }

        h->heap[parent] = h-> heap[child];
        parent = child;
        child *= 2;
    }

    h->heap[parent] = temp;
    return ret;
}


