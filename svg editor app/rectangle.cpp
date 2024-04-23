#include "rectangle.hpp"
#include <cstring>
    Rectangle::Rectangle(int x,int y, int height, int width,char fill[]){
        this->x = x;
        this->y = y;
        this->height = height;
        this->width = width;
        strcpy(this->fill,fill);
    }

    void Rectangle::Translate(int x,int y){
        this->x += x;
        this->y += y;
    }
    void Rectangle::PrintToConsole()const{
         std::cout<<"rectangle"<<' '<<this->x<<' '<<this->y<<' '<<this->width<<' '<<this->height<<' '<<this->fill;
    }
    void Rectangle::PrintToFile(std::ostream &out)const{
        out<<"<rect "<<"x=\""<<this->x<<"\""<<' '<<"y=\""<<this->y<<"\""<<' '<<"width=\""<<this->width<<"\""<<' '
           <<"height=\""<<this->height<<"\""<<' '<<"fill=\""<<this->fill<<"\""<<' '<<'/'<<'>';
    }