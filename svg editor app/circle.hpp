#ifndef __CIRCLE_HPP
#define __CIRCLE_HPP
#include "figure.hpp"

class Circle:public Figure{
    public:
        Circle(int cx, int cy, int r,char fill[]);
        void Translate(int x,int y);
        void PrintToConsole()const;
        void PrintToFile(std::ostream & out)const;
    private:
        int cx,cy,r;
        
};

#endif