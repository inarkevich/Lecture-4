#include <iostream>

class Figure{
protected:
    int sides = 0;
    std::string name = "Фигура";
public:
    void getInfo(){ std::cout<< name <<": " <<sides<<std::endl;};
  
};
class Triangle:public Figure{
public:
    Triangle (){
        this->sides = 3;
        this->name = "Треугольник";
    }
};
class Square:public Figure{
public:
    Square(){
        this->sides = 4;
        this->name = "Четыреухгольник";
    }
};

int main(){
    Figure figure;
    std::cout<<"Количество сторон: "<<std::endl;
    figure.getInfo();
    Triangle triangle;
    triangle.getInfo();
    Square square;
    square.getInfo();

};