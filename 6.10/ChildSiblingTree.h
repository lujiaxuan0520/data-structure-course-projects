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
    ChildSiblingTree();									// 无参数的构造函数
    ChildSiblingTreeNode<ElemType> *CreateTreeGhelp(ElemType items[], int parents[], int r, int n);
    // 建立数据元素为items[],对应结点双亲为parents[],根结点位置为r,结点个数为n的树，并 求树的根
    ChildSiblingTree(ElemType items[], int parents[], int n);
    // 建立数据元素为items[],对应结点双亲为parents[],根结点位置为r,结点个数为n的树
	ChildSiblingTreeNode<ElemType> * GetRoot() const;	//  求树的根
	Status GetElem(ChildSiblingTreeNode<ElemType> *cur, ElemType &e) const;// 用e 求结点元素值
	ChildSiblingTreeNode<ElemType> *FirstChild(ChildSiblingTreeNode<ElemType> *cur) const;
	ChildSiblingTreeNode<ElemType> *NextSibling(ChildSiblingTreeNode<ElemType> *cur) const;
	int Height(ChildSiblingTreeNode<ElemType> *r) const//树的深度
	{
	    if(r==NULL) return 0;
	    ChildSiblingTreeNode<ElemType> *p;
	    int maxHeight=0;//子树中最大的高度
	    for(p=FirstChild(r);p!=NULL;p=NextSibling(p))
        {
            if(Height(p)>maxHeight)
                maxHeight=Height(p);
        }
        return maxHeight+1;
	}
	int TreeDegree(ChildSiblingTreeNode<ElemType> *r) const//求树的度
	{
	    if(r==NULL) return 0;
	    int count=0;//当前结点的度
	    int maxDegree=0;//当前结点的子树中最大的度
	    for(ChildSiblingTreeNode<ElemType> *p=FirstChild(r);p!=NULL;p=NextSibling(p))
        {
            count++;//依次累加出该结点的度
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
// 操作结果：建立数据元素为items[],对应结点双亲为parents[],根结点位置为r,结点个数为n的树，并返回树的根
{
	if (r >= 0 && r < n){
		ChildSiblingTreeNode<ElemType> *rt = new ChildSiblingTreeNode<ElemType>(elems[r]);	// 复制根结点
		ChildSiblingTreeNode<ElemType> *subTreeRoot, *cur;
		for (int i = 0; i < n; i++)	{	// 查找r的孩子
			if (parents[i] == r)	{	// 建立以pos为根的子树
				subTreeRoot = CreateTreeGhelp(elems, parents, i, n);
				if (rt->firstChild == NULL)	{	// subTreeRoot为rt第一棵子树的根
					rt->firstChild = subTreeRoot;
					cur = subTreeRoot;	        // cur最新复制的子树的根
				}
				else{	               // subTreeRoot为cur的下一个兄弟
					cur->nextSibling = subTreeRoot;
					cur = subTreeRoot;
				}
			}
		}
		return rt;
	}
	else return NULL;									// r非法，建立空树
}

template <class ElemType>
ChildSiblingTree<ElemType>::ChildSiblingTree(ElemType elems[], int parents[], int n)
// 操作结果：建立数据元素为items[],对应结点双亲为parents[],根结点位置为0,结点个数为n的树
{
	root = CreateTreeGhelp(elems, parents, 0, n);	// 用辅助函数建立树
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
// 操作结果：用e 求结点cur元素值,如果不存在结点cur,函数 求NOT_PRESENT,否则 求ENTRY_FOUND
{
	if (cur == NULL)
		return NOT_PRESENT;
	else	{
		e = cur->data;			// 用e 求元素值
		return ENTRY_FOUND;		//  求ENTRY_FOUND
	}
}

template <class ElemType>
void DisplayTWithConcaveShape(const ChildSiblingTree<ElemType> &t,
	ChildSiblingTreeNode<ElemType> *r, int level)
// 操作结果：按凹入表示法显示树，level为层次数，设根结点的层次数为1
{
    ChildSiblingTreeNode<ElemType> *p;
	if (r != NULL)	{
		cout<<endl;									//显示新行
		for(int i = 0; i < level - 1; i++)
			cout<<" ";								//确保在第level列显示结点
		ElemType e;
		t.GetElem(r, e);							// 取出结点r的元素值
		cout << e;									// 显示结点元素值
		for (p = t.FirstChild(r); p != NULL;	p = t.NextSibling(p))
			DisplayTWithConcaveShape(t, p, level + 1);// 依次显示各棵子树
	}
}

template <class ElemType>
void DisplayTWithConcaveShape(const ChildSiblingTree<ElemType> &t)
// 操作结果：按凹入表示法显示树
{
	DisplayTWithConcaveShape(t, t.GetRoot(), 1);// 调用辅助函数实现按凹入表示法显示树
	cout << endl;									// 换行
}


#endif
