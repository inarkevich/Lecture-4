#include <iostream>

class Figure{
protected:
    std::string name = "Фигура";
    int sides = 0;
public:
    virtual void getDetails(){};// Здесь 0 убран, иначе не удастся создать объект класса "Фигура"
    virtual void getName(){ std::cout<< name <<": " <<std::endl;}; 
    virtual bool checkCorrect(){return true;}; 
    virtual void getSize(){ std::cout<<"Количество сторон: " <<sides<<std::endl;}; 

};
class Triangle:public Figure{
protected: 
    int a = 0;
    int b = 0;
    int c = 0;
    int A = 0;
    int B = 0;
    int C = 0;
public:
    Triangle (int a, int b, int c, int A, int B, int C){
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
        this->name = "Треугольник";
        this->sides = 3;
    }
    bool checkCorrect() override{
        bool angleSum = (A+B+C==180); //проверяем что все углы = 180 градусам
        bool sides = (a+b>c)&&(b+c>a)&&(a+c>b); // проверяем условие неравенства сторон треугольника
        return angleSum && sides;
    }
    void getDetails()override{
        std::cout<<"Стороны: a="<<a<<" b="<<b<<" c="<<c<<std::endl;
        std::cout<<"Углы: A="<<A<<" B="<<B<<" C="<<C<<std::endl;
    }
};
class Quadril:public Figure{
protected: 
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int A = 0;
    int B = 0;
    int C = 0;
    int D = 0;
public:
    Quadril(int a, int b, int c, int d, int A, int B, int C, int D){
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
        this->name = "Четыреухгольник";
        this->sides = 4;
    }
        bool checkCorrect() override{
        bool angleSum = (A+B+C+D==360); //проверяем что все углы = 360 градусам
        return angleSum;
    }
    void getDetails() override{
        std::cout<<"Стороны: a="<<a<<" b="<<b<<" c="<<c<<" d="<<d<<std::endl;
        std::cout<<"Углы: A="<<A<<" B="<<B<<" C="<<C<<" D="<<D<<std::endl;
    }
};

class RightTriangle:public Triangle{
public: 
    RightTriangle(int a, int b, int c,int A, int B):
    Triangle(a, b, c, A,B,90){
        this->name = "Прямоугольный Треугольник";
    }
    bool checkCorrect() override{
        bool angleSum = (A==90||B==90||C==90)&&(A+B+C==180); //проверяем что все углы = 180 градусам и что хотя бы один равен 90
        bool sides = (a+b>c)&&(b+c>a)&&(a+c>b); // проверяем условие неравенства сторон треугольника
        return angleSum && sides;   
    }
};

class IsosTriangle:public Triangle{
public: 
    IsosTriangle(int a, int b, int A, int B):
    Triangle(a,b,a,  A, B, A){
    this->name = "Равнобедренный Треугольник";
    }
    bool checkCorrect() override{
        bool angleSum = (A==B||B==C||C==A)&&(A+B+C==180); //проверяем что все углы = 180 градусамб и что хотя бы два попарно равны
        bool sides = (a==b||b==c||c==a)&&(a+b>c)&&(b+c>a)&&(a+c>b); // проверяем условие неравенства сторон треугольника и что хотя бы две попарно равны
        return angleSum && sides;
    }
}; 

class EquilTriangle:public Triangle{
public: 
    EquilTriangle(int a):
    Triangle(a, a, a, 60,60,60){
    this->name = "Равносторонний Треугольник";
    }
    bool checkCorrect() override{
        bool angleSum = (A==60 && B==60 && C==60); //проверяем что каждый угол = 60 градусам
        bool sides = (a==b==c)&&(a+b>c)&&(b+c>a)&&(a+c>b); // проверяем условие неравенства сторон треугольника и что стороны равны
        return angleSum && sides;
    }
};

class Parallel : public Quadril{
public:
    Parallel(int a, int b, int A, int B):
    Quadril(a,b,a,b, A, B,A,B){
    this->name = "Параллелограмм";
    };
    bool checkCorrect() override{
        bool angleSum = (A+B+C+D==360)&&(A==C&&B==D); //проверяем что все углы = 360 градусам и что углы попарно равны
        bool sides = (a==c && b==d); // проверяем что стороны попарно равны;
        return angleSum && sides;
    }
};

class Rectangle: public Parallel{
public:
    Rectangle (int a, int b):Parallel(a, b, 90,90){
    this->name = "Прямоугольник";
    }
    bool checkCorrect() override{
        bool angleSum = (A==90&&B==90&&C==90&&D==90); //проверяем что каждый угол = 90
        bool sides = (a==c && b==d); // проверяем что стороны попарно равны;
        return angleSum && sides;
    }
};

class Rhombus:public Parallel{
public:
    Rhombus(int a, int A, int B):Parallel(a,a,A,B){
    this->name = "Ромб";
    }
    bool checkCorrect() override{
        bool angleSum = (A+B+C+D==360)&&(A==C&&B==D); //проверяем что все углы = 360 и углы попарно равны
        bool sides = (a==c==b==d); // проверяем что все стороны равны;
        return angleSum && sides;
    }
};

class Square : public Rectangle{
public:
    Square(int a):Rectangle(a,a){
    this->name = "Квадрат";
    }
     bool checkCorrect() override{
        bool angleSum = (A==90&&B==90&&C==90&&D==90); //проверяем что каждый угол = 90
        bool sides = (a==c==b==d); // проверяем что все стороны равны;
        return angleSum && sides;
    }
};

void print_info(Figure* anyFigure){
    anyFigure->getName();
    if(anyFigure->checkCorrect()){
        std::cout<<"Правильная"<<std::endl;
    }else{
        std::cout<<"Неправильная"<<std::endl;
    }
    anyFigure->getSize();
    anyFigure->getDetails();
};

int main(){
    Figure figure;
    print_info(&figure);
    Triangle triangle(10,20,30,50,60,70);
    print_info(&triangle);
    RightTriangle rightTriangle (10,20,30,50,60);
    print_info(&rightTriangle);
    IsosTriangle isosTriangle(10,20,50,60);
    print_info(&isosTriangle);
    EquilTriangle equilTriangle(30);
    print_info(&equilTriangle);
    Quadril quadril(10,20,30,40,50,60,70,80);
    print_info(&quadril);
    Parallel parallel(20,30,30,40);
    print_info(&parallel);
    Rectangle rectangle(10,20);
    print_info(&rectangle);
    Rhombus rhombus(30,30,40);
    print_info(&rhombus);
    Square square(20);
    print_info(&square);
};