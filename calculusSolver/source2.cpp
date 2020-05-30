
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


//using namespace std 
#include <iostream>
//#include <cstdio>
//#include <stdio.h>
//#include <stdlib.h> 
#include<string>
using std::cout;
using std::cin;
#include"source2.h"
#define PI 3.14159265


//calculus chapter 4.2 theorem 5.  page#309
double sigma1(double n, double i) {
	double result = (n * (n + 1)) / 2;
	return result;
}

//calculus chapter 4.2 theorem 6
double sigma2(double n, double i) {
	double result = (n * (n + 1)*(2*n+1)) / 6;
	return result;
}

//calculus chapter 4.2 theorem 7
double sigma3(double n, double i) {
	double result = (n * (n + 1)) / 2;
	return (result*result);
}


/**
*
*
*work cited:  helloacm.com
*/
double Chapter4::integral() {
    double width = (m_b - m_a) / m_n;  // width of each small rectangle
    double upper_sum = 0.0, lower_sum = 0.0, mid_sum = 0.0;  // signed area
    for (int i = 0; i < m_n; i++) {
        //1.call the fucntion helper to replace var with param numbers 
        //2.call parse method to calculate the results

        //right sum
        int ii = i + 1;                                             //is there way to eliminate this warning?????
        double replace_x = m_a + (ii)*width;
        func_helper(replace_x,'x');
        double height = calculator();
        lower_sum += height * width; // sum up each small rectangle

        //left sum                                            
        replace_x = m_a + (i)*width;
        func_helper(replace_x,'x');
        height = calculator();
        upper_sum += height * width; // sum up each small rectangle

        //mid sum  0.5*(xi-1 + xi)  
        double xi = 0.5 * (m_a + m_a * width);
        replace_x = m_a + (i)*width + (width / 2);                   //formula: how to do the midpoint?????
        func_helper(replace_x,'x');
        height = calculator();
        mid_sum += height * width; // sum up each small rectangle
        cout << "//----------------\n";
    }
    std::cout << "Lower RIght sum is: " << lower_sum << std::endl;
    std::cout << "Upper Left sum is: " << upper_sum << std::endl;
    std::cout << "Midpoint sum is: " << mid_sum << std::endl;
    return upper_sum;
}


//a function that will take char array and replace variable with numbers
void Chapter4::func_helper(double replace_x, char var) {

    std::string replace = std::to_string(replace_x);
    m_func_empty = m_func;
    size_t found = m_func_empty.find(var);
    if (found != string::npos) {
        while (found != string::npos)
        {
            m_func_empty.erase(found, 1);
            m_func_empty.insert(found, replace);
            found = m_func_empty.find(var);
        }
    }
    else {
        cout << "variable x is not found in function!";
        return;
    }

}



void Chapter4::getvars() {
    int problem_type;
    puts("\
1.given integral aproximate sum.\n\
2.given integral, use integral therom 4 to evaluate the integral.\n\
3.express the integral as a limit of sums \n\
4.given f''(x) and two point of f(x), find f(x)\n\
0.stop\n\
");

    bool flag = true;
    while (flag)
    {


        std::cin >> problem_type;

        if (problem_type == 1) {
            std::string func_e;
            puts("Enter you function: ");
            std::cin >> func_e;
            m_func = func_e;

            puts("Enter lower integrand: ");
            std::cin >> m_a;

            puts("Enter uppper integrand: ");
            std::cin >> m_b;

            puts("number of subintervals: ");
            std::cin >> m_n;

            //call the proper method
            integral();

        }
        else if (problem_type == 2) {
            std::string func_e;
            puts("Enter you function: ");
            std::cin >> func_e;
            m_func = func_e;

            puts("Enter lower integrand: ");
            std::cin >> m_a;

            puts("Enter uppper integrand: ");
            std::cin >> m_b;

            //call the proper method
            //integral();
            theogrom4();
        }
        else if (problem_type == 3) {
            std::string func_e;
            puts("Enter you function: ");
            std::cin >> func_e;
            m_func = func_e;

            puts("Enter lower integrand: ");
            std::cin >> m_a;

            puts("Enter uppper integrand: ");
            std::cin >> m_b;

            puts("number of subintervals: ");
            std::cin >> m_n;
            //i am still working on this
            cout << "1.find delta_x\n\
2.find f'(x)+c by finding antiderivative of f''(x)\n\
3.find f'(x)+cx+d by finding antiderivative of f'(x)\n\
4.plugin two points to find c and d\n\
";
        }
        else if (problem_type == 4) {
            std::string func_e;
            puts("Enter you function: ");
            std::cin >> func_e;
            m_func = func_e;

            puts("Enter lower integrand: ");
            std::cin >> m_a;

            puts("Enter uppper integrand: ");
            std::cin >> m_b;

            puts("number of subintervals: ");
            std::cin >> m_n;
            //i am still working on this
            cout << "1.f'(x) = Ff''(x)dx\n\
2.find xi\n\
3.repalce xi with x in the original function\n\
4.repalce delta_x with dx in the original fucntion\n\
";
        }
        else if (problem_type == 0) {
            flag = false;
        }
        else {
            flag = false;
        }
    }
}


double Chapter4::calculator() {
    //convert m_func to char array
    //check if function is empty
    //pass function to parse
    //return the result

    //convert to char array
    const int n = m_func_empty.length();
    char* char_array = (char*)malloc(n + 1);
    strcpy(char_array, m_func_empty.c_str());//Parse object only excepts C_array


    if (strcmp(char_array, "") != 0)
    {
        try
        {
            // evaluate the expression
            char* result;
            result = parse(char_array);
            printf("\t the result is: %s\n", result);

            return ans;//ans is a private double of Parser. holds the result of the expression

        }
        catch (...)
        {
            printf("\tError: Unknown error occured in parser\n");
        }
    }

}


void Chapter4::theogrom4() {
    int _i = 0;
    double delta_x = (m_b - m_a) / 2;
    double xi = m_a + _i * delta_x;
    //repalce the x with xi, dx with delta_x
    


    cout << "\
1. find delta_x: delta_x = (b-a)\n\
2.find xi: xi = a + i * delta_x\n\
3.plug in delta_x and xi: lim   sigma(n)  f(xi) * delta_x           \n\
                         (n->&) (i=1)                                \n\
";
}


