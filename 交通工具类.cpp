#include  <iostream>
using  namespace  std;
class  vehicle
{
protected:
    double  speed;        //速度,公里/小时
    int  wheels;          //轮子数
    double  weight;  //重量
public:
    vehicle(double  speed = 80, int  wheels = 4, double  weight = 1000);
    virtual  void  show(void) = 0;
};
vehicle::vehicle(double, int, double)
{
    speed = 80;  wheels = 4;   weight = 1000;
}


class  car : public  vehicle
{
    int  passenger_load;
public:
    car(double  speed = 80, int  wheels = 4, double  weight = 1000, int  passenger_load = 4);
    virtual  void  show(void);
};
car::car(double, int, double, int)
{
    speed = 80;  wheels = 4;   weight = 1000; passenger_load = 4;
}


void  car::show(void)
{
    cout << "Car  message\n";
    cout << speed << "  " << wheels << "  " << weight << "  " << passenger_load << endl;
}
class  truck : public  vehicle
{
    double  rated_load;      //额定载重
public:
    truck(double  speed = 80, int  wheels = 4, double  weight = 2500, double  rated_load = 3000);
    virtual    void  show(void);
};
truck::truck(double, int, double, double)
{
    speed = 80;  wheels = 4;   weight = 2500; rated_load = 3000;
}
void  truck::show(void)
{
    cout << "truck message\n";
    cout << speed << " " << wheels << " " << weight << " " << rated_load << endl;
}

class  boat : public  vehicle
{
    char  kind;              //轮船类别，如客轮为'k'
public:
    boat(double  speed = 30, int  wheels = 0, double  weight = 12000, char  kind = 'k');
    virtual    void  show(void);
};
boat::boat(double, int, double, char)
{
    speed = 30;  wheels = 0;   weight = 12000; kind = 'k';
}
void  boat::show(void)
{
    cout << "boat message\n";
    cout << speed << " " << wheels << " " << weight << " " << kind << endl;
}

int  main()
{
    vehicle* unicycle;    car* BMW;
    unicycle = new  car;      unicycle->show();
    BMW = (car*)unicycle;      BMW->show();
    delete  unicycle;
    unicycle = new  truck;      unicycle->show();
    delete  unicycle;
    unicycle = new  boat;      unicycle->show();
    delete  unicycle;
    return  0;
}