#include <iostream>

using namespace std;

//单例类的C++实现

class Singleton

{   

private:   

    Singleton();//注意:构造方法私有   



    static Singleton* instance;//惟一实例   

    int var;//成员变量(用于测试)   

public:   

    static Singleton* GetInstance();//工厂方法(用来获得实例)   

    int getVar();//获得var的值   

    void setVar(int);//设置var的值   

    virtual ~Singleton();

};

//构造方法实现

Singleton::Singleton()
{
    this->var = 20;
    cout<<"Singleton Constructor"<<endl;
}

Singleton::~Singleton()
{

    cout<<"Singleton Destructor"<<endl;
    //delete instance;
}

//初始化静态成员   

/*Singleton* Singleton::instance=NULL;

  Singleton* Singleton::GetInstance()   

  {   

  if(NULL==instance)

  instance=new Singleton();

  return instance;   

  }*/

Singleton* Singleton::instance=new Singleton;

Singleton* Singleton::GetInstance()
{
    return instance;
}

//seter && getter含数

int Singleton::getVar()

{

    return this->var;

}

void Singleton::setVar(int var)

{

    this->var = var;

}

int main()
{
    Singleton *ton1 = Singleton::GetInstance();
    Singleton *ton2 = Singleton::GetInstance();
    if(ton1==ton2)
        cout<<"ton1==ton2"<<endl;
    cout<<"ton1 var = "<<ton1->getVar()<<endl;
    cout<<"ton2 var = "<<ton2->getVar()<<endl;
    ton1->setVar(150);
    cout<<"ton1 var = "<<ton1->getVar()<<endl;
    cout<<"ton2 var = "<<ton2->getVar()<<endl;
    delete Singleton::GetInstance();

    return 0;
}
