#ifndef SEQLIST_H
#define SEQLIST_H
using namespace std;
template <class ElemType>
class SeqList
{
protected:
    int length;
    int maxlength;
    ElemType *elems;
public:
    SeqList(int size=0)
    {
        elems=new ElemType[size];
        maxlength=size;
        length=0;
    }
    SeqList(ElemType v[],int n,int size=0)
    {
        elems=new ElemType[size];
        maxlength=size;
        length=n;
        for(int i=0;i<length;i++)
        {
            elems[i]=v[i];
        }
    }
    void Sort()
    {
        for(int i=0;i<length-1;i++)
        {
            for(int j=0;j<length-i-1;j++)
            {
                if(elems[j]>elems[j+1])
                {
                    ElemType temp;
                    temp=elems[j];
                    elems[j]=elems[j+1];
                    elems[j+1]=temp;
                }
            }
        }
    }
    int Insert(const ElemType &e)
    {

        if(length==maxlength)
        {
            return 0;
        }
        elems[length]=e;
        length++;
        Sort();

    }
    void Delete(const ElemType &e)
    {
        for(int i=0;i<length;i++)
        {
            if(elems[i]==e)
            {
                int j;
                for(j=i;j<length-1;j++)
                {
                    elems[j]=elems[j+1];
                }
                length--;j--;i--;
            }
        }
    }
//    void DeleteRepetition()
//    {
//        for(int i=0;i<length;i++)
//        {
//            for(int j=i+1;j<length;j++)
//            {
//                if(elems[i]==elems[j])
//                {
//                    for(int k=j;k<length-1;k++)
//                    {
//                        elems[k]=elems[k+1];
//                    }
//                    length--;j--;
//                }
//            }
//        }
//    }
//    ElemType DeleteMin()
//    {
//        ElemType min=elems[0];
//        ElemType index=0;
//        int i;
//        for(i=0;i<length;i++)
//        {
//            if(elems[i]<min)
//            {
//                index=i;
//                min=elems[i];
//
//            }
//
//        }
//        elems[index]=elems[length-1];
//        return min;
//    }
    void Show()
    {
        for(int i=0;i<length;i++)
        {
            cout<<elems[i]<<" ";
        }
    }
    virtual ~SeqList()
    {
        delete []elems;
    }
    void clear()
    {
        length=0;
    }
};
#endif // SEQLIST_H
