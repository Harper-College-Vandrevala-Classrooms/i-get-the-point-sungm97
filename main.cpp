#include <iostream>
#include <cmath>

using namespace std;

class Point {
private:
    double x, y; 
public:
    Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    double operator-(const Point& other) const {
        return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
    }

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    Point operator/(const Point& other) const {
        return Point((x + other.x) / 2, (y + other.y) / 2);
    }

    void print() const {
        cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    Point p1(15, 27);
    Point p2(69.74, 4.20);

    cout << "Distance between p1 and p2: " << p1 - p2 << endl;
    cout << "Are point 1 and point 2 equal? " << (p1 == p2) << endl;
    cout << "Are point 1 and point 2 not equal? " << (p1 != p2) << endl;

    Point midpoint = p1 / p2;
    cout << "Midpoint between point 1 and point 2: ";
    midpoint.print();
    cout << endl;

    return 0;
}
