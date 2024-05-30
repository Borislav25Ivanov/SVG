#include "funcs.hpp"

void PrintToFIle(const string fileLoc,const vector<Figure *> &figures){
    if(fileLoc.size()==0) 
        throw std::invalid_argument("Can't save because no file is open. First open a file or save as.");
    string Template = "<svg width=\"1920\" height=\"1080\" xmlns=\"http://www.w3.org/2000/svg\">";
    if(fileLoc.substr(fileLoc.length()-3) != "svg")
        throw std::invalid_argument("Invalid file type!");
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
            int x,y,width,height;
            double strokeWidth;
            string fill,stroke;
            in>>x>>y>>width>>height>>fill>>stroke>>strokeWidth;
            temp = new Rectangle(x,y,width,height,fill,stroke,strokeWidth);
        }
        else if(word == "circle"){
            int cx,cy,r;
            double strokeWidth;
            string fill,stroke;
            in>>cx>>cy>>r>>fill>>stroke>>strokeWidth;
            temp = new Circle(cx,cy,r,fill,stroke,strokeWidth);
        }
        else if(word == "line"){
            int x1,y1,x2,y2;
            double strokeWidth;
            string stroke;
            in>>x1>>y1>>x2>>y2>>stroke>>strokeWidth;
            temp = new Line(x1,y1,x2,y2,stroke,strokeWidth);
        }
        return temp;
}



void Open(const string fileLoc, vector<Figure *> &figures){
    std::stringstream sso;
    std::ifstream in;
    if(fileLoc.substr(fileLoc.length()-3) != "svg")throw std::invalid_argument("Invalid file type.");
    in.open(fileLoc.c_str());
    string word;
    if(in){
        sso<<in.rdbuf();
        in.close();
    }
    else{throw std::invalid_argument("Invalid file name.");}
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
void Print(const vector<Figure *> &figures){
    for(Figure* fig:figures){
        fig->Print();
        std::cout<<std::endl;
    }
}
void Create(std::stringstream& in, vector<Figure *> &figures){
    Figure * temp = Factory(in);    
    figures.push_back(temp);
}
void Erase(const size_t n, vector<Figure *> &figures){
    if(n>figures.size())
        throw std::invalid_argument("Index out of bounds");
    figures.erase(figures.begin()+n-1);
}
void Translate(const string horizontal,const string vertical,const string n, const vector<Figure *> &figures){
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