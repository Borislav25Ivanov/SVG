#ifndef __RECTANGLE_HPP
#define __RECTANGLE_HPP
#include "figure.hpp"
class Rectangle:public Figure{
    public:
    Rectangle();
    Rectangle(double x, double y,double width, double height,std::string fill, std::string stroke, double strokeWidth);
    void Print()const override;
    void PrintToFile(std::ostream& os)const override;
    void Translate(double offx, double offy) override;

    private:
    double x,y,width,height;
};
#endif