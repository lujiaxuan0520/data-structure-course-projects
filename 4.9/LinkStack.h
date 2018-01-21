#ifndef LINKSTACK
#define LINKSTACK
#include <iostream>
using namespace std;
enum Status {SUCCESS, FAIL, UNDER_FLOW, OVER_FLOW,RANGE_ERROR, DUPLICATE_ERROR,
	NOT_PRESENT, ENTRY_INSERTED, ENTRY_FOUND, VISITED, UNVISITED};
template<typename T>
struct Node
{
    T data;
    Node<T> *next;
    Node(const T&t,Node<T> *q=NULL);
};
template<typename T>
Node<T>::Node(const T&t,Node<T> *q)
{
    data = t;
    next = q;
}
template<typename T>
class LinkStack
{
protected:
    Node<T> *Top;
public:
    LinkStack();
    virtual ~LinkStack();
    Status push(const T e);
    Status top(T &e);
    Status pop(T &e);
    bool IsEmpty();
    void Clear();
    void Show();
};
template<typename T>
LinkStack<T>::LinkStack()
{
    Top=NULL;
}
template<typename T>
LinkStack<T>::~LinkStack()
{
    Clear();
}
template<typename T>
void LinkStack<T>::Clear()
{
    Node<T> *p;
    for(;Top;)
    {
        p=Top;
        Top=Top->next;
        delete p;
    }
}
template<typename T>
bool LinkStack<T>::IsEmpty()
{
    return Top==NULL;
}
template<typename T>
Status LinkStack<T>::push(const T e)
{
    Node<T> *p=new Node<T>(e,Top);
    if(p==NULL)
    {
        return OVER_FLOW;
    }
    else
    {
        Top=p;
        return SUCCESS;
    }
}
template<typename T>
Status LinkStack<T>::top(T &e)
{
    if(IsEmpty())
        return UNDER_FLOW;
    else
    {
        e=Top->data;
        return SUCCESS;
    }
}
template<typename T>
Status LinkStack<T>::pop(T &e)
{
    if(IsEmpty())
        return UNDER_FLOW;
    else
    {
        Node<T> *p=Top;
        e=Top->data;
        Top=Top->next;
        delete p;
        return SUCCESS;
    }
}
template<typename T>
void LinkStack<T>::Show()
{
    if(IsEmpty())
        cout<<"Õ»¿Õ"<<endl;
    else
    {
        Node<T> *p;
        cout<<"Top";
        for(p=Top;p;p=p->next)
        {
            cout<<"->"<<p->data;
        }
        cout<<endl;
    }
}
#endif // LINKSTACK
