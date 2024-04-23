#ifndef __FIGURES_HPP
#define __FIGURES_HPP
#include <iostream>
class Figure{
    public:
    virtual void Translate(int x,int y);
    virtual void PrintToConsole()const;
    virtual void PrintToFile(std::ostream &out)const;
    protected:
    char fill [30];
};
#endif
