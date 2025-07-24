#include <iostream>
using namespace std;

class Complex {
private:
    double r, i; 

public:
    // Constructor 
    Complex(double real = 0, double imag = 0) {
        r = real;
        i = imag;
        cout<<"Constructor called for: "<<r<<" + "<<i<<"i"<<endl;
    }

    // Destructor
    ~Complex() {
        cout<<"Destructor called for: "<<r<<" + "<<i<<"i"<<endl;
    }

    void input() {
        cout<<"Enter real Part: ";
        cin>>r;
        cout<<"Enter imaginary Part: ";
        cin>>i; 
    }

    void display() const {
        cout<<r<<" + "<<i<<"i"<<'\n';
    }

    void add(Complex c1, Complex c2) {
        r = c1.r + c2.r;
        i = c1.i + c2.i;
    }

    void subtract(Complex c1, Complex c2) {
        r = c1.r - c2.r;
        i = c1.i - c2.i;
    }

    void multiply(Complex c1, Complex c2) {
        r = c1.r * c2.r - c1.i * c2.i;
        i = c1.r * c2.i + c2.r * c1.i;
    }
};

int main() {
    // Constructor calls
    Complex c1, c2, result;
    
    cout<<endl<<"Complex Number 1"<<endl<<'\n';
    c1.input();
    cout<<"Complex Number 1: ";
    c1.display();

    cout<<endl<<"Complex Number 2"<<endl<<'\n';
    c2.input();
    cout<<"Complex Number 2: ";
    c2.display();

    result.add(c1, c2);
    cout<<endl<<"Addition : ";
    result.display();

    result.subtract(c1, c2);
    cout<<endl<<"Subtraction : ";
    result.display();

    result.multiply(c1, c2);
    cout<<endl<<"Multiplication : ";
    result.display();

    return 0;
}

