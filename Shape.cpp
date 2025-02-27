#include <iostream>
using namespace std;
#include <cmath>
#define PI 3.14159

class Shape {

protected:
    double area;
    double perimeter;

public:
    virtual void computeArea() {
        cout<<"Computing Area"<<endl;

    }
    virtual void computePerimeter() {
        cout<<"Computing Perimeter"<<endl;

    }
    // Making draw() a pure virtual function
    virtual void draw() = 0;
};

class Circle: public Shape {
    private: 
        double radius;
    
    public:
        // Constructor .....
        Circle(double r) {
            radius = r;
        }
    
        void computeArea() override {
            cout<<"Area: "<<PI*radius*radius<<endl;
        }
    
        void computePerimeter() override {
            cout<<"Perimeter: "<<2*PI*radius<<endl;
        }
        void draw() override {
            cout<<"Drawing a circle...."<<endl;
        }
};

class Triangle: public Shape {
    private:
        double a, b, c;
    
    public:
        // Constructor.....
        Triangle(double a, double b, double c) {
            this->a = a;
            this->b = b;
            this->c = c;
        }
        
        void computeArea() override {
            double s = (a + b + c) / 2; 
            area = sqrt(s * (s - a) * (s - b) * (s - c));
            cout<<"Area: "<<area<<endl;
        }
    
        void computePerimeter() override {
            perimeter = a + b + c;
            cout<<"Perimeter: "<<perimeter<<endl;
        }
    
        void draw() override {
            cout<<"Drawing Triangle..."<<endl;
        }
};

class Rectangle: public Shape {

    private:
        int l;
        int b;
    
    public:
        // Constructor....
        Rectangle(int l,int b) {
            this->l = l;
            this->b = b;
        }
    
        void computeArea() override {
            cout<<"Area: "<<l*b<<endl;
        }
        void computePerimeter() override {
            cout<<"Perimeter: "<<(2*(l+b))<<endl;
        }
        void draw() override {
            cout<<"Drawing a Rectangle..."<<endl;
        }   
};

class Square: public Shape {

private:
    int side;

public:
    //Constructor
    Square (int side) {
        this->side = side;
    }
    void computeArea() override {
        cout<<"Area: "<<side*side<<endl;
    }
    void computePerimeter() override {
        cout<<"Perimeter: "<<4*side<<endl;
    }
    void draw() override {
        cout<<"Drawing a Square...."<<endl;
    }
   
};
    
int main() {
    int ch;
    Shape* shape;
    cout<<"Choose a shape"<<endl;
    cout<<"1) Circle"<<endl<<"2) Triangle"<<endl<<"3) Rectangle"<<endl<<"4) Square"<<endl;
    cin>>ch;
    if(ch==1) {
        double r;
        cout<<"Enter Radius: ";
        cin>>r;
        Circle c(r);
        shape = &c;
    }
    else if(ch==2) {
        double a,b,c;
        cout<<"Enter three sides: ";
        cin>>a>>b>>c;
        Triangle t(a,b,c);
        shape = &t;
    }
    else if(ch==3) {
        int l,b;
        cout<<"Enter length and breadth: ";
        cin>>l>>b;
        Rectangle r(l,b);
        shape = &r;
    }
    else if(ch==4) {
        double side;
        cout<<"Enter a sides: ";
        cin>>side;
        Square sq(side);
        shape = &sq;
    }
    else {
        cout<<"Invalid Choice"<<endl;
        return 0;
    }

    shape->computeArea();
    shape->computePerimeter();
    shape->draw();

    delete shape;
    return 0;
    

} 

