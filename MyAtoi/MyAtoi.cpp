#include <iostream>
#include <cstring>

int MyAtoi(const char* str)
{
    if (str == NULL)
    {
        return 0;
    }

    int slen = strlen(str);
    if(slen < 0)
    {
        return 0;
    }
    const char* c = str;

    int ret = 0;
    int sign=1;
    while(*c == ' ')
    {
        c++;
    }
    if(*c == '+')
    {
        c++;
    }
    else if(*c == '-')
    {
        sign = -1;
        c++;
    }
    else
    {

    }

    int t = 0;
    while((*c >='0') && (*c <= '9'))
    {
        t = *c - '0';
        ret = ret * 10 + t;
        c++;
    }
    return ret * sign;
}

int main()
{
    std::cout << MyAtoi("+124") << std::endl;
    std::cout << MyAtoi("-124") << std::endl;
    std::cout << MyAtoi("    124") << std::endl;
    std::cout << MyAtoi("     +124") << std::endl;
    std::cout << MyAtoi("      -124") << std::endl;

    std::cout << MyAtoi(NULL) << std::endl;
    std::cout << MyAtoi("1d24") << std::endl;
    std::cout << MyAtoi("") << std::endl;

    std::cout << MyAtoi("124") << std::endl;

    return 0;
}
