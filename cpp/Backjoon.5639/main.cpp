#include <cstdio>

struct Node{
    int key;
    Node *left;
    Node *right;
};

Node *insert(Node *root, int value){
    if(root == NULL){
        Node *temp = new Node;
        temp -> key = value;
        temp -> left = temp -> right = NULL;
        return temp;
    }

    if(root -> key < value){
        root -> right = insert(root -> right, value);
    }else{
        root -> left = insert(root -> left, value);
    }
    return root;
}

void printPost(Node *root){
    if(root -> left){
        printPost(root -> left);
    }
    if(root -> right){
        printPost(root -> right);
    }
    printf("%d\n", root -> key);
}

int main(void){
    int tmp;
    Node *root = NULL;
    //초기화 해줄것...
    while(scanf("%d", &tmp) != EOF){
        root = insert(root, tmp);
    }
    printPost(root);

    return 0;
}