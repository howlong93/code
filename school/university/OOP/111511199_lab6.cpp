#include <iostream>

using namespace std;

class Complex {
  private:
    int real, imagine;
  public:
    Complex () {
        real = imagine = 0;
    }

    Complex (int x, int y) {
        real = x, imagine = y;
    }

    friend const Complex operator+ (const Complex &x, const Complex &y);
    friend const Complex operator- (const Complex &x, const Complex &y);
    friend const Complex operator* (const Complex &x, const Complex &y);
    friend const Complex operator! (const Complex &x);
    friend bool operator== (const Complex &x, const Complex &y);
    friend bool operator!= (const Complex &x, const Complex &y);
    friend istream& operator>> (istream& input, Complex &x);
    friend ostream& operator<< (ostream& output, const Complex &y);
};

int main() {
    Complex a, b;
    cout << "input a & b: " << endl;
    cin >> a >> b;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "conjugate of a = " << !a << endl;

    if (a == b)
        cout << "a is equal to b." << endl;
    if (a != b)
        cout << "a is not equal to b." << endl;

    return 0;
}

const Complex operator+ (const Complex &x, const Complex &y) {
    Complex temp (x.real + y.real, x.imagine + y.imagine);
    return temp;
}

const Complex operator- (const Complex &x, const Complex &y) {
    Complex temp (x.real - y.real, x.imagine - y.imagine);
    return temp;
}

const Complex operator* (const Complex &x, const Complex &y) {
    Complex temp;
    temp.real = x.real*y.real - x.imagine*y.imagine;
    temp.imagine = x.real*y.imagine + x.imagine*y.real;
    return temp;
}

const Complex operator! (const Complex &x) {
    Complex temp (x.real, -x.imagine);
    return temp;
}

bool operator== (const Complex &x, const Complex &y) {
    return (x.real == y.real && x.imagine == y.imagine);
}

bool operator!= (const Complex &x, const Complex &y) {
    return (x.real != y.real || x.imagine != y.imagine);
}

istream& operator>> (istream &input, Complex &x) {
    input >> x.real >> x.imagine;
    return input;
}

ostream& operator<< (ostream& output, const Complex &x) {
    output << x.real;
    if (x.imagine > 0) cout << "+";
    cout << x.imagine << "i";
    return output;
}
