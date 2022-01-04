#include <stdio.h>

/*Sum of natural numbers from 0 to n*/
int sum(int n){
    if(n==0){
        return 0;
    }

    return sum(n-1)+n;
}

int Isum(int n){
    int s=0;
    int i;
    for(i=1;i<=n;i++){
        s=s+i;
    }
    return s;
}

int factorial(int n){
    if(n==0){
        return 1;
    }

    return factorial(n-1)*n;
}

int exp(int m, int n){
//m power n
    if(n==0){
        return 1;
    }

    return exp(m,n-1)*m;
}

int Ifact(int n){
    int f=1;
    int i;
    for(i=1;i<=n;i++){
        f=f*i;
    }
    return f;
}

/*Taylor Series*/
int taylor(int x, int n){
    static int p,f=1;
    int r;
    if (n==0){
        return 1;
    }
    r=taylor(x,n-1);
    p=p*x;
    f=f*n;
    return x+p/f;
}

/*Taylor series using horners rule: 1+(x/n)*/
double taylor_swift(int x, int n){
    static double s;
    if(n==0){
        return s;
    }
    s=1+x/n;
    return taylor_swift(x,n-1);
}

/*Taylor series using horners rule except iterative*/
double taylor_launtner(int x, int n){
    double s=1;
    int i;
    double num=1;
    double den=1;

    for(i=1;i<=n;i++){
        num*=1;
        den*=i;
        s+=num/den;
    }
    return 0.0;
}

/*Fibonacci. fib(n-2)+fib(n-1)*/
double fibonacci(int n){
    if(n<=1){
        return n;
    }
    return fibonacci(n-2)+fibonacci(n-1);
}

/*Cominbation (n!)/r!(n-r)!*/
//Pascal's triangle
int combination(int n, int r){
    //den=denominator
    int num, den;

    num=factorial(n);
    den=factorial(r)*factorial(n-r);

    return num/den;
}

/*Tower of hanoi(a: from, b: using, c: to)*/
void tower(int n, int A, int B, int C){
    //moving the disk from tower A to C
    if(n>0){
        tower(n-1,A,C,B);
        printf("(%d,%d)\n",A,C);
        tower(n-1,B,A,C);
    }
}

int main(){
    int r=Isum(5);
    printf("%d ",r);

    int f=factorial(5);
    printf("%d ",f);

    int e=exp(5,2);
    printf("%d ",e);

    int p=taylor(2,3);
    printf("%d ",p);

    int taylor1 = taylor_swift(2,10);
    printf("%lf \n", taylor1);

    int fibby = fibonacci(10);
    printf("%d \n", fibby);

    int combo = combination(4,2);
    printf("%d \n", combo);
    
    return 0;
}