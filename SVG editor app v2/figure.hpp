#ifndef __FIGURE_HPP
#define __FIGURE_HPP
#include <iostream>
class Figure{
    public:
    Figure();
    virtual void Print()const =0;
    virtual void PrintToFile(std::ostream &out)const =0;
    virtual void  Translate(double offx, double offy) =0;
    
    protected:
    std::string fill;   
    std::string stroke;
    double strokeWidth;
};
#endif 