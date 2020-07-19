#include <iostream>
#include <cmath>


using namespace std;

class Figure {
    public:
    virtual float area() = 0;
  
};

class Parallelogram : virtual public Figure {
    protected:
    float width;
    float length;
    float height;
    public:
    Parallelogram (float w, float l) {
        width = w;
        length = l;
    }
    Parallelogram (float w, float l, float h) {
        width = w;
        length = l;
        height = h;
    }
    Parallelogram (float w) {
        width = w;
    }
    
    float area () override {
        cout << "Parallelogram area with " << width << " width and " << height << " height is: " << width*height << endl;
    }
};

class Circle : virtual public Figure {
    private:
    float radius;
    float PI = 3.14;
    public:
    Circle (float r) {
        radius = r;
    }
    float area () override {
        cout << "Circle area with " << radius << " radius is: " << pow(radius, 2) * PI << endl;
    }
    
};

class Rectangle: public Parallelogram {
    public:
    Rectangle (float w, float l) : Parallelogram (w, l) {}
    float area() override {
        cout << "Rectangle area with " << width << " width and " << length << " length is: " << width*length << endl;
    }
};

class Square : public Parallelogram {

    public:
    Square (float w) : Parallelogram (w) {}
    
    float area () override {
        cout << "Square area with " << width << " width is: " << width*width << endl;
       
    }
};

class Rhombus : public Parallelogram {
    private:
    int height;
    public:
    Rhombus (float w, float h) : Parallelogram (w) {
        height = h;
    }
    float area () override {
        cout << "Rhombus area with " << width << " width and " << height << " height is: " << width*height << endl;
    }
};


int main()
{
    /*Parallelogram p(10, 0, 12);
    p.area();
    Circle c(20);
    c.area();
    Rectangle r(10, 15);
    r.area();
    Square s(13);
    s.area();
    Rhombus rh(12, 14);
    rh.area();*/
    
    Parallelogram p(10, 0, 12);
    Figure *f1 = &p;
    f1->area();
    
    Circle c(20);
    Figure *f2 = &c;
    f2->area();
    
    Rectangle r(10, 15);
    Figure *f3 = &r;
    f3->area();
  
    Square s(13);
    Figure *f4 = &s;
    f4->area();
    
    Rhombus rh(12, 14);
    Figure *f5 = &rh;
    f5->area();
    
    

    return 0;
}
