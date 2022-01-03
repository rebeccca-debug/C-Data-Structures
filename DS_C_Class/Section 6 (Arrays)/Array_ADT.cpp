#include <stdio.h>
#include <cstdlib>

/*Data:
    1. Array space
    2. Size
    3. Length (No. of elements)
  Operations:
    1. Display()
    2. Add(x)/Append(x)
    3. Insert(index x)
    4. Delete(index)
    5. Search(x)
    6. Get(index)
    7. Set(index, x)
    8. Max(), Min()
    9. Reverse()
    10. Shift()/Rotate()
*/

struct Array{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr){
    int i;
    printf("Elements are\n");
    for(i=0;i<arr.length;i++){
        printf("%d ", arr.A[i]);
    }
}

void Append(struct Array *arr, int x){
    if(arr->length<arr->size){
        arr->A[arr->length++]=x;
    }
}

void Insert(struct Array *arr, int index, int x){
    int i;
    if(index>=0 &&index <= arr->length){
        for(i=arr->length;i>index;i--){
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
}

int Delete(struct Array*arr, int index){
    int x=0;

    if(index>=0 && index<=arr->length-1){
        x=arr->A[index];
        for(int i=index;i<arr->length-1;i++){
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        return x;
    }

    return 0;
}

int LinearSearch(struct Array arr, int key){
    int i;
    for(i=0;i<arr.length;i++){
        if(key==arr.A[i]){
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key){
    int l,mid,h;
    l=0;
    h=arr.length-1;

    while(l<=h){
        mid=(l+h)/2;
        if(key==arr.A[mid]){
            return mid;
        }
        else if(key<arr.A[mid]){
            h=mid-1;
        }
        else {
            l=mid+1;
        }
    }
    return -1;
}

int RBinSearch(int a[], int l, int h, int key){
    int mid;

    if(l<=h){
        mid=(l+h)/2;
        if(key==a[mid]){
            return mid;
        }
        else if (key<a[mid]){
            return RBinSearch(a,l,mid-1,key);
        }
        else {
            return RBinSearch(a,mid+1,h,key);
        }
    }
    return -1;
}

int Get(struct Array arr,int index){
    if(index>=0 && index<arr.length){
        return arr.A[index];
    }
    return -1;
}
void Set(struct Array *arr,int index,int x){
    if(index>=0 && index<arr->length){
        arr->A[index]=x;
    }
}

int Max(struct Array arr){
    int max=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++){
        if(arr.A[i]>max){
            max=arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr){
    int min=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++){
        if(arr.A[i]<min){
            min=arr.A[i];
        }
    }
    return min;
}

int Sum(struct Array arr){
    int s=0;
    int i;
    for(i=0;i<arr.length;i++){
        s+=arr.A[i];
    }
    return s;
}

float Avg(struct Array arr){
    return (float)Sum(arr)/arr.length;
}






void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void Reverse(struct Array *arr){
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--){
        swap(&arr->A[i],&arr->A[j]);
    }
}

int isSorted(struct Array arr){
    int i;
    for(i=0;i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1]){
            return 0;
        }
    }
    return 1;
}





//Set operations

struct Array* Union(struct Array *arr1,struct Array *arr2){
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct
Array));
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            arr3->A[k++]=arr2->A[j++];
        else{
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];

    arr3->length=k;
    arr3->size=10;

    return arr3;
}

struct Array* Intersection(struct Array *arr1,struct Array
*arr2){
    int i,j,k;
    i=j=k=0;
    
    struct Array *arr3=(struct Array *)malloc(sizeof(struct
Array));
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j])
            i++;
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else if(arr1->A[i]==arr2->A[j]){
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }

    arr3->length=k;
    arr3->size=10;

    return arr3;
}

struct Array* Difference(struct Array *arr1,struct Array
*arr2){
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct
Array));

    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else{
            i++;
            j++;
        }
    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];


    arr3->length=k;
    arr3->size=10;
    return arr3;
}




int main(){
    struct Array arr;
    int n,i;
    printf("Enter size of an array");
    scanf("%d",&arr.size);
    arr.A=(int *)malloc(arr.size*sizeof(int));
    arr.length=0;

    printf("Enter number of numbers");
    scanf("%d",&n);

    printf("Enter all Elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr.A[i]);
    }
    arr.length=n;

    printf("%d\n",LinearSearch(arr,2));
    printf("%d\n", BinarySearch(arr,15));
    Display(arr);

    return 0;
}
