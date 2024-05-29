#include "rectangle.hpp"
#include <cmath>
    Rectangle::Rectangle(int x, int y,int width, int height,std::string fill, std::string stroke, double strokeWidth){
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
    Rectangle::Rectangle(std::stringstream& sso){
        std::string word;
        while (sso>>word)
            {
                if(word.back() != '>'){
           
                    if(word.front() == 'x'){                      
                        for(char c : word){
                            if(c>='0' && c<='9'){
                                x*=10;
                                x+=c-'0';
                            }
                        }
                    }
                    if(word.front() == 'y'){
                        for(char c : word){
                            if(c>='0' && c<='9'){
                                y*=10;
                                y+=c-'0';
                            }
                        }
                    }
                    if(word.front() == 'w'){
                        for(char c : word){
                            if(c>='0' && c<='9'){
                                width*=10;
                                width+=c-'0';
                            }
                        }
                    }
                    if(word.front() == 'h'){
                        for(char c : word){
                            if(c>='0' && c<='9'){
                                height*=10;
                                height+=c-'0';
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
    void Rectangle::Print()const{
        std::cout<<"rectangle"<<' '<<this->x<<' '<<this->y<<' '<<this->width<<' '<<this->height<<' '<<this->fill<<' '<<this->stroke<<' '<<this->strokeWidth;
    }
    void Rectangle::PrintToFile(std::ostream& os)const{
        os<<"<rect "<<"x=\""<<this->x<<"\""<<' '<<"y=\""<<this->y<<"\""<<' '<<"width=\""<<this->width<<"\""<<' '
        <<"height=\""<<this->height<<"\""<<' '<<"fill=\""<<this->fill<<"\""<<' '<<"stroke=\""<<this->stroke<<"\""
        <<' '<<"stroke-width=\""<<this->strokeWidth<<"\""<<' '<<'/'<<'>';
    }
    void Rectangle::Translate(const int offx,const int offy){
        this->x+=offx;
        this->y+=offy;
    }
    bool Rectangle::isInsideRect(int x,int y,int width,int height)const {
        return((x<this->x) && (this->x - x + this->width<width) && (y<this->y) && (this->y - y + this->height<height));
    }
    bool Rectangle::isInsideCircle(int cx,int cy,int r)const {
        return std::pow(this->x - cx,2)+std::pow(this->y - cy,2)<=r * r &&
        std::pow(this->x - cx + width,2)+std::pow(this->y - cy + height,2)<=r * r &&
        std::pow(this->x - cx + width,2)+std::pow(this->y - cy,2)<=r * r &&
        std::pow(this->x - cx,2)+std::pow(this->y - cy + height,2)<=r * r;
    }
