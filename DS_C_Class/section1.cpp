#include <iostream>
#include <stdio.h>

using namespace std;

main(){
    int A[5];
    A[0] = 5;
    A[1] = 10;
    A[2] = 20;
    A[3] = 25;
    A[4] = 30;
    
    cout<<sizeof(A)<<endl;  /*Print size of A*/
    cout<<A[1]<<endl;       /*Print A[1]*/
    printf("%d\n",A[2]);    /*Print A[2]*/
    
    return 0;
}

input_output(){
    int n;
    cout<<"Enter Size";
    cin>>n;
    int A[n]={2,4,6,8,10,12};
    
    for(int x:A)
    {
        cout<<x<<endl;
    }
    
    return 0;
}
