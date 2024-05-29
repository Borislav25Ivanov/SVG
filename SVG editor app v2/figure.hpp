#ifndef __FIGURE_HPP
#define __FIGURE_HPP
#include <iostream>
class Figure{
    public:
    Figure() = default;
    virtual void Print()const =0;
    virtual void PrintToFile(std::ostream &out)const =0;
    virtual void  Translate(const int offx,const int offy) =0;
    virtual bool isInsideRect(int x,int y,int width,int height)const = 0;
    virtual bool isInsideCircle(int cx,int cy,int r)const = 0;
    enum class Type{
        Rectangle,
        Circle,
        Line,
    };
    Type type;
    
    protected:
    std::string fill;   
    std::string stroke;
    double strokeWidth = 0;
};
#endif 