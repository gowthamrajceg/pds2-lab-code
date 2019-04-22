#include<iostream>
using namespace std;
class Amazon
{
protected:
    int Amazon_price,A_ship;
public:
    void getAp()
    {
        cout << "Enter the Item price in Amazon :" << endl;
        cin >> Amazon_price;
        cout << "Enter the shipping charge :" << endl;
        cin >> A_ship;
    }
};
class Flipkart
{
protected:
    int Flipkart_price,F_ship;
public:
    void getFp()
    {
        cout << "Enter the Item price in Flipkart :" << endl;
        cin >> Flipkart_price;
        cout << "Enter the shipping charge :" << endl;
        cin >> F_ship;
    }
};
class Best : public Amazon,public Flipkart
{
private:
    int Amazon_total,Flipkart_total;
public:
    void display()
    {
        Amazon_total = Amazon_price + A_ship;
        Flipkart_total = Flipkart_price + F_ship;
        cout << "Total Price in Amazon :" << Amazon_total << endl;
        cout << "Total Price in Flipkart :" << Flipkart_total << endl;
        if(Amazon_total>Flipkart_total)
        {
            cout << "Flipkart Price is cheap.. Go for it :)";
        }
        else
        {
            cout << "Amazon Price is cheap.. Go for it :)";
        }
    }
};
int main()
{
    Best b;
    b.getAp();
    b.getFp();
    b.display();
    return 0;
}


