#include <stdio.h>
#include <string.h>

char order[20];
int N;

int stack[10000];
int stack_size = 0;

void push(int n){
    stack[stack_size++] = n;
}

int pop(){
    if(stack_size == 0){
        return -1;
    }
    int ret = stack[stack_size-1];
    stack_size -= 1;
    return ret;
}

int size(){
    return stack_size;
}

int empty(){
    if(stack_size == 0){
        return 1;
    }
    return 0;
}

int top(){
    if(stack_size == 0){
        return -1;
    }
    return stack[stack_size-1];
}

int main(void){
    scanf("%d", &N);

    while(N--){
        scanf("%s", order);
        if(strcmp(order, "push") == 0){
            int num = 0;
            scanf("%d", &num);
            push(num);
        }else if(strcmp(order, "pop") == 0){
            printf("%d\n", pop());
        }else if(strcmp(order, "size") == 0){
            printf("%d\n", size());
        }else if(strcmp(order, "empty") == 0){
            printf("%d\n", empty());
        }else if(strcmp(order, "top") == 0){
            printf("%d\n", top());
        }
    }

    return 0;
}