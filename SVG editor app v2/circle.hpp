#ifndef __CIRCLE_HPP
#define __CIRCLE_HPP
#include "figure.hpp"
#include <sstream>
class Circle:public Figure{
    public:
    Circle();
    Circle(std::stringstream& sso);
    Circle(int cx ,int  cy, int r,std::string fill,std::string stroke,double strokeWidth);
    void Print()const;
    void PrintToFile(std::ostream &out)const;
    void  Translate(const int x,const int y);
    bool isInsideRect(int x,int y,int width, int height)const override;
    bool isInsideCircle(int cx, int cy,int r)const override;
    
    private:
    int cx=0,cy=0,r=0;
    Type Type = Figure::Type::Circle;
    
};

#endif