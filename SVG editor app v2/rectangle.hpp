#ifndef __RECTANGLE_HPP
#define __RECTANGLE_HPP
#include "figure.hpp"
#include <sstream>
class Rectangle:public Figure{
    public:
    Rectangle();
    Rectangle(std::stringstream& sso);
    Rectangle(int x, int y,int width, int height,std::string fill, std::string stroke, double strokeWidth);
    void Print()const override;
    void PrintToFile(std::ostream& os)const override;
    void Translate(const int offx,const int offy) override;
    bool isInsideRect(int x,int y,int width,int height)const override;
    bool isInsideCircle(int cx,int cy,int r)const override;

    private:
    int x =0,y=0,width=0,height=0;
    Type type = Figure::Type::Rectangle;
};
#endif