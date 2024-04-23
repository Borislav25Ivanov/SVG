#include "circle.hpp"
#include <cstring>
    Circle::Circle(int cx,int cy,int r,char fill[]){
        this->cx = cx;
        this->cy =cy;
        this->r = r;
        strcpy(this->fill,fill);
    }
    void Circle::Translate(int x,int y){
        this->cx+=x;
        this->cy+=y;
    }
    void Circle::PrintToConsole()const{
        std::cout<<"cirlce "<<this->cx<<' '<<this->cy<<' '<<this->r<<' '<<this->fill;
    }
    void Circle::PrintToFile(std::ostream &out)const{
        out<<"<circle "<<"cx=\""<<this->cx<<"\""<<' '<<"cy=\""<<this->cy<<"\""<<' '<<"r=\""<<this->r<<"\""<<' '
           <<"fill=\""<<this->fill<<"\""<<' '<<'/'<<'>';
    }