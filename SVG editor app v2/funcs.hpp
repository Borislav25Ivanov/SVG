#ifndef __FUNCS_HPP
#define __FUNCS_HPP
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "line.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
using std::string;
using std::vector;



void PrintToFIle(const string fileLoc,const vector<Figure *> &figures);
Figure * Factory(std::stringstream& in);
void Open(const string fileLoc,vector<Figure *> &figures);
void Print(const vector<Figure * > &figures);
void Create(std::stringstream& in, vector<Figure *> &figures);
void Erase(const size_t n, vector<Figure * > &Figure);
void Translate(const string horizontal,const string vertical,const string n,const vector<Figure * > & figures);

#endif