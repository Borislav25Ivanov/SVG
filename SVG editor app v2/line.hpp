#ifndef __LINE_HPP
#define __LINE_HPP
#include "figure.hpp"
#include <sstream>
class Line:public Figure{
    public:
    Line();
    Line(std::stringstream& sso);
    Line(int x1,int y1, int x2,int y2 , std::string stroke ,double strokeWidth);
    void Print()const;
    void PrintToFile(std::ostream& os)const;
    void Translate(const int x,const int y);
    bool isInsideRect(int x,int y,int width,int height)const override;
    bool isInsideCircle(int cx,int cy,int r)const override;
    private:
    int x1=0,x2=0,y1=0,y2=0;
    Type type = Figure::Type::Line;
};
#endif