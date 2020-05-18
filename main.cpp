#include <iostream>

class A{
public:
    int a,b;
    A(int num1, int num2): a(num1), b(num2){
        std::cout<<"constructor of A called"<<std::endl;
    }

    virtual ~A() {
        std::cout<<"destructor of A called"<<std::endl;
    }

    int add() const{
        return this->a + this->b;
    }
};

class B{
public:
    int a,b;
    B(int a, int b) : a(a), b(b) {
        std::cout<<"constructor of B called"<<std::endl;
    }

    virtual ~B() {
        std::cout<<"destructor of B called"<<std::endl;
    }

    virtual int subtract() const{
        return this->a - this->b;
    }
};

class C: public A, public B{
public:
    C(int a, int b): A(a, b), B(a, b){
        std::cout<<"constructor of C called"<<std::endl;
    }

    virtual ~C() {
        std::cout<<"destructor of C called"<<std::endl;
    }

    int multiply(){
      return this->A::a * this->A::b;
    }

    int subtract() const override {
        return this->B::b - this->B::a;
    }
};

int main(){
    A a(12,34);
    B b(12,34);
    C c(12,34);

    std::cout<<a.add()<<std::endl;

    std::cout<<b.subtract()<<std::endl;

    std::cout<<c.subtract()<<std::endl;

    std::cout<<c.multiply()<<std::endl;

}