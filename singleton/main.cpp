#include <iostream>

using namespace std;

//�������C++ʵ��

class Singleton

{   

private:   

    Singleton();//ע��:���췽��˽��   



    static Singleton* instance;//Ωһʵ��   

    int var;//��Ա����(���ڲ���)   

public:   

    static Singleton* GetInstance();//��������(�������ʵ��)   

    int getVar();//���var��ֵ   

    void setVar(int);//����var��ֵ   

    virtual ~Singleton();

};

//���췽��ʵ��

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

//��ʼ����̬��Ա   

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

//seter && getter����

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
