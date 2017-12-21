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
    SeqList Merge(const SeqList<ElemType> &sb)
    {
        SeqList temp(0);
        temp.maxlength=this->maxlength+sb.maxlength;
        temp.elems=new ElemType[maxlength];
        if(temp.elems!=NULL)
        {
            int i;
            temp.length=this->length+sb.length;
            for(i=0;i<this->length;i++)
            {
                temp.elems[i]=this->elems[i];
            }
            for(;i<temp.length;i++)
            {
                temp.elems[i]=sb.elems[i-this->length];
            }
            temp.Sort();
        }
        return temp;
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
    void DeleteBetween(const ElemType &s,const ElemType &t)
    {
        if(length==0) return;
        if(s>t)
        {
            cerr<<"Error!"<<endl;
            return;
        }
        else
        {
            for(int i=0;i<length;i++)
            {
                if(elems[i]>s&&elems[i]<t)
                {
                    int j;
                    for(j=i;j<length-1;j++)
                    {
                        elems[j]=elems[j+1];
                    }
                    i--;length--;j--;
                }
            }
        }
    }
    void Show()
    {
        for(int i=0;i<length;i++)
        {
            cout<<elems[i]<<" ";
        }
        cout<<endl;
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
