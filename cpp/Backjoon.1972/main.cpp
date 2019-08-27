#include <iostream>

#define HEAP_MAX_SIZE 100000

using namespace std;

void push(int *nHeap, int *nHeapSize, int data){
    int target = *nHeapSize + 1;
    
    while(target != 1 && nHeap[target/2] > data){
        nHeap[target] = nHeap[target/2];
        target = target / 2;
    }
    nHeap[target] = data;
    (*nHeapSize)++;
}

int getRoot(int *nHeap, int nHeapSize){
    if(nHeapSize == 0){
        return 0;
    }
    return nHeap[1];
}

void pop(int *nHeap, int *nHeapSize){
    if(*nHeapSize <= 0){
        return;
    }
    int parent = 1, child = 2;
    int temp = nHeap[*nHeapSize];
    while(child < *nHeapSize){
        if(child + 1 < *nHeapSize && nHeap[child] > nHeap[child + 1]){
            ++child;
        }
        if(temp <= nHeap[child]){
            break;
        }
        nHeap[parent] = nHeap[child];
        parent = child;
        child *= 2;
    }
    nHeap[parent] = temp;
    (*nHeapSize)--;
    return;
}


int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int testCase = 0;
    int heap[HEAP_MAX_SIZE + 1] = {0, };
    int heapSize = 0;

    cin >> testCase;
    while(testCase--){
        int cmd;
        cin >> cmd;
        if(cmd == 0){
            cout << getRoot(heap, heapSize) <<"\n";
            pop(heap, &heapSize);
        }else{
            push(heap, &heapSize, cmd);
        }
    }
    return 0;
}