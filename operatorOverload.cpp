#include <iostream>
using namespace std;

class Counter {
private:
    int value;
public:
    Counter(int v = 0) : value(v) {}

    Counter& operator++() {
        ++value;
        return *this;
    }

    Counter operator++(int) {
        Counter temp = *this;
        value++;
        return temp;
    }

    void display() const {
        cout << "Counter: " << value << endl;
    }
};

class Point {
private:
    int x, y;

public:
    Point(int xVal, int yVal) : x(xVal), y(yVal) {}

    bool operator==(const Point& other) const {
        return (x == other.x) && (y == other.y);
    }
};

int main() {
    Counter c(5);
    cout << "initial value: ";
    c.display();

    ++c;
    cout << "prefix increment: ";
    c.display();

    c++;
    cout << "postfix increment: ";
    c.display();

    Point x(1,1);
    Point y(1,1);

    if(x==y)
    {
        cout<<"x equals y"<<endl;
    }
    else
    {
        cout<<"x does not equal y"<<endl;
    }
    return 0;
}
