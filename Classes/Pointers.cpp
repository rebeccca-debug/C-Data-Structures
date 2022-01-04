#include <iostream>
#include <stdio.h>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    pointer6();
    
    return 0;
}

int pointer1(){
    int a=10;
    int *p;
    p=&a;
    
    printf("using pointer %d %d", *p, a);
    
    return 0;
}

int pointer2(){
    int A[5]={2,4,6,8,10};
    int *p;
    p=A;
    
    for(int i=0;i<5;i++){
        cout<<p[i]<<endl;
    }
    
    return 0;
}

int pointer3(){
    int *p; /*p is in the stack*/
    /*p=(int *)malloc(5*sizeof(int)); Array of 5 ints is created in the heap*/
    p=new int[5];
    
    p[0]=10; p[1]=15; p[2]=14; p[3]=21; p[4]=31;
    
    for(int i=0;i<5;i++){
        cout<<p[i]<<endl;
    }
    
    delete [ ] p; /*Release the memory (C++)*/
    return 0;
}

int pointer4()
{
    int a=10;
    int &r=a;
    
    int b=30;
    r=b;
    
    cout<<a<<endl<<r<<endl;
    
    return 0;
}

int pointer5()
{
    Rectangle r={10,5};
    cout<<r.length<<endl;
    cout<<r.breadth<<endl;
    
    Rectangle *p=&r;
    cout<<p->length<<endl;
    cout<<p->breadth<<endl;
    
    return 0;
}

int pointer6()
{
    Rectangle *p;
    p=(struct Rectangle *)malloc(sizeof(struct Rectangle));
    
    p->length=15;
    p->breadth=7;
    
    cout<<p->length<<endl;
    cout<<p->breadth<<endl;
    
    return 0;
}