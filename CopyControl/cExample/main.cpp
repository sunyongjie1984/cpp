#include "example.h"
int main()
{
    const char* p = "1234567"; // ���ֲ����Լ�new�������ַ����ģ���ֵʲô�ģ��Ƚ����⣬����������������
                         // ���е��������ֻ����memcpy�����ĺ������ܸ���
    p = "american";      // char*�����ֵ��p��������Ϊһ��const char*ָ�룬ָ��һ���ַ�����
                         // ����ַ��������ݲ����Ը���
                         // Ҳ��������Ϊһ���ַ����������͵Ķ���
    std::cout << p << std::endl;

    CExample a;
    a.Init(20);

    CExample b = a;
    CExample c(a); // ������������˼��ȫһ�������ǵ��ÿ������캯������b��c��
                   // �������а���ָ����࣬���û�п������캯����仰�ͻ�����������п��Է���a��pBuffer��
                   // b��pBufferָ��ͬһ���ڴ�
                   // ��ʱ��������ʱ��������b�����Գɹ�������aʱ������ȥdeleteͬһ���ڴ������;

    a.SetBuffer(p);
    // p = "iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii"; // strlen(p) > 20.
    // a.SetTooLongBuffer(p); // �����Է�������������ʱdelete��������ܿ���������ʱ�������new�������������������ڴ档

    CExample d; 
    d = a; // 1.����һ����ֵ�����������û�ж������ظ�ֵ�����������������Զ�����ȱʡ�ĸ�ֵ����������������
           // ����һ����ָ���Ա���࣬
           // �ֻ���������ʱ����������ͬһ���ڴ档�������Ĵ���û��ע�͵�����ô������������d��c��b��a���˳��
           // ������aʱ������ 
           // 2.ȱʡ�ĸ�ֵ����ֻ�Ǹ�����Ӧ�ĳ�Ա����ֵ���ɵ�ֵ�ᱻ�������ɵĶ����ָ���Ա������ָ���new
           // �����Ķ��󽫲��ᱻdelete������ڴ�й¶��
           // 3.�����ɵĶ����ָ�����ָ����㸳ֵ�Ķ����ָ�����ָ��ͬһ���󣬶���������������ָ�����ָ��Ķ���
           // Ҳ����1�е�����ͬһλ�ò�����ԭ�����и�ֵ��������������������������һ��������ֵ����new��������Դ��
           // �ڶ��ǽ����㸳ֵ�Ķ����ȫ��
           // ���ݸ��ƹ���������ָ���Աָ��Ķ�������ݵ��������ɡ�
    // b = a;
    // a.PrintBuffer();
    // b.PrintBuffer();
    return 0;
}