#include<stdio.h>
#include<stdlib.h>
void display(int **mat,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",*(*(mat+i)+j));
        }
        printf("\n");
    }
}
int main(){
    int m,n;
    printf("Enter the size of row: ");
    scanf("%d",&m);
    printf("Enter the size of col: ");
    scanf("%d",&n);
    int **mat1;
    mat1=(int **)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++){
        mat1[i]=(int *)malloc(n*sizeof(int));
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&mat1[i][j]);
        }
    }
    display(mat1,m,n);
    return 0;
}