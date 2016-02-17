//class Resource {
//public:
//    Resource(parms p): r(allocate(p)) { }
//    ~Resource() { release(r); }
//    // also need to define copy and assignment
//private:
//    resource_type *r;           // resource managed by this type
//    resource_type *allocate(parms p);     // allocate this resource
//    void release(resource_type*);         // free this resource
//};

//void fcn()
//{
//    Resource res(args);   // allocates resource_type
//    // code that might throw an exception
//    // if exception occurs, destructor for res is run automatically
//    // ...
//}  // res goes out of scope and is destroyed automatically

#include <exception>
#include <iostream>
#include <unistd.h>
#include <stdexcept>

class Resource {
public:
    // in case of no function of allocate, 
    // the following function can be a subsitude
    //Resource(const int& number) : r(new int [number]())
    //{
    //    std::cout << "allocate 4k bytes" << std::endl;
    //}
    Resource(const int& number) : r(allocate(number)) { }
    ~Resource() { release(r); }
private:
    // I as a programmer, believe this function may throw exception
    int* allocate(const int& number) const
    {
        std::cout << "allocate 4k bytes " << std::endl;
        // this "()" means initlise to zero
        // under linux OS this line will be a compile error
        return new int[number]();
    }
    // I as a programmer, believe that this function will not throw exception
    void release(int* pRes) const throw()
    {
        std::cout << "free 4k bytes " << std::endl;
        delete [] pRes;
        // delete pRes;
    }
    int* r;
};

void fcn() throw()
{
    usleep(1000);
    Resource const res(1024);
}

// programmer believe this function maybe will throw exception of type
// std::exception
void fcn2() throw(std::logic_error)
{
    usleep(1000);
    Resource const res(1000);
    // throw std::exception("a! yi chang le!!!");
    throw std::logic_error("a! yi chang le!!!");
}

int main()
{
    // use for testing my RAII function
    // 1, comment release in deconstructor
    // 2, un comment the following line
    // 3, wathc the memory uses on the task manager program(ren wu guan li qi, when windows)
    //while(true)
    //{
    //    fcn();
    //}

    while(true)
    {
        try
        {
            fcn2();
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}
