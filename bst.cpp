#include <iostream>
#include <cstdlib>
#include<queue>
#include<cstdio>

using namespace std;

struct BNode{

    int data;
    struct BNode * left;
    struct BNode * right;
};

struct BNode*New_Node(int data){
    struct BNode * new_node = (struct BNode *)malloc(sizeof(struct BNode));
    new_node -> data = data;
    new_node -> left = NULL;
    new_node -> right = NULL;

    return new_node;
}

struct BNode* Insert(struct BNode* root,int data){
    if (root == NULL){
        root = New_Node(data);
    }
    else if(data <= root -> data){
        root -> left = Insert(root -> left, data);
    }
    else{
        root -> right = Insert(root -> right, data);
    }
    return root;
}

int search(struct BNode* root, int data){

    if(root == NULL) return -1;
    else if(root-> data == data) return 1;
    else if(data <= root -> data) return search(root->left,data);
    else return search(root->right, data);

}

int find_hight(struct BNode *root){

    if (root == NULL)
        return -1;
    else{
        int x = find_hight(root->left);
        int y = find_hight(root->right);
        return (x>y?x+1:y+1);
    }
}

void print_level(struct BNode *root){

    if(root == NULL)
        return;
    queue <BNode*> Q;
    Q.push(root);

    while(!Q.empty()){
        struct BNode * current = Q.front();
        printf("%c ",current -> data);
        if(current -> left != NULL)
            Q.push(current -> left);
        if(current -> right != NULL)
            Q.push(current -> right);
        Q.pop();
    }
}

void preorder(struct BNode* root){

    if(root == NULL)
        return ;
    printf("%c ",root -> data);
    preorder(root -> left);
    preorder(root -> right);
}

void inorder(struct BNode *root){

    if(root != NULL){
        inorder(root -> left);
        printf("%c ",root -> data);
        inorder(root -> right);
    }
    return;
}
void postorder(struct BNode* root){

    if(root != NULL){
        postorder(root -> left);
        postorder(root -> right);
        printf("%c ",root -> data);
    }

}

bool isbst(struct BNode *root,int min_value, int max_value){

    if(root == NULL)
        return true;
    if(root -> data >= min_value && root -> data <= max_value
       && isbst(root->left,min_value,root->data)
       && isbst(root->right,root->data,max_value))
        return true;
    else
        return false;
}

bool IBST(struct BNode * root){
    return isbst(root,INT_MIN,INT_MAX);
}
struct BNode * find_min(struct BNode* root){

    while(root-> left != NULL)
        root = root -> left;
    return root;
}
struct BNode* delete_node(struct BNode* root,int data){

    if(root == NULL)
        return root;
    else if(data < root -> data)
        root -> left = delete_node(root->left,data);
    else if(data > root -> data)
        root ->right = delete_node(root -> right,data);
    else{

        if(root -> left == NULL && root -> right == NULL){
            free(root);
            return NULL;
        }
        else if(root -> left == NULL){
            struct BNode* temp =root;
            root = root -> right;
            free(temp);
        }
        else if(root -> right == NULL){
            struct BNode * temp = root;
            root = root -> left;
            free(temp);
        }
        else{

            struct BNode* temp = find_min(root -> right);
            root -> data = temp -> data;
            root -> right = delete_node(root->right,temp -> data);
        }

    }
    return root;
}
struct BNode * find_min(struct BNode* root ,int data){

    while(root-> left != NULL)
        root = root -> left;
    return root;
}

int main()
{
    struct BNode * root = NULL;
    printf("Hello world!\n");
    root = Insert(root,'F');
    root = Insert(root,'D');
    root = Insert(root,'J');

    root = Insert(root,'B');
    root = Insert(root,'E');
    root = Insert(root,'A');
    root = Insert(root,'C');
    root = Insert(root,'G');
    root = Insert(root,'K');
    root = Insert(root,'I');
    root = Insert(root,'H');
    root = delete_node(root, 'J');
    cout << IBST(root) << endl;
    printf("%d\n",search(root,18));
    inorder(root);
    printf("\n%d\n",find_hight(root));
    print_level(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    return 0;
}
/*
TREE LOOKS LIKE
                          F
                  D                  J
             B        E        G            K
       A         C               H
                                    I

*/






