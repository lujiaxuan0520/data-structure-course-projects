#ifndef __CHILD_SIBLING_TREE_H__
#define __CHILD_SIBLING_TREE_H__

#include "ChildSiblingTreeNode.h"
#include "LinkQueue.h"

template<class ElemType>
class ChildSiblingTree
{
private:
    ChildSiblingTreeNode<ElemType> *root;
public:
    ChildSiblingTree();									// �޲����Ĺ��캯��
    ChildSiblingTreeNode<ElemType> *CreateTreeGhelp(ElemType items[], int parents[], int r, int n);
    // ��������Ԫ��Ϊitems[],��Ӧ���˫��Ϊparents[],�����λ��Ϊr,������Ϊn�������� �����ĸ�
    ChildSiblingTree(ElemType items[], int parents[], int n);
    // ��������Ԫ��Ϊitems[],��Ӧ���˫��Ϊparents[],�����λ��Ϊr,������Ϊn����
	ChildSiblingTreeNode<ElemType> * GetRoot() const;	//  �����ĸ�
	Status GetElem(ChildSiblingTreeNode<ElemType> *cur, ElemType &e) const;// ��e ����Ԫ��ֵ
	ChildSiblingTreeNode<ElemType> *FirstChild(ChildSiblingTreeNode<ElemType> *cur) const;
	ChildSiblingTreeNode<ElemType> *NextSibling(ChildSiblingTreeNode<ElemType> *cur) const;
	int Height(ChildSiblingTreeNode<ElemType> *r) const//�������
	{
	    if(r==NULL) return 0;
	    ChildSiblingTreeNode<ElemType> *p;
	    int maxHeight=0;//���������ĸ߶�
	    for(p=FirstChild(r);p!=NULL;p=NextSibling(p))
        {
            if(Height(p)>maxHeight)
                maxHeight=Height(p);
        }
        return maxHeight+1;
	}
	int TreeDegree(ChildSiblingTreeNode<ElemType> *r) const//�����Ķ�
	{
	    if(r==NULL) return 0;
	    int count=0;//��ǰ���Ķ�
	    int maxDegree=0;//��ǰ�������������Ķ�
	    for(ChildSiblingTreeNode<ElemType> *p=FirstChild(r);p!=NULL;p=NextSibling(p))
        {
            count++;//�����ۼӳ��ý��Ķ�
            if(TreeDegree(p)>maxDegree) maxDegree=TreeDegree(p);
        }
        if(count>maxDegree) maxDegree=count;
        return maxDegree;
	}
};



template <class ElemType>
void DisplayTWithConcaveShape(const ChildSiblingTree<ElemType> &t, ChildSiblingTreeNode<ElemType> *r, int level);

template <class ElemType>
void DisplayTWithConcaveShape(const ChildSiblingTree<ElemType> &t);




template <class ElemType>
ChildSiblingTree<ElemType>::ChildSiblingTree()
{
	root = NULL;
}

template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::CreateTreeGhelp(ElemType elems[], int parents[], int r, int n)
// �����������������Ԫ��Ϊitems[],��Ӧ���˫��Ϊparents[],�����λ��Ϊr,������Ϊn���������������ĸ�
{
	if (r >= 0 && r < n){
		ChildSiblingTreeNode<ElemType> *rt = new ChildSiblingTreeNode<ElemType>(elems[r]);	// ���Ƹ����
		ChildSiblingTreeNode<ElemType> *subTreeRoot, *cur;
		for (int i = 0; i < n; i++)	{	// ����r�ĺ���
			if (parents[i] == r)	{	// ������posΪ��������
				subTreeRoot = CreateTreeGhelp(elems, parents, i, n);
				if (rt->firstChild == NULL)	{	// subTreeRootΪrt��һ�������ĸ�
					rt->firstChild = subTreeRoot;
					cur = subTreeRoot;	        // cur���¸��Ƶ������ĸ�
				}
				else{	               // subTreeRootΪcur����һ���ֵ�
					cur->nextSibling = subTreeRoot;
					cur = subTreeRoot;
				}
			}
		}
		return rt;
	}
	else return NULL;									// r�Ƿ�����������
}

template <class ElemType>
ChildSiblingTree<ElemType>::ChildSiblingTree(ElemType elems[], int parents[], int n)
// �����������������Ԫ��Ϊitems[],��Ӧ���˫��Ϊparents[],�����λ��Ϊ0,������Ϊn����
{
	root = CreateTreeGhelp(elems, parents, 0, n);	// �ø�������������
}

template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::GetRoot() const
{
	return root;
}

template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::FirstChild(ChildSiblingTreeNode<ElemType> *cur) const
{
	if (cur == NULL)
		return NULL;
	else
		return cur->firstChild;
}

template <class ElemType>
ChildSiblingTreeNode<ElemType> *ChildSiblingTree<ElemType>::NextSibling(ChildSiblingTreeNode<ElemType> *cur) const
{
	if (cur == NULL)
		return NULL;
	else
		return cur->nextSibling;
}

template <class ElemType>
Status ChildSiblingTree<ElemType>::GetElem(ChildSiblingTreeNode<ElemType> *cur, ElemType &e) const
// �����������e ����curԪ��ֵ,��������ڽ��cur,���� ��NOT_PRESENT,���� ��ENTRY_FOUND
{
	if (cur == NULL)
		return NOT_PRESENT;
	else	{
		e = cur->data;			// ��e ��Ԫ��ֵ
		return ENTRY_FOUND;		//  ��ENTRY_FOUND
	}
}

template <class ElemType>
void DisplayTWithConcaveShape(const ChildSiblingTree<ElemType> &t,
	ChildSiblingTreeNode<ElemType> *r, int level)
// ����������������ʾ����ʾ����levelΪ�������������Ĳ����Ϊ1
{
    ChildSiblingTreeNode<ElemType> *p;
	if (r != NULL)	{
		cout<<endl;									//��ʾ����
		for(int i = 0; i < level - 1; i++)
			cout<<" ";								//ȷ���ڵ�level����ʾ���
		ElemType e;
		t.GetElem(r, e);							// ȡ�����r��Ԫ��ֵ
		cout << e;									// ��ʾ���Ԫ��ֵ
		for (p = t.FirstChild(r); p != NULL;	p = t.NextSibling(p))
			DisplayTWithConcaveShape(t, p, level + 1);// ������ʾ��������
	}
}

template <class ElemType>
void DisplayTWithConcaveShape(const ChildSiblingTree<ElemType> &t)
// ����������������ʾ����ʾ��
{
	DisplayTWithConcaveShape(t, t.GetRoot(), 1);// ���ø�������ʵ�ְ������ʾ����ʾ��
	cout << endl;									// ����
}


#endif
