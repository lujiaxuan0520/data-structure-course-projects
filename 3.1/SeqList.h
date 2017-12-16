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
    void DeleteRepetition()
    {
        for(int i=0;i<length;i++)
        {
            for(int j=i+1;j<length;j++)
            {
                if(elems[i]==elems[j])
                {
                    for(int k=j;k<length-1;k++)
                    {
                        elems[k]=elems[k+1];
                    }
                    length--;j--;
                }
            }
        }
    }
    ElemType DeleteMin()
    {
        ElemType min=elems[0];
        ElemType index=0;
        int i;
        for(i=0;i<length;i++)
        {
            if(elems[i]<min)
            {
                index=i;
                min=elems[i];
            }
        }
        if(index==length-1)
        {
            elems[length-1]=elems[length-2];
        }
        else
        {
            elems[index]=elems[length-1];
        }

        return min;
    }
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
