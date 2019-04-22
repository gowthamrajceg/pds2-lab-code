#include <iostream>
using namespace std;
class Shape {
  protected:
        int width, height;
  public:
    void setValues(int width, int height)
      {
          this->width=width;
          this->height=height;
      }
      virtual int area()
      {

      }
};

class Rectangle: public Shape {
  public:
    int area()
      {
          return width*height;
      }
};

class Triangle: public Shape {
  public:
    int area()
      {
          return width*height/2;
      }
};

int main () {
  Rectangle r;
  Triangle t;
  Shape *s1 = &r;
  Shape *s2 = &t;
  s1->setValues (4,5);
  s2->setValues (5,10);
  cout << s1->area() << endl;
  cout << s2->area() << endl;
  return 0;
}
