#include <iostream>
#include <string>

// pointer array, array of pointers
const char* p[] = { "wang zong", "sun zong", "china" };
const char* q[] = { "wang zong", "sun zong", "china" , 0 };

const char *pp[] = { "wang zong", "sun zong", "china" };
const char *qq[] = { "wang zong", "sun zong", "china" , 0 };

const char* a = "hello world";
const char* b = "hello world again";

int main()
{
    // p is a array of pointer, there are three pointers in array p
    // one pointer is 8 bytes, so the sizeof array p is 24 bytes
    std::cout << sizeof(p) << std::endl;
    std::cout << sizeof(q) << std::endl;
    std::cout << sizeof(pp) << std::endl;
    std::cout << sizeof(qq) << std::endl;
    std::cout << sizeof(a) << std::endl;
    for (int i = 0; NULL != q[i]; i++)
    {
        std::cout << q[i] << std::endl;
    }

    for (int i = 0; NULL != p[i]; ++i)
    {
        std::cout << p[i] << std::endl;
    }
    return 0;
}
