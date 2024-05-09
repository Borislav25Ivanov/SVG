#include "circle.hpp"
    Circle::Circle(double cx ,double  cy, double r,std::string fill,std::string stroke,double strokeWidth)
    {
        this->cx = cx;
        this->cy = cy;
        this->r = r;
        this->stroke = stroke;
        this->strokeWidth = strokeWidth;
        this->fill = fill;
    }
    Circle::Circle(){
        this->cx = 0;
        this->cy = 0;
        this->r = 0;
        this->strokeWidth = 0.0;

    }
    void Circle::PrintToFile(std::ostream &out)const{
        out<<"<circle "<<"cx=\""<<this->cx<<"\""<<' '<<"cy=\""<<this->cy<<"\""<<' '<<"r=\""<<this->r<<"\""<<' '
           <<"fill=\""<<this->fill<<"\""<<' '<<'/'<<'>';
    }
    void Circle::Print()const{
        std::cout<<"circle "<<this->cx<<' '<<this->cy<<' '<<this->r<<' '<<this->fill;
    }
    void Circle::Translate(double offx, double offy){
        this->cx+=offx;
        this->cy+=offy;
    }