#include <stdio.h>
void funB(int n);

/*Indirect recursion*/
void funA(int n){
    if(n>0){
        printf("%d ", n);
        funB(n-1);
    }
}

void funB(int n){
    if(n>1){
        printf("%d ", n);
        funA(n/2);
    }
}

/*Nested Recursion*/
int fun(int n){
    if (n>100){
        return n-10;
    }
    return fun(fun(n+11));
}

int main(){
    funA(20);
    int r;
    r=fun(95);
    printf("%d\n",r);
    return 0;
}