#include "line.hpp"
    Line::Line(int x1,int y1, int x2,int y2 , std::string stroke ,double strokeWidth){
        this->x1 = x1;
        this->x2 = x2;
        this->stroke = stroke;
        this->strokeWidth = strokeWidth;
        this->y1 = y1;
        this->y2 = y2;
        
    }
    Line::Line(){
        
    }
    Line::Line(std::stringstream& sso){
        
        std::string word;
        while (sso>>word)
        {
            if(word.back() != '>'){
        
                if(word.find("x1") != std::string::npos){
                    word.erase(0,2);
                    for(char c : word){
                        if(c>='0' && c<='9'){
                            x1*=10;
                            x1+=c-'0';
                        }
                    }
                }
                if(word.find("x2") != std::string::npos){
                    word.erase(0,2);
                    for(char c : word){
                        if(c>='0' && c<='9'){
                            x2*=10;
                            x2+=c-'0';
                        }
                    }
                }
                if(word.find("y1") != std::string::npos){
                    word.erase(0,2);
                    for(char c : word){
                        if(c>='0' && c<='9'){
                            y1*=10;
                            y1+=c-'0';
                        }
                    }
                }
                if(word.find("y2") != std::string::npos){
                    word.erase(0,2);
                    for(char c : word){
                        if(c>='0' && c<='9'){
                            y2*=10;
                            y2+=c-'0';
                        }
                    }
                }
                
                if(word.find("stroke") != std::string::npos && word.find("stroke-width") == std::string::npos){
                    stroke = word.substr(word.find("\"")+1);
                    stroke.pop_back();
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
    void Line::Print()const{
        std::cout<<"line "<<this->x1<<' '<<this->y1<<' '<<this->x2<<' '<<this->y2<<' '<<this->stroke<<' '<<this->strokeWidth;
    }
    void Line::PrintToFile(std::ostream& os)const{
        os<<"<line "<<"x1=\""<<this->x1<<"\""<<' '<<"y1=\""<<this->y1<<"\""<<' '
        <<"x2=\""<<this->x1<<"\""<<' '<<"y2=\""<<this->y1<<"\""<<' '<<' '
        <<"stroke=\""<<this->stroke<<"\""<<' '<<"stroke-width=\""<<this->strokeWidth<<"\""<<'/'<<'>';
    }
    void Line::Translate(const int offx,const int offy){
        this->x1+=offx;
        this->x2+=offx;
        this->y1+=offy;
        this->y2+=offy;
    }
    bool Line::isInsideRect(int x,int y,int width,int height)const{
        return((x<this->x1<x+width && y<this->y1<y+height) && (x<this->x2<x+width && y<this->y2<y+height));
    }
    bool Line::isInsideCircle(int cx,int cy,int r)const{
        return(((this->x1 - cx)*(this->x1 - cx) + (this->y1 - cy)*(this->y1 - cy)<=r*r) && 
        ((this->x2 - cx)*(this->x2 - cx) + (this->y2 - cy)*(this->y2 - cy)<=r*r));
    }