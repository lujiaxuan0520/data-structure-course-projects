// Class_String.cpp
#include "Class_String.h"
#include<cstdlib>
//以下为构造函数
String::String(const char* chr)
{
    if(!chr)
    {
        num=0;
        pc=NULL;
    }
    else
    {
        int i=0,_count=0;
        while(chr[i])
        {
            _count++;i++;
        }
        num=_count;
        pc=new char[num];
        for(i=0;i<num;++i)
        {
            pc[i]=chr[i];
        }
    }
}

String::String(int n,const char &c)
{
    if(n<0)
    {
        cerr<<"The first argument should be greater than zero.";
        exit(-1);
    }
    else
    {
        num=n;
        pc=new char[num];
        for(int i=0;i<num;++i)
        {
            pc[i]=c;
        }
    }
}

String::String(const String &s)
{
    num=s.num;
    pc=new char[num];
    for(int i=0;i<num;++i)
    {
        pc[i]=s[i];
    }
}

//以下为析构函数
String::~String()
{
    if(pc!=NULL)
    {
        delete [] pc;
        num=0;
        pc=NULL;
    }
}

//以下为普通成员函数
int String::length() const
{
    return num;
}

bool String::empty() const
{
    if(num==0) return 1;
    else return 0;
}

String& String::erase()
{
    if(pc!=NULL)
    {
        delete [] pc;
        num=0;
        pc=NULL;
    }
    return *this;
}

String& String::swap(String &s)
{
	String temp = s;
	s=*this;
	*this=temp;
	return *this;
}

//以下为重载运算符
char& String::operator[](int index) const
{
    if(index>=num)
    {
        cerr<<"Index too large";
        exit(-1);
    }
    else
    {
        return pc[index];
    }
}

String& String::operator=(const String& s)
{
    if(&s!=this)
    {
        if(pc!=NULL) delete [] pc;
        num=s.num;
        pc=new char[num];
        for(int i=0;i<num;++i)
        {
            pc[i]=s[i];
        }
    }
    return *this;
}

String String::operator+(const String& s) const
{
    String temp;
    temp.pc=new char[this->num+s.num];
    temp.num=this->num+s.num;
    int i;
    for(i=0;i<this->num;++i)
    {
        temp[i]=(*this)[i];
    }
    for(;i<this->num+s.num;++i)
    {
        temp[i]=s[i-this->num];
    }
    return temp;
}

String String::operator+(const char& c) const
{
    String t(1,c);
    String temp(*this);
    temp=temp+t;
    return temp;
}

String& String::operator+=(const String& s)
{
    *this=*this+s;
    return *this;
}

String& String::operator+=(const char& c)
{
    *this=*this+c;
    return *this;
}

bool String::operator==(const String &s) const
{
    if(this->num==s.num)
    {
        int i;
        for(i=0;i<s.num;++i)
        {
            if((*this)[i]!=s[i]) break;
        }
        if(i==s.num) return 1;
        else return 0;
    }
    else return 0;
}

bool String::operator!=(const String &s) const
{
    if(*this==s) return 0;
    else return 1;
}
void String::Failure(const String &b,int *f)
{
    int j=0,k=-1;
    f[0]=-1;
    while(j<b.length()-1)
    {
        if(k==-1||b[k]==b[j])
        {
            f[++j]=++k;
            if(b[j]==b[k])
            {
                f[j]=f[k];
            }
        }
        else
            k=f[k];
    }
}
int String::KMP_find(const String &b,int &p)
{
    int *f=new int [b.length()];
    Failure(b,f);
    int i=p,j=0;
    while(i<this->length()&&j<b.length()&&(b.length()-j<=this->length()-i))
    {
        if(j==-1||b[j]== this->pc[i])
        {
            i++;
            j++;
        }
        else
            j=f[j];
    }
    delete []f;
    if(j<b.length())
        return -1;
    else
        return p=i-j;
}
bool String::operator<(const String& s) const
{
    if(*this==s) return 0;
    else if(this->num==0&&s.num!=0) return 1;
    else if(this->num!=0&&s.num==0) return 0;
    else
    {
        int _min=(this->num>s.num)?s.num:this->num;
        int i;
        for(i=0;i<_min;++i)
        {
            if((*this)[i]>s[i]) break;
        }
        if(i==_min) return 1;
        else return 0;
    }
}
String & String::Replace(const String &t,const String &v)
{
    int p=0,_count=0;
    if(KMP_find(t,p)==-1)
    {
        return *this;
    }
    else
    {
        String temp;
        while(KMP_find(t,p)!=-1)
        {
            for(int i=_count;i<p;i++)
            {
                temp=temp+this->pc[i];
                _count++;
            }
            for(int j=0;j<v.length();j++)
            {
                temp=temp+v[j];
            }
            _count+=t.length();
            p+=t.length();
        }
        for(;_count<num;_count++)
        {
            temp=temp+this->pc[_count];
        }
        return *this=temp;
    }
}

bool String::operator>(const String& s) const
{
    if(*this==s) return 0;
    else if(this->num==0&&s.num!=0) return 0;
    else if(this->num!=0&&s.num==0) return 1;
    else
    {
        int _min=(this->num>s.num)?s.num:this->num;
        int i;
        for(i=0;i<_min;++i)
        {
            if((*this)[i]<s[i]) break;
        }
        if(i==_min) return 1;
        else return 0;
    }
}

bool String::operator<=(const String& s) const
{
    if(*this<s||*this==s) return 1;
    else return 0;
}

bool String::operator>=(const String& s) const
{
    if(*this>s||*this==s) return 1;
    else return 0;
}

ostream& operator<<(ostream& out,const String& s)
{
    for(int i=0;i<s.num;++i)
    {
        out<<s[i];
    }
    return out;
}

istream& operator>>(istream& in,String& s)
{
    in>>s.pc;
    char *it=s.pc;
    int _count=0;
    while(*it!='\0')
    {
        _count++;
        it++;
    }
    s.num=_count;
    return in;
}

