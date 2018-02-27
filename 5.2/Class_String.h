// Class_String.h
#ifndef MY_CLASS_STRING_H
#define MY_CLASS_STRING_H
#include<iostream>
using namespace std;
class String
{
public:
    //���캯��
    String(const char* chr="");                 //���캯����ʵ�ֳ�ʼ��string s("abc");
    String(const int n,const char &c) throw(char);           //���캯����ʵ�ֳ�ʼ��string s(3,'a');
    String(const String &s);                    //�������캯����ʵ�ֳ�ʼ��string a(b);���
    //��������
    virtual ~String();                          //��������
    //��ͨ��Ա����
    int length() const;                         //�����ַ�������
    bool empty() const;                         //�ж��ַ����Ƿ�Ϊ��
    String& erase();                            //����ַ���
    String& swap(String &s);                    //���������ַ���
    //���������
    char& operator[](int index) const throw(double);     //����[]�������ʵ��s[i]�±����
    String& operator=(const String& s);         //���ظ�ֵ�������ʵ��s1=s2;�ֵ
    String operator+(const String& s) const;    //���ؼӷ��������ʵ��s1+s2
    String operator+(const char& c) const;      //���ؼӷ��������ʵ��s+'a'
    String& operator+=(const String& s);        //����+=�������ʵ��s1+=s2
    String& operator+=(const char& c);          //����+=�������ʵ��s1+='a'
    bool operator==(const String &s) const;     //����==�������ʵ��s1==s2
    bool operator!=(const String &s) const;     //����!=�������ʵ��s1!=s2
    bool operator<(const String& s) const;      //����<�������ʵ��s1<s2
    bool operator>(const String& s) const;      //����>�������ʵ��s1>s2
    bool operator<=(const String& s) const;     //����<=�������ʵ��s1<=s2
    bool operator>=(const String& s) const;     //����>=�������ʵ��s1>=s2
    friend ostream& operator<<(ostream& out,const String& s);   //����<<�����
    friend istream& operator>>(istream& in,String& s);          //����>>�����

private:
    char *pc;
    int num;
};

#endif
