#include "line.hpp"
#include <cstring>
    Line::Line(int x1,int y1,int x2, int y2,char stroke[30]){
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
        strcpy(this->fill,stroke);
    }
    void Line::Translate(int x,int y){
        this->x1+=x;
        this->x2+=x;
        this->y1+=y;
        this->y2+=y;
    }
    void Line::PrintToConsole()const{
        std::cout<<"line "<<this->x1<<' '<<this->y1<<' '<<this->x2<<' '<<this->y2;
    }
    void Line::PrintToFile(std::ostream & out)const{
        out<<"<line "<<"x1=\""<<this->x1<<"\""<<' '<<"y1=\""<<this->y1<<"\""<<' '
        <<"x2=\""<<this->x1<<"\""<<' '<<"y2=\""<<this->y1<<"\""<<' '<<' '<<"stroke=\""<<this->fill<<"\""<<' '<<'/'<<'>';
    
    }