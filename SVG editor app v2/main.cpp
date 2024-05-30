#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "line.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "funcs.hpp"
using std::string;
using std::vector;


int main(){
    string helpStr = "The following commands are supported:\nopen <file>	opens <file>\nclose	        closes currently opened file\nsave		saves the currently open file\nsaveas <file>	saves the currently open file in <file>\nprint     prints all figures from file\ncreate <figure>       creates ne figure <figure>\nerase <n>    erases figure with index <n>\ntranslate <horz> <vert>    translates all figures\ntranslate <horz> <vert> <n>     translates only figure with index <n>\nhelp		prints this information\nexit		exists the program";
    vector<Figure *> figures;
    std::cout<<"Type \"help\" for a list of commands\n";
    string fileLoc;
    string input;
    std::cin>>input;
    while(input != "exit"){

        if(input == "print")
            Print(figures);
        else if(input == "create"){
            string in;
            std::getline(std::cin,in);
            std::stringstream ssi(in);
            Create(ssi,figures);
        } 
        else if(input == "erase") {
            int n=0;
            std::cin>>n;
            try
            {
                Erase(n,figures);
            }
            catch(const std::exception& e)
            {
                std::cout<<"Invalid index";
            }
            
        }
        else if(input == "translate"){
            string line,horizontal, vertical,n;
            std::getline(std::cin,line);
            std::stringstream ssi(line);
            ssi>>horizontal>>vertical>>n;
            try
            {
                Translate(horizontal,vertical,n,figures);
            }
            catch(const std::exception& e)
            {
                std::cout<<"Invalid index of figure";
            }
            
        }
        else if(input == "open"){
            std::cin>>fileLoc;
            try
            {
                Open(fileLoc,figures);
                std::cout<<"Successfully opened "<<fileLoc<<std::endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
        }
        else if(input == "save"){
            try
            {
                PrintToFIle(fileLoc,figures);
                std::cout<<"Successfully saved!";
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        else if(input == "saveas"){
            string fileToSaveTo;
            std::cin>>fileToSaveTo;
            try
            {
                PrintToFIle(fileToSaveTo,figures);
                std::cout<<"Successfully save to "<<fileToSaveTo<<std::endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            } 
        }
        else if(input == "close"){
            for(Figure * fig:figures)
                delete fig;
            figures.clear();
            std::cout<<"Successfully closed "<<fileLoc<<std::endl;
        }
        else if(input == "help")
        {
            std::cout<<helpStr<<std::endl;
        }
        else if(input == "within"){
            
            string area;
            std::cin>>area;
            if(area == "rectangle"){
                int x,y,height,width;
                size_t counter = 0;
                std::cin>>x>>y>>width>>height;
                for(Figure * fig :figures)
                    if(fig->isInsideRect(x,y,width,height)){
                        counter ++ ;
                        fig->Print();
                        std::cout<<std::endl;
                    }
                if(counter == 0)std::cout<<"No figures in area!"<<std::endl;
            }
            else if(area == "circle"){
                int cx,cy,r;
                std::cin>>cx>>cy>>r;
                size_t counter = 0;
                for(Figure * fig:figures)
                    if(fig->isInsideCircle(cx,cy,r)){
                        counter++;
                        fig->Print();
                        std::cout<<std::endl;
                    }
                if(counter == 0)std::cout<<"No figures in area!"<<std::endl;
            }
           
        }
        std::cin>>input;        
    }
    for(Figure * fig:figures)
        delete fig;
}
    
    
