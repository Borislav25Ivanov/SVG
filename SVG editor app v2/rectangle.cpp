#include "rectangle.hpp"
    Rectangle::Rectangle(double x, double y,double width, double height,std::string fill, std::string stroke, double strokeWidth){
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->stroke = stroke;
        this->strokeWidth = strokeWidth;
        this->fill = fill;
    }
    Rectangle::Rectangle(){

    }
    void Rectangle::Print()const{
        std::cout<<"rectangle"<<' '<<this->x<<' '<<this->y<<' '<<this->width<<' '<<this->height<<' '<<this->fill;
    }
    void Rectangle::PrintToFile(std::ostream& os)const{
        os<<"<rect "<<"x=\""<<this->x<<"\""<<' '<<"y=\""<<this->y<<"\""<<' '<<"width=\""<<this->width<<"\""<<' '
        <<"height=\""<<this->height<<"\""<<' '<<"fill=\""<<this->fill<<"\""<<' '<<'/'<<'>';
    }
    void Rectangle::Translate(double offx, double offy){
        this->x+=offx;
        this->y+=offy;
    }
