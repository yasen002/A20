#pragma once


#include"expression_parser_C/parser.h"

//sigma notation properties from chapter 4.2
double sigma1(double n, double i); 
double sigma2(double n, double i); 
double sigma3(double n, double i);

class Chapter4 :public Parser {
public:
    Chapter4() : m_a(0), m_b(0), m_n(0), m_func("") {};
    void getvars();
    double calculator();
    void func_helper(double replace_x, char var);
    double integral();                    
    void theogrom4();
private:
    std::string m_func,
        m_func_empty = ""; //is an empty function, so i can get the original func intact during calculation.
    double m_a, m_b, m_n;
};
