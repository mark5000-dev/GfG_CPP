// Source code

#include <bits/stdc++.h>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void display() const = 0;
    virtual ~Shape() {}

    // Compare shapes by area
    bool operator>(const Shape& other) const {
        return this->area() > other.area();
    }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
    double perimeter() const override {
        return 2 * M_PI * radius;
    }
    void display() const override {
        cout << "Circle: radius = " << radius << "\n";
        cout << "Area = " << area() << "\n";
        cout << "Perimeter = " << perimeter() << "\n";
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
    double perimeter() const override {
        return 2 * (width + height);
    }
    void display() const override {
        cout << "Rectangle: width = " << width
             << ", height = " << height << "\n";
        cout << "Area = " << area() << "\n";
        cout << "Perimeter = " << perimeter() << "\n";
    }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}
    void display() const override {
        cout << "Square: side = " << area() << "\n";
        Rectangle::display();
    }
};

class Triangle : public Shape {
    double a, b, c;
public:
    Triangle(double x, double y, double z) : a(x), b(y), c(z) {}
    double area() const override {
        double s = perimeter() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    double perimeter() const override {
        return a + b + c;
    }
    void display() const override {
        cout << "Triangle: sides = " << a
             << ", " << b << ", " << c << "\n";
        cout << "Area = " << area() << "\n";
        cout << "Perimeter = " << perimeter() << "\n";
    }
};

class Ellipse : public Shape {
    double a, b;
public:
    Ellipse(double x, double y) : a(x), b(y) {}
    double area() const override {
        return M_PI * a * b;
    }
    double perimeter() const override {
        return M_PI * (3*(a + b) - sqrt((3*a + b)*(a + 3*b)));
    }
    void display() const override {
        cout << "Ellipse: axes = " << a << ", " << b << "\n";
        cout << "Area = " << area() << "\n";
        cout << "Perimeter = " << perimeter() << "\n";
    }
};
vector<Shape*> shapes;

void createCircle() {
    double r;
    cout << "Enter radius: ";
    cin >> r;
    shapes.push_back(new Circle(r));
}

void createRectangle() {
    double w, h;
    cout << "Enter width and height: ";
    cin >> w >> h;
    shapes.push_back(new Rectangle(w, h));
}

void createSquare() {
    double s;
    cout << "Enter side: ";
    cin >> s;
    shapes.push_back(new Square(s));
}

void createTriangle() {
    double a, b, c;
    cout << "Enter sides a, b, c: ";
    cin >> a >> b >> c;
    shapes.push_back(new Triangle(a, b, c));
}

void createEllipse() {
    double a, b;
    cout << "Enter axes a and b: ";
    cin >> a >> b;
    shapes.push_back(new Ellipse(a, b));
}

void displayAllShapes() {
    if (shapes.empty()) {
        cout << "No shapes created.\n";
        return;
    }
    for (size_t i = 0; i < shapes.size(); i++) {
        cout << "\nShape #" << i+1 << ":\n";
        shapes[i]->display();
    }
}

void compareShapes() {
    if (shapes.size() < 2) {
        cout << "Need at least 2 shapes.\n";
        return;
    }
    int i, j;
    cout << "Enter indices of shapes (1-based): ";
    cin >> i >> j;
    if (i < 1 || j < 1 || i > (int)shapes.size() || j > (int)shapes.size()) {
        cout << "Invalid indices.\n";
        return;
    }
    if (*shapes[i-1] > *shapes[j-1])
        cout << "Shape #" << i << " has larger area.\n";
    else
        cout << "Shape #" << j << " has larger or equal area.\n";
}

void shapeDashboard() {
    int choice;
    while (true) {
        cout << "\n--- Shape Calculator Menu ---\n";
        cout << "1. Create Circle\n";
        cout << "2. Create Rectangle\n";
        cout << "3. Create Square\n";
        cout << "4. Create Triangle\n";
        cout << "5. Create Ellipse\n";
        cout << "6. Display All Shapes\n";
        cout << "7. Compare Two Shapes\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createCircle(); break;
            case 2: createRectangle(); break;
            case 3: createSquare(); break;
            case 4: createTriangle(); break;
            case 5: createEllipse(); break;
            case 6: displayAllShapes(); break;
            case 7: compareShapes(); break;
            case 8:
                cout << "Exiting Shape Calculator.\n";
                return;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
int main() {
    shapeDashboard();
    // Cleanup
    for (Shape* s : shapes)
        delete s;
    return 0;
}