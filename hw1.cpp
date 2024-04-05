#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Shape 
{
protected:
    double x, y;

public:
    Shape(double x, double y) : x(x), y(y) {}
    virtual double area() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape 
{
    protected:
    double r;
    
    public:
    Circle(double x, double y, double r): Shape(x, y), r(r) {}
    virtual double area() const
    {
        return M_PI * r * r;
    }
    virtual ~Circle() {};
};


class Rectangle : public Shape 
{
    protected:
    double w, h;
    
    public:
    Rectangle(double x, double y, double w, double h) : Shape(x, y), w(w), h(h) {}
    virtual double area() const
    {
        return w*h;
    }
    virtual ~Rectangle() {};
};

int main() {
    vector<Shape*> V;
    Rectangle a(5, 7, 1, 2);
    V.push_back(&a);
    Circle b(0, 0, 2);
    V.push_back(&b);
    
    for(int i = 0; i < V.size(); i++)
    {
        double d = V[i] -> area();
        cout << d << endl;
    }
    return 0;
}