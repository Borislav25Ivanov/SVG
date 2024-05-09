#ifndef __LINE_HPP
#define __LINE_HPP
#include "figure.hpp"
class Line:public Figure{
    public:
    Line();
    Line(double x1,double y1, double x2,double y2 , std::string stroke ,double strokeWidth);
    void Print()const;
    void PrintToFile(std::ostream& os)const;
    void Translate(double x, double y);
    private:
    double x1,x2,y1,y2;
};
#endif