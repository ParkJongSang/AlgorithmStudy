#include <cstdio>
#include <cstring>

int q[10001];
int q_front = 0;
int q_rear = 0;
int q_size = 0;

int N;
char str[10];

void push(int n){
    q[q_rear] = n;
    q_rear += 1;
    q_size += 1;
}

int pop(){
    if(q_size == 0){
        return -1;
    }
    int ret = q[q_front];
    q_front += 1;
    q_size -= 1;
    return ret;
}

int size(){
    return q_size;
}

int empty(){
    if(q_size == 0){
        return 1;
    }
    return 0;
}

int front(){
    if(q_size == 0){
        return -1;
    }
    return q[q_front];
}

int back(){
    if(q_size == 0){
        return -1;
    }
    return q[q_rear-1];
}

int main(void){
    scanf("%d", &N);

    while(N--){
        scanf("%s", str);
        if(strcmp(str,"push") == 0){
            int input;
            scanf("%d", &input);
            push(input);
        }else if(strcmp(str,"pop") == 0){
            printf("%d\n", pop());
        }else if(strcmp(str,"size") == 0){
            printf("%d\n", size());
        }else if(strcmp(str,"empty") == 0){
            printf("%d\n", empty());
        }else if(strcmp(str,"front") == 0){
            printf("%d\n", front());
        }else if(strcmp(str,"back") == 0){
            printf("%d\n", back());
        }
    }
    return 0;
}
