#include <limits>
#include <iostream>
using namespace std;

int main()
{
    cout << boolalpha;

    cout << "max(short): " << numeric_limits<short>::max() << endl;
    cout << "min(short): " << numeric_limits<short>::min() << endl;

    cout << "max(int): " << numeric_limits<int>::max() << endl;
    cout << "min(int): " << numeric_limits<int>::min() << endl;

    cout << "max(long): " << numeric_limits<long>::max() << endl;
    cout << "min(long): " << numeric_limits<long>::min() << endl;

    cout << endl;

    cout << "max(float): " << numeric_limits<float>::max() << endl;
    cout << "min(float): " << numeric_limits<float>::min() << endl;

    cout << "max(double): " << numeric_limits<double>::max() << endl;
    cout << "min(double): " << numeric_limits<double>::min() << endl;

    cout << "max(long double): " << numeric_limits<long double>::max() << endl;
    cout << "min(long double): " << numeric_limits<long double>::min() << endl;

    cout << endl;

    cout << "is_signed(char): "
        << numeric_limits<char>::is_signed << endl;
    cout << "is_specialized(string): "
        << numeric_limits<string>::is_specialized << endl;

    // double a = numeric_limits<double>::max();
}

