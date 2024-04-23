#ifndef __LINE_HPP
#define _LINE_HPP
#include "figure.hpp"
class Line:public Figure{
    public:
        Line(int x1,int y1,int x2, int y2,char stroke[30]);
        void Translate(int x,int y);
        void PrintToConsole()const;
        void PrintToFile(std::ostream & out)const;
    private:
        int x1,y1,x2,y2;
};

#endif