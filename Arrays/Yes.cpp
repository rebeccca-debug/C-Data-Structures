#include <stdio.h>
#include <cstdlib>

int main(){

    return 0;
}

int ex1(){
    //create an array in stack (static)
    int A[5]={1,2,3,4,5};
    int *p;

    //create an array in heap (dynamic)
    p=(int *)malloc(5*sizeof(int));

    for(int i=0;i<5;i++){
        printf("%d ",A[i]);
    }

    p[0]=1;
    p[1]=2;
    p[2]=3;
    p[3]=4;
    p[4]=5;
    for(int i=0;i<5;i++){
        printf("%d ",p[i]);
    }

    return 0;
}

int ex2(){
    int *p,*q;
    int i;
    p=(int *)malloc(5*sizeof(int));
    p[0]=2;p[1]=4;p[2]=6;p[3]=8;p[4]=10;

    for(i=0;i<5;i++){
        q[i]=p[i];
    }
    free(p);
    p=q;
    q=NULL;

    for(i=0;i<5;i++){
        printf("%d \n",p[i]);
    }

    return 0;
};

int ex3(){
    int A[3][4]={{1,2,3,4},{2,4,6,8},{1,3,5,7}};

    int *B[3];
    int **C;
    int i,j;

    B[0]=(int *)malloc(4*sizeof(int));
    B[1]=(int *)malloc(4*sizeof(int));
    B[2]=(int *)malloc(4*sizeof(int));

    C=(int **)malloc(3*sizeof(int *));
    C[0]=(int *)malloc(4*sizeof(int));
    C[1]=(int *)malloc(4*sizeof(int));
    C[2]=(int *)malloc(4*sizeof(int));

    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
//Arrays in compilers: Addr(A[i])=L_0t(i-1)*w
    //Row major formula [left to right]: Addr(A[i][j])=L_0t(i*n+j)*w
    //Column major formula [right to left]: Addr(A[i][j]=L_0t[i*n+j]*w)