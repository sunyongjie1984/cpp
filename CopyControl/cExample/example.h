#include <iostream>
class CExample {
public:
    CExample();                   // Ĭ�Ϲ��캯��
    // CExample(const CExample&); // �������캯��
    ~CExample();                  // ��������

    void Init(int);               // ��ʼ��
    void SetBuffer(const char*);        // ��ֵ
    void SetTooLongBuffer(char*); // wrong func
    void PrintBuffer();           // ���

    CExample& operator=(const CExample&); // ���ظ�ֵ������
    CExample(const CExample&);    // �������캯������ʹ�����ظ�ֵ�������������Լ�
private:
    char* pBuffer;
    int nSize;
};
