#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    float data;
    struct node *next;
}node;
node* createlist(int n){
    if(n<=0)return NULL;
    node* head;
    head=(node *)malloc(sizeof(node));
    if(head==NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    node* temp;
    temp=head;
    printf("Enter the data: ");
    scanf("%f",&head->data);
    head->next=NULL;
    for(int i=1;i<n;i++){
        node *newnode;
        newnode=(node *)malloc(sizeof(node));
        scanf("%f",&(newnode->data));
        temp->next=newnode;
        newnode->next=NULL;
        temp=temp->next;
    }
    return head;
}
void display(node *head){
    node *temp=head;
    while(temp!=NULL){
        printf("%.2f->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
    return;
}
node* InsertByIndex(node *head,int index,float val){
    int count=0;
    node *temp=head;
    node *prev=NULL;
    if(index==0){
        node *newhead;
        newhead=(node *)malloc(sizeof(node));
        newhead->data=val;
        newhead->next=head;
        return newhead;
    }
    while(temp!=NULL){
        if(count==index){
            node *newnode;
            newnode=(node *)malloc(sizeof(node));
            newnode->data=val;
            newnode->next=temp;
            prev->next=newnode;
            return head;
        }
        count++;
        prev=temp;
        temp=temp->next;
    }
    if(count == index){
        node *newnode;
            newnode=(node *)malloc(sizeof(node));
            newnode->data=val;
            newnode->next=temp;
            prev->next=newnode;
            return head;
    }
    return head;
}
void delete_node(node **head,int index){
    node *temp=*head;
    node *prev=NULL;
    int count=0;
    if(index==0){
        *head=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL){
        if(count==index){
            prev->next=temp->next;
            free(temp);
            return;
        }
        prev=temp;
        temp=temp->next;
        count++;
    }
}
int search(node *head,float val){
    node *temp=head;
    int index=0;
    while(temp!=NULL){
        if(temp->data==val){
            return index;
            break;
        }
        index++;
        temp=temp->next;

    }
    return -1;
}
int isEmpty(node **head){
    node *temp=*head;
    if(temp==NULL){
        return 0;
    }
    else return 1;
}
int main(){
    int n;
    printf("Enter the number of data: ");
    scanf("%d",&n);
    node* head;
    head=createlist(n);
    while(1){
        int choice;
        int index;
        float val;
        printf("1:Insert by index(int index)\n");
        printf("2:Insert at position (float val)\n");
        printf("3:delete by index\n");
        printf("4:delete at position\n");
        printf("5:printList\n");
        printf("6:search\n");
        printf("7:isEmpty\n");
        printf("8: exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("At which index want to add: ");
            scanf("%d",&index);
            printf("Enter the value: ");
            scanf("%f",&val);
            head=InsertByIndex(head,index,val);
            break;
        case 2:
            printf("Enter the value:");
            scanf("%f",&val);
            printf("At begining: 0,At middle : %d ,At end %d: ",(n/2),n);
            scanf("%d",&index);
            head=InsertByIndex(head,index,val);
            break;
        case 3:
            printf("Enter the index: ");
            scanf("%d",&index);
            delete_node(&head,index);
            break;
        case 4:
            printf("At begining: 0,At middle : %d ,At end %d: ",(n/2),n);
            scanf("%d",&index);
            delete_node(&head,index);
            break;
        case 5:
            display(head);
            break;
        case 6:
            printf("Enter the val to search: ");
            scanf("%f",&val);
            int found=search(head,val);
            if(found>=0){
                printf("The index is : %d\n",found);
            }
            else{
                printf("Not found!!");
            }
            break;
        case 7:
            if(isEmpty(&head)){
                printf("The linked list is not empty\n");
            }
            else{
                printf("Empty!!\n");
            }
            break;
        default:
            break;
        }
        if(choice==8){
            break;
        }
    }
}