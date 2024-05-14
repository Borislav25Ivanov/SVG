#ifndef __LINE_HPP
#define __LINE_HPP
#include "figure.hpp"
#include <sstream>
class Line:public Figure{
    public:
    Line();
    Line(std::stringstream& sso);
    Line(double x1,double y1, double x2,double y2 , std::string stroke ,double strokeWidth);
    void Print()const;
    void PrintToFile(std::ostream& os)const;
    void Translate(double x, double y);
    private:
    double x1=0,x2=0,y1=0,y2=0;
};
#endif