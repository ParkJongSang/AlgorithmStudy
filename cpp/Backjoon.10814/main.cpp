#include <cstdio>
#define MAX_L 100000

struct AgeName{
    int order;
    int age;
    char name[110];
};

AgeName ms[MAX_L], buf[MAX_L];

void strcpy(char *dest, char *src){
    int i = 0;
    while(src[i]){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void merge(AgeName *p, int len){
    if(len < 2) return;

    int i,j,k,mid;
    mid = len/2;
    i = 0; j = mid; k = 0;
    
    merge(p, mid);
    merge(p+mid, len-mid);

    while(i < mid && j < len){
        if(p[i].age < p[j].age){
            buf[k].age = p[i].age;
            buf[k].order = p[i].order;
            strcpy(buf[k].name, p[i].name);
            k++; i++;
        }else if(p[i].age > p[j].age){
            buf[k].age = p[j].age;
            buf[k].order = p[j].order;
            strcpy(buf[k].name, p[j].name);
            k++; j++;
        }else{
            if(p[i].order < p[j].order){
                buf[k].age = p[i].age;
                buf[k].order = p[i].order;
                strcpy(buf[k].name, p[i].name);
                k++; i++;
            }else{
                buf[k].age = p[j].age;
                buf[k].order = p[j].order;
                strcpy(buf[k].name, p[j].name);
                k++; j++;
            }
        }
    }

    while(i < mid){
        buf[k].age = p[i].age;
        buf[k].order = p[i].order;
        strcpy(buf[k].name, p[i].name);
        k++; i++;
    }
    while(j < len){
        buf[k].age = p[j].age;
        buf[k].order = p[j].order;
        strcpy(buf[k].name, p[j].name);
        k++; j++;
    }

    for(int i = 0; i < len; i++){
        p[i].order = buf[i].order;
        p[i].age = buf[i].age;
        strcpy(p[i].name, buf[i].name);
    }
}

int main(void){
    int n; scanf("%d", &n);
    for(int i = 0 ; i < n; i++){
        ms[i].order = i;
        scanf("%d %s", &ms[i].age, ms[i].name);
    }
    merge(ms, n);
    for(int i = 0; i < n; i++){
        printf("%d %s\n", ms[i].age, ms[i].name);
    }
    return 0;
}