#include<stdio.h>//convert to sparse
#include<stdlib.h>
int** transpose(int **sparse,int sparse_row,int col){
    int **t;
    t=(int**)malloc(sparse_row*sizeof(int*));
    for(int i=0;i<sparse_row;i++){
        t[i]=(int*)malloc(3*sizeof(int));
    }
    int k = 0;
    for(int j = 0; j < col; j++){
        for(int i =0;i<sparse_row;i++){
            if(sparse[i][1]==j){
                t[k][0]=sparse[i][1];
                t[k][1]=sparse[i][0];
                t[k][2]=sparse[i][2];
                k++;
            }
        }
    }
    printf("\nTranspose of Sparse Matrix Representation (Triple Format):\n");
    printf("Row  Col  Value\n");
    for (int i = 0; i < k; i++) {
        printf("%3d  %3d  %5d\n", t[i][0], t[i][1], t[i][2]);
    }
    return t;

}
int** convert_to_sparse(int **mat,int row,int col,int *ptr_sp_row){
    int **sparse=NULL;
    int k =0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(mat[i][j]!=0){
                sparse=(int**)realloc(sparse,(k+1)*sizeof(int*));
                sparse[k]=(int*)malloc(3*sizeof(int));
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=mat[i][j];
                k++;
            }
        }
    }
    printf("\nSparse Matrix Representation (Triple Format):\n");
    printf("Row  Col  Value\n");
    for (int i = 0; i < k; i++) {
        printf("%3d  %3d  %5d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }
    *(ptr_sp_row)=k;
    return sparse;
}
int main(){
    int row;
    int col;
    printf("Enter the number of row: ");
    scanf("%d",&row);
    printf("Enter the number of col: ");
    scanf("%d",&col);
    int **mat;
    mat=(int **)malloc(row*sizeof(int*));
    for(int i=0;i<row;i++){
        mat[i]=(int*)malloc(col*sizeof(int));
    }
    printf("Enter the elements: ");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    int sparse_row=0;
    int **sparse=convert_to_sparse(mat,row,col,&sparse_row);
    int **t=transpose(sparse,sparse_row,col);
    for (int i = 0; i < row; i++)
    free(mat[i]);
    free(mat);

    for (int i = 0; i < sparse_row; i++)
        free(sparse[i]);
    free(sparse);

    for (int i = 0; i < sparse_row; i++)
        free(t[i]);
    free(t);
    return 0;
}