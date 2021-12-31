#include <iostream>

using namespace std;

class Rectangle {
    private:
        int length;
        int breadth;
    public:
        Rectangle(){
            length=0;
            breadth=0;
        }
        Rectangle(int l, int b){
            length=l;
            breadth=b;
        }
        int area(){
            return length*breadth;
        }
        int perimeter(){
            return 2*(length+breadth);
        }
        void setLength(int l){
            length = l;
        }
        void setBreadth(int b){
            breadth = b;
        }
        int getBreadth(){
            return breadth;
        }
        int getLength(){
            return length;
        }

        ~Rectangle(){
            cout<<"Destructor";
        }
};

template<class T>
/*Template class*/
class Arithmetic {
    private:
        T a;
        T b;
    public:
        Arithmetic(T a, T b);
        T add();
        T sub();
};

template<class T>
Arithmetic<T>::Arithmetic(T a, T b){
    this->a=a;
    this->b=b;
}

template<class T>
T Arithmetic<T>::add(){
    T c;
    c=a+b;
    return c;
}

template<class T>
T Arithmetic<T>::sub(){
    T c;
    c=a-b;
    return c;
}

int main(){
    Rectangle r(10,5);

    cout<<"Area "<<r.area()<<endl;
    cout<<"Perimeter "<<r.perimeter()<<endl;

    Arithmetic<float> ar(10.99,5.44);
    cout<<"Add "<<ar.add()<<endl;
    cout<<"Sub "<<ar.sub()<<endl;

    return 0;
};