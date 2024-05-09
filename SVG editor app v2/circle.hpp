#ifndef __CIRCLE_HPP
#define __CIRCLE_HPP
#include "figure.hpp"
#include <iostream>
class Circle:public Figure{
    public:
    Circle();
    Circle(double cx ,double  cy, double r,std::string fill,std::string stroke,double strokeWidth);
    void Print()const;
    void PrintToFile(std::ostream &out)const;
    void  Translate(double x, double y);
    
    private:
    double cx,cy,r;
    
};

#endif