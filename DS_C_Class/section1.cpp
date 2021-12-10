#include <iostream>
#include <stdio.h>

using namespace std;

#include <stdio.h>
#include <iostream>

main(){
    plus_input_output();
    rectangleStruct();
    
    return 0;
}

struct Rectangle{
    int length;         /*4 bytes*/
    int breadth;        /*4 bytes*/
    char x;             /*1 byte*/
}

rectangleStruct(){
    struct Rectangle r1={10,5,'c'}; /*Takes 12 bytes b/c nearest multiple of 4*/
    
    /*C*/
    printf("%lu", sizeof(r1));
    
    r1.length=15;
    r1.breadth=7;
    r1.x='r';
    
    /**C++**/
    cout<<r1.length<<endl;
    cout<<r1.breadth<<endl;
    cout<<r1.x<<endl;
}

/*C++ first time with carry in carry out*/
plus_input_output(){
    int n;
    cout<<"Enter Size";
    cin>>n;
    int A[n]={2,4,6,8,10,12};
    
    for(int x:A)
    {
        cout<<x<<endl;
    }
    
    cout<<sizeof(A)<<endl;  /*Print size of A*/
    cout<<A[1]<<endl;       /*Print A[1]*/
    printf("%d\n",A[2]);    /*Print A[2]*/
    
    return 0;
};
