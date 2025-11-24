#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
} Node;
Node* CreateNode(int val){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data=val;
    newnode->left = NULL;
    newnode->right=NULL;
    return newnode;
}
Node* Insert(int val, Node* root) {
    if (root == NULL) {
        return CreateNode(val);
    }

    if (val < root->data)
        root->left = Insert(val, root->left);
    else if (val > root->data)
        root->right = Insert(val, root->right);
    else
        printf("Duplicate values are not allowed!\n");

    return root;
}

void display(Node* root){
    //preorder
    if(root){
        printf("%d ",root->data);
        display(root->left);
        display(root->right);
    }
}
int main(){
    Node* root = NULL;
    int choice,val;
   
    while(1){
        printf("=====MENU DRIVEN=====\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                printf("Enter the value: ");
                scanf("%d",&val);
                root=Insert(val,root);
                break;
            case 2:
                if (root == NULL)
                    printf("Tree is empty!\n");
                else {
                    printf("Preorder Traversal: ");
                    display(root);
                    printf("\n");
                }
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}