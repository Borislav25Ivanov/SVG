#include "circle.hpp"
#include <cmath>
    Circle::Circle(int cx ,int  cy, int r,std::string fill,std::string stroke,double strokeWidth)
    {
        
        this->cx = cx;
        this->cy = cy;
        this->r = r;
        this->stroke = stroke;
        this->strokeWidth = strokeWidth;
        this->fill = fill;
    }
    Circle::Circle(){

    }
    Circle::Circle(std::stringstream& sso){
        
        std::string word;
        while (sso>>word)
        {
            if(word.back() != '>'){
        
                if(word.find("cx") != std::string::npos){
                    for(char c : word){
                        if(c>='0' && c<='9'){
                            cx*=10;
                            cx+=c-'0';
                        }
                    }
                }
                if(word.find("cy") != std::string::npos){
                    
                    for(char c : word){
                        if(c>='0' && c<='9'){
                            cy*=10;
                            cy+=c-'0';
                        }
                    }
                }
                if(word.front() == 'r'){
                    for(char c : word){
                        if(c>='0' && c<='9'){
                            r*=10;
                            r+=c-'0';
                        }
                    }
                }
                
                
                if(word.find("stroke") != std::string::npos && word.find("stroke-width") == std::string::npos){
                    stroke = word.substr(word.find("\"")+1);
                    stroke.pop_back();
                }
                if(word.front() == 'f'){
                    fill = word.substr(word.find("\"")+1);
                    fill.pop_back();
                } 

                if(word.find("stroke-width") != std::string::npos ){
                    for(char c : word){
                        if(c>='0' && c<='9'){
                            strokeWidth*=10;
                            strokeWidth+=c-'0';
                        }
                    }
                }                  
            }
            else{
                break;
            } 
        }   
    }
            
    
    void Circle::PrintToFile(std::ostream &out)const{
        out<<"<circle "<<"cx=\""<<this->cx<<"\""<<' '<<"cy=\""<<this->cy<<"\""<<' '<<"r=\""<<this->r<<"\""<<' '
           <<"fill=\""<<this->fill<<"\""<<' '<<"stroke=\""<<this->stroke<<"\""<<' '<<"stroke-width=\""<<this->strokeWidth<<"\""<<' '<<'/'<<'>';
    }
    void Circle::Print()const{
        std::cout<<"circle "<<this->cx<<' '<<this->cy<<' '<<this->r<<' '<<this->fill<<' '<<this->stroke<<' '<<this->strokeWidth;
    }
    void Circle::Translate(const int offx,const int offy){
        this->cx+=offx;
        this->cy+=offy;
    }
    bool Circle::isInsideRect(int x,int y,int width, int height)const{
        return((cx-r>x) && (cy - r>y) && (cy+r-y<height) && (cx+r-x<width));
    }
    bool Circle::isInsideCircle(int cx, int cy,int r)const {
        return(std::sqrt((this->cx - cx)*(this->cx - cx) + (this->cy - cy)*(this->cy - cy))<=r-this->r);
    }
