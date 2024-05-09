#include "line.hpp"
    Line::Line(double x1,double y1, double x2,double y2 , std::string stroke ,double strokeWidth){
        this->x1 = x1;
        this->x2 = x2;
        this->stroke = stroke;
        this->strokeWidth = strokeWidth;
        this->y1 = y1;
        this->y2 = y2;
    }
    Line::Line(){
        this->x1 =0;
        this->y1 =0;
        this->x2 =0;
        this->y2 =0;
        this->strokeWidth = 0.0;
    }
    void Line::Print()const{
        std::cout<<"line "<<this->x1<<' '<<this->y1<<' '<<this->x2<<' '<<this->y2;
    }
    void Line::PrintToFile(std::ostream& os)const{
        os<<"<line "<<"x1=\""<<this->x1<<"\""<<' '<<"y1=\""<<this->y1<<"\""<<' '
        <<"x2=\""<<this->x1<<"\""<<' '<<"y2=\""<<this->y1<<"\""<<' '<<' '<<"stroke=\""<<this->fill<<"\""<<' '<<'/'<<'>';
    }
    void Line::Translate(double offx, double offy){
        this->x1+=offx;
        this->x2+=offx;
        this->y1+=offy;
        this->y2+=offy;
    }