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
    
    cout<<sizeof(A)<<endl;
    cout<<A[1]<<endl;
    printf("%d\n",A[2]);
    
    return 0;
}
