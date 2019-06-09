#include <cstdio>
#define MAX_L 500000

const int HASH_SIZE = 10000;
const int PN  = 23;

int name_size;
char name[MAX_L][22];
int table[HASH_SIZE][1000]; 
//table의 0번째에는 해당 위치에 들어있는 데이터의 숫자가 들어가있다.
//값은 해당 문자열의 Index가 들어감
char ret[MAX_L][22];
char buf[MAX_L][22];

//해싱
unsigned int get_key(char _data[]){
    unsigned int key = 0, p = 1;
    for(int i = 0; _data[i] != 0; ++i){
        key += (_data[i] * p);
        p *= PN;
    }
    return (key % HASH_SIZE);
}

//문자열 비교
int my_strcmp(char a[], char b[]){
    int i = 0 ;
    while(a[i]){
        if(a[i] != b[i]) break;
        ++i;
    }
    return a[i] - b[i];
}

//문자열 복사
void my_strcpy(char dst[], char src[]){
    int i = 0;
    while(src[i]){
        dst[i] = src[i];
        ++i;
    }
    dst[i] = '\0';
}

//해시테이블에 값 존재 유무 확인
int contain(char _data[]){
    unsigned int key = get_key(_data);
    int h_size = table[key][0];
    for(int i = 1; i <= h_size; ++i){
        int n_pos = table[key][i];
        if(my_strcmp(name[n_pos], _data) == 0){
            return n_pos;
        }
    }
    return -1;
}

//해시테이블에 삽입
void add(char _name[]){
    int len;
    for(len = 0; _name[len] != 0; ++len){
        name[name_size][len] = _name[len];
    }
    name[name_size][len] = 0;

    unsigned int key = get_key(_name);
    int& h_size = table[key][0];
    table[key][++h_size] = name_size;

    ++name_size;
}

//제거
bool remove(char _name[]){
    unsigned int key = get_key(_name);
    int& h_size = table[key][0];
    for(int i = 1; i <= h_size; ++i){
        int n_pos = table[key][i];
        if(my_strcmp(name[n_pos], _name) == 0){
            for(int j = i+1; j <= h_size; ++j){
                table[key][j-1] = table[key][j];
            }
            --h_size;
            return true;
        }
    }
    return false;
}

void merge(char (*p)[22], int len){
    if(len < 2) return;
    int i,j,k,mid;
    mid = len/2;
    i = 0; j = mid; k = 0;
    merge(p , mid);
    merge(p+mid, len-mid);
    while(i<mid && j<len){
        if(my_strcmp(p[i], p[j]) < 0){
            my_strcpy(buf[k++], p[i++]);
        }else{
            my_strcpy(buf[k++], p[j++]);
        }
    }
    while(i<mid){
        my_strcpy(buf[k++], p[i++]);
    }
    while(j<len){
        my_strcpy(buf[k++], p[j++]);
    }
    for(int i = 0; i < len; i++){
        my_strcpy(p[i], buf[i]);
    }
}

int main(void){
    int ans = 0;
    int n,m; scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        char tmp[22]; scanf("%s", tmp);
        add(tmp);
    }
    for(int i = 0; i < m; i++){
        char tmp[22]; scanf("%s", tmp);
        int find = contain(tmp);
        if(find >= 0){
            my_strcpy(ret[ans], tmp);
            ++ans;
        }
    }
    merge(ret, ans);
    printf("%d\n", ans);
    for(int i = 0; i < ans; i++){
        printf("%s\n", ret[i]);
    }
}