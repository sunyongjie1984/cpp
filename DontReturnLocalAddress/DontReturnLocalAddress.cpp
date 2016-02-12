#include <iostream>
#include <string>

#ifdef __linux
#include <stdio.h>
#endif

// friendly compoler ^_^, warning C4172: returning address of local
// variable or temporary, do not return local address

char* GetMemory(void)
{
    char p[] = "hello world";
    return p; // returning local ADDRESS
}

int get_int(void)
{
    int i = 3;
    // returning a value, not the address of i, returning the value of i,
    // in the above function, after returning, the address of local variable p is used,
    // but the variable of p is already unconstructed.
    return i;
}

int main()
{
    char* str = NULL;

    str = GetMemory();
    std::cout << str << std::endl;
    std::cout << std::endl;

    std::cout << get_int() << std::endl;
    return 0;
}
