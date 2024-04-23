#ifndef __RECTANGLE_HPP
#define __RECTANLGE_HPP
#include "figure.hpp"
class Rectangle:public Figure{
    public:
    Rectangle(int x,int y, int height, int width,char fill[]);
    void Translate(int x,int y);
    void PrintToConsole()const;
    void PrintToFile(std::ostream &out)const;
    private:
    int x,y,height,width;

};
#endif