#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "line.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
using std::string;
using std::vector;

vector<Figure *> figures;

void PrintToFIle(string fileLoc){
            string Template = "<svg width=\"1920\" height=\"1080\" xmlns=\"http://www.w3.org/2000/svg\">";
            std::ofstream out(fileLoc);
            out<<Template<<std::endl;
            for(Figure * fig:figures){
                fig->PrintToFile(out);
                out<<std::endl;
            }
            out<<"</svg>";
            out.close();
}
Figure * Factory(std::stringstream& in){
    string word;
    Figure * temp;
    in>>word;
        if(word == "rectangle"){
            double x,y,width,height,strokeWidth;
            string fill,stroke;
            in>>x>>y>>width>>height>>fill>>stroke>>strokeWidth;
            temp = new Rectangle(x,y,width,height,fill,stroke,strokeWidth);

        }
        else if(word == "circle"){
            double cx,cy,r,strokeWidth;
            string fill,stroke;
            in>>cx>>cy>>r>>fill>>stroke>>strokeWidth;
            temp = new Circle(cx,cy,r,fill,stroke,strokeWidth);
        }
        else if(word == "line"){
            double x1,y1,x2,y2,strokeWidth;
            string stroke;
            in>>x1>>y1>>x2>>y2>>stroke>>strokeWidth;
            temp = new Line(x1,y1,x2,y2,stroke,strokeWidth);
        }
        return temp;
}



void Open(string fileLoc){
    std::stringstream sso;
    std::ifstream in;
    in.open(fileLoc.c_str());
    string word;
    if(in){
        sso<<in.rdbuf();
        in.close();
    }
    else{std::cout<< "error";}
    while (sso>>word)
    {
        if(word == "<rect"){
            Figure * fig = new Rectangle(sso);  
            figures.push_back(fig);
        }
        else if(word=="<circle"){
            Figure * fig = new Circle(sso);
            figures.push_back(fig);
        }
        else if(word == "<line"){
            Figure * fig = new Line(sso);
            figures.push_back(fig);
        }
    }
    

    
}
void Print(){
    for(Figure* fig:figures){
        fig->Print();
        std::cout<<std::endl;
    }
}
void Create( std::stringstream& in){
    Figure * temp = Factory(in);    
    figures.push_back(temp);
}
void Erase(const size_t n){
    if(n>figures.size())throw std::invalid_argument("out of bounds");
     figures.erase(figures.begin()+n-1);
}
void Translate(const string horizontal,const string vertical,const string n){
    int horizontalInt = 0;
    int verticalInt = 0;
     for(char c : horizontal)
        {
            if(c<='9' && c>='0'){
                horizontalInt *=10;
                horizontalInt += c -'0';
            }
        }

        for(char c : vertical)
        {
            if(c<='9' && c>='0'){
                verticalInt *=10;
                verticalInt += c -'0';
            }
        }
        
    if(n.size() == 0){
        for(Figure * fig : figures){
            fig->Translate(verticalInt,horizontalInt);
        }
    }
    else {
        int index = stoi(n);
        if(index> figures.size())throw std::invalid_argument("out of bounds");
        figures[index]->Translate(horizontalInt,verticalInt);
    }
}
int main(){
    string fileLoc;
    string input;
    std::cin>>input;
    while(input != "exit"){

        if(input == "print")Print();
        else if(input == "create"){
            string in;
            std::getline(std::cin,in);
            std::stringstream ssi(in);
            Create(ssi);
        } 
        else if(input == "erase") {
            int n=0;
            std::cin>>n;
            try
            {
                Erase(n);
            }
            catch(const std::exception& e)
            {
                std::cout<<"invalid index";
            }
            
        }
        else if(input == "translate"){
            string line,horizontal, vertical,n;
            std::getline(std::cin,line);
            std::stringstream ssi(line);
            ssi>>horizontal>>vertical>>n;
            try
            {
                Translate(horizontal,vertical,n);
            }
            catch(const std::exception& e)
            {
                std::cout<<"Invalid index of figure";
            }
            
        }
        else if(input == "open"){
            std::cin>>fileLoc;
            Open(fileLoc);
        }
        else if(input == "save"){
        PrintToFIle(fileLoc);
        }
        else if(input == "saveas"){
            string fileToSaveTo;
            std::cin>>fileToSaveTo;
            PrintToFIle(fileToSaveTo);
        }
        std::cin>>input;        
    }
}
    
    
