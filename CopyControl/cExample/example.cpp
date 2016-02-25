#include "example.h"
CExample::CExample()
{
    pBuffer = NULL;
    nSize = 0;
}

CExample::CExample(const CExample& rSide)
{
    nSize = rSide.nSize;
    pBuffer = new char[nSize];
    memcpy(pBuffer, rSide.pBuffer, nSize * sizeof(char));
}

CExample::~CExample()
{
    // delete pBuffer[]; ��ʱҲ���ԣ�����û���롣
    delete pBuffer;
}

void CExample::Init(int n)
{
    pBuffer = new char[n];
    nSize = n;
}

void CExample::SetBuffer(const char* p)
{
    if (strlen(p) > nSize) // ����ģ���Ȼ����ֵ���ܿ��Գɹ�������������ʱ����ܻ������⡣
    {
        return;
    }
    else
    {
        // memcpy(pBuffer, p, sizeof(p) * sizeof(char)); // sizeof(p) == 4
        memcpy(pBuffer, p, strlen(p) * sizeof(char)); // �����Լ����ַ�����pBuffer����char*���͵ĺ���ֻ����ô����
                                                      // ���˰ɡ�
    }
}

void CExample::PrintBuffer()
{
    std::cout << pBuffer << std::endl;
}

/*
CExample& CExample::operator=(CExample& rSide) // ����һ����������ظ�ֵ��������û��ȥdeleteԭ��ָ�����ָ����ڴ档
{
    nSize = rSide.nSize;
    pBuffer = new char[nSize];
    memcpy(pBuffer, rSide.pBuffer, nSize * sizeof(char));
    return *this;
}
*/

CExample& CExample::operator=(const CExample& rSide)
{
    nSize = rSide.nSize; // ���Ƴ����Ա��

    char* p = new char[nSize];
    memcpy(p, rSide.pBuffer, nSize * sizeof(char)); // ����ָ��ָ������ݡ�

    delete []pBuffer; // delete�Լ�ԭ��new�������ڴ档// ����ɲ�����delete pBuffer����[]��?

    pBuffer = p;      // �����µ�ָ��

    return *this;
}
/*
CExample::CExample(const CExample& rSide)
{
    pBuffer = NULL; // ������ǳ����ã��ӵ����п��Կ�������Ϊ��ֵ������ܿ���û�п��ǵ��������캯��
                    // Ҫʹ���������壬���Ի���Ҫ��delete����ԭ��ָ����ڴ�
                    // ��������������һ�����캯����ָ���Ա��û��new��������������deleteʱ������˴���
    *this = rSide;  // �������غ�ĸ�ֵ��������
}
*/
void CExample::SetTooLongBuffer(char* p)
{
    memcpy(pBuffer, p, strlen(p) * sizeof(char));
}
