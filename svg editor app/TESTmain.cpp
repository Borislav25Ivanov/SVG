#include <iostream>
#include <fstream>
#include "figure.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "line.hpp"


int main(){
    char fill[10]  = "blue";
    std::ofstream out("test.svg");
    out<<"<svg width=\"1920\" height=\"1080\" xmlns=\"http://www.w3.org/2000/svg\">"<<std::endl;
    Rectangle rec(10,10,30,40,fill);
    rec.PrintToFile(out);
    out<<std::endl<<"</svg>";
    rec.PrintToConsole();
}