class  Rect
{
public:
    Rect(float  l, float  w);                        //定义矩形接受长和宽
    float  getArea();                                      //矩形面积
protected:
    float  mLength;                                            //定义长
    float  mWidth;                                              //定义宽

};
Rect::Rect(float l, float w)
{
    mLength = l; mWidth = w;
}
float Rect::getArea()
{
    return mLength * mWidth;
}
class cubiod :protected Rect
{
public:
    cubiod(float mLength, float mWidth, float l) :Rect(mLength, mWidth)
    {
        this->l = l;
    }
    int l;
    int getVol()
    {
        return mLength * mWidth * l;
    }
    int Area()
    {
        return 2 * mLength * mWidth + 2 * l * mWidth + 2 * l * mLength;
    }
};
//cubiod::cubiod(float j, float k, float l) :Rect(mLength, mWidth)
//{
//    this->l = l;
//}



#include<iostream>
using  namespace  std;
int  main()
{
    int  j, k, l;
    cout << "请输入矩形的长和宽：";
    cin >> j >> k;                                                                                        //键盘接收长和宽
    Rect  r1(j, k);
    cout << "矩形的面积为：" << r1.getArea() << endl;
    cout << "请输入立方体的高：";
    cin >> l;                                                                                                  //接受高
    cubiod  c1(j, k, l);
    cout << "立方体体积为：" << c1.getVol() << endl;
    cout << "立方体表面积为：" << c1.Area();
    system("pause");
    return  0;

}



