#include <iostream>
using namespace std;

typedef double (*FUNC)(double);

double integrate(FUNC f, double a, double b) {
    // sum records the areas of the individual rectangles (Reimann sum) and delta is the width of each rectangle
    double sum = 0, delta = 0.0001, x = a;
    // while the rectangle's horizontal position is between point a and b
    while (x < b) {
        sum += f(x) * delta; // calculates the area and adds it to the sum using f(x) as the height of the rectangle
        x += delta; // moves to the next rectangle's horizontal position (x)
    }
    return sum; 
}

double line(double x) {
    return x; // returns function y = x
}

double square(double x) {
    return x*x; // returns function y = x^(2)
}

double cube(double x) {
    return x*x*x; // returns function y = x^(3)
}

int main() {
   cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;     
   cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl; 
   cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;   
   return 0;
}