#ifndef __RECTANGLE_HPP
#define __RECTANGLE_HPP
#include "figure.hpp"
#include <sstream>
class Rectangle:public Figure{
    public:
    Rectangle();
    Rectangle(std::stringstream& sso);
    Rectangle(double x, double y,double width, double height,std::string fill, std::string stroke, double strokeWidth);
    void Print()const override;
    void PrintToFile(std::ostream& os)const override;
    void Translate(double offx, double offy) override;

    private:
    double x =0,y=0,width=0,height=0;
};
#endif