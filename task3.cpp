#include <iostream>

class Figure{
protected:
    std::string name = "Фигура";
    int sides = 0;
public:
    virtual void getDetails(){};// Здесь 0 убран, иначе не удастся создать объект класса "Фигура"
    virtual void getName(){ std::cout<< name <<": " <<std::endl;}; 
    virtual void checkCorrect(){std::cout<<"Правильная"<<std::endl;}; 
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
    void checkCorrect() override{
        int angleSum = A+B+C;
        if(angleSum==180){
            std::cout<<"Правильная"<<std::endl;
        }
        else{std::cout<<"Неправильная"<<std::endl;}
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
    void checkCorrect() override{
        int angleSum = A+B+C+D;
        if(angleSum==360){
            std::cout<<"Правильная"<<std::endl;
        }
        else{std::cout<<"Неправильная"<<std::endl;}
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
};

class IsosTriangle:public Triangle{
public: 
    IsosTriangle(int a, int b, int A, int B):
    Triangle(a,b,a,  A, B, A){
    this->name = "Равнобедренный Треугольник";
    }
}; 

class EquilTriangle:public Triangle{
public: 
    EquilTriangle(int a):
    Triangle(a, a, a, 60,60,60){
    this->name = "Равносторонний Треугольник";
    }
};

class Parallel : public Quadril{
public:
    Parallel(int a, int b, int A, int B):
    Quadril(a,b,a,b, A, B,A,B){
    this->name = "Параллелограмм";
    };
};

class Rectangle: public Parallel{
public:
    Rectangle (int a, int b):Parallel(a, b, 90,90){
    this->name = "Прямоугольник";
    }
};

class Rhombus:public Parallel{
public:
    Rhombus(int a, int A, int B):Parallel(a,a,A,B){
    this->name = "Ромб";
    }
};

class Square : public Rectangle{
public:
    Square(int a):Rectangle(a,a){
    this->name = "Квадрат";
    }
};

void print_info(Figure* anyFigure){
    anyFigure->getName();
    anyFigure->checkCorrect();
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