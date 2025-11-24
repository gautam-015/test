#include<stdio.h>
#include<stdlib.h>
typedef struct _poly{
    int exp;
    float coef;
    struct _poly *next;
}poly;
void display(poly *start){
    poly *temp=start;
    while(temp->next!=NULL){
        printf("%.1fx^%d",temp->coef,temp->exp);
        printf(" + ");
        temp=temp->next;
    }
    printf("%.1fx^%d\n",temp->coef,temp->exp);
}
poly* create(int n){
    int exp;
    float coef;
    poly *start=NULL;
    poly *temp=NULL;
    
    for(int i=0;i<n;i++){
        printf("Enter the exponent of term %d\n",i+1);
        scanf("%d",&exp);
        printf("Enter the coefficient\n");
        scanf("%f",&coef);
        poly *new;
        new=(poly*)malloc(sizeof(poly));
        new->coef=coef;
        new->exp=exp;
        new->next=NULL;
        if(start==NULL){
            start=new;
            temp=new;
        }
        else{
            temp->next=new;
            temp=temp->next;
        }
        
    }
    return start;
}
poly* add(poly *head1,poly *head2){
    if(head1==NULL || head2==NULL){
        return NULL;
    }
    poly *t1=head1;
    poly *t2=head2;
    while(t1->next!=NULL && t2->next!=NULL){
        if(t1->exp==t2->exp){
            t1->coef+=t2->coef;
            t1=t1->next;
            t2=t2->next;
        }
        t1=t1->next;
        t2=t2->next;
    }
    t1->coef+=t2->coef;
    while(t2!=NULL){

    }
}
int main(){
    int n;
    printf("Enter the degree of polynomial 1\n");
    scanf("%d",&n);
    poly *head1=create(n);
    printf("Enter the degree of polynomial 2\n");
    scanf("%d",&n);
    poly *head2=create(n);
    display(head1);
    display(head2);
    return 0;
}