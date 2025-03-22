//按以下提示信息，由基类的设计和测试开始，逐渐地完成各个类的设计，并且完成要求的功能。
//
//①设计一个Point（点）类，包含数据成员x、y（坐标点）。
//
//②以Point为基类，派生出一个Circle（圆）类，增加数据成员r（半径）。
//
//③以Circle类为直接基类，派生出一个Cylinder（圆柱体）类，再增加数据成员h（高）。
//
//请设计出各类中基本的成员函数，包括构造函数、设置数据成员和获取数据成员的函数，以及计算圆的周长和面积、
// 计算圆柱体的表面积和体积的函数，使程序正确运行。
//
//pi = 3.1415926
#include<iostream>
#include<iomanip>
using namespace std;
const double pi = 3.1415926;
class Point
{
public:
  double x, y;
    Point()
    {

    }
    Point(double x, double y)
    {
        this->x = x; 
        this->y = y;
    }
    void SetPoint(double a, double b)
    {
        x = a; 
        y = b;
    }
    void Show()
    {
        cout << x << "," << y << endl;
    }
    double GetX(void)
    {
        return x;
    }
    double GetY(void)
    {
        return y;
    }
};
class Circle : public Point
{
public:
    double r;
    Circle(){}
    Circle( double x, double y,double r) :Point(x, y)
    {
        this->r = r;
    }
    double Girth(void)
    {
        return 2 * pi * r;
    }
    double Area(void)
    {
        return pi * r * r;
    }
    void show()
    {
        cout << x << "," << y << endl;
        cout << r << endl;
    }
};

class Cylinder :public Circle
{
public:
    
    double h;
    void SetCylinder(Circle c, double h)
    {
        x = c.x;
        y = c.y;
        r = c.r;
        this->h = h;
    }
    double Area()
    {
        return 2 * pi * r * r + 2 * pi * r * h;
    }
    double Volumn()
    {
        return pi * r * r * h;
    }
    void show()
    {
        cout << x << "," << y << endl;
        cout << r << endl;
        cout << h << endl;
    }
};





int  main()
{
    double  x, y;
    cin >> x >> y;//若输入：10  20
    Point  p1(x, y);
    p1.SetPoint(x + 10, y + 5);
    cout << fixed << setprecision(1);
    p1.Show();//单独占一行输出：10,20
    Circle  c1(p1.GetX(), p1.GetY(), 20);
    c1.Show();//输出两行：圆心一行，半径一行
    cout << "c1的周长是：" << c1.Girth() << endl;//一个数据一行
    cout << "c1的面积是：" << c1.Area() << endl;//一个数据一行
    Cylinder  cy1;
    cy1.SetCylinder(c1, 10.5);
    cy1.Show();//输出三行：圆心一行，半径一行，高一行
    cout << "cy1的表面积是：" << cy1.Area() << endl;//一个数据一行
    cout << "cy1的体积是：" << cy1.Volumn() << endl;//一个数据一行
    return  0;
}

