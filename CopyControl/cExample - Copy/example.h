#include <iostream>
#define NULL 0
class CExample {
public:
	CExample();                     // Ĭ�Ϲ��캯��
    ~CExample()
    {
        delete pBuffer;
    }
    void CExample::Init(int );
private:
	char* pBuffer;              
	int nSize;
};