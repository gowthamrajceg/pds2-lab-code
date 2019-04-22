#include<iostream>
using namespace std;
class Shape
{
protected :
    float length,breadth;
public :
    void setData(float l,float b)
    {
        length = l;
        breadth = b;
    }
    void printData()
    {
        cout << "Length : " <<length <<" Breadth : "<< breadth << endl;
    }
};
class Area : public Shape
{
public:
    float area_shape()
    {
        return (length*breadth);
    }
};
int main()
{
    Area a;
    float l,b;
    cout << "Enter the length and breadth :" ;
    cin >> l >> b;
    a.setData(l,b);
    a.printData();
    cout << "Area is "<< a.area_shape();
    return 0;
}

