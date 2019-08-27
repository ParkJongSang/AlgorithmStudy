#include <stdio.h>

using namespace std;

int iHeapSize;
int iHeap[10000];

void push(int data){
    int target = iHeapSize + 1;
    while(target != 1 && iHeap[target / 2] < data){
        iHeap[target] = iHeap[target / 2];
        target /= 2;
    }
    iHeap[target] = data;
    ++iHeapSize;
}

void pop(){
    int parent = 1, child = 2;
    int temp = iHeap[iHeapSize];
    while(child < iHeapSize){
        if(child + 1 < iHeapSize && iHeap[child] < iHeap[child + 1]){
            ++child;
        }
        if(temp >= iHeap[child]){
            break;
        }
        iHeap[parent] = iHeap[child];
        parent = child;
        child *= 2;
    } 
    iHeap[parent] = temp;
    --iHeapSize;
}