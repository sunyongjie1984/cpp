#include <iostream>

int main()
{
    double a = 9.87777;
    double b = 9.87776;
    double c = 10;
    double * p = &c;
    std::cout << "*p = " << *p << std::endl;

    std::cout << "sizeof float   =: " << sizeof(float)  << std::endl;
    std::cout << "sizeof double  =: " << sizeof(double) << std::endl;
    std::cout << "sizeof int     =: " << sizeof(int)    << std::endl;
    std::cout << "sizeof long    =: " << sizeof(long)   << std::endl;
    std::cout << "sizeof pointer =: " << sizeof(p)      << std::endl;

    double t = a - b;
    if ((0.0000001 > t) && (-0.0000001 < t))
    {
        std::cout <<  "a == b" << std::endl;
    }
    else
    {
        std::cout << "a != b"  << std::endl;
    }
    getchar();
    return 0;
}
