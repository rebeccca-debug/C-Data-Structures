#include <iostream>

int main()
{
    int A[5];
    A[0]=12;
    A[1]=15;
    A[2]=25;

    std::cout<<sizeof(A)<<std::endl;
    std::cout<<A[1]<<std::endl;

    return 0;
}