#ifndef __CHILD_SIBLING_FOREST_NODE_H__
#define __CHILD_SIBLING_FOREST_NODE_H__

template <class ElemType>
struct ChildSiblingTreeNode
{
    ChildSiblingTreeNode<ElemType> *firstChild;
    ChildSiblingTreeNode<ElemType> *nextSibling;
    ElemType data;

    ChildSiblingTreeNode();						// �޲����Ĺ��캯��
	ChildSiblingTreeNode(ElemType val,			// �в����Ĺ��캯��
        ChildSiblingTreeNode<ElemType> *fChild = NULL,ChildSiblingTreeNode<ElemType> *nSibling = NULL);
};


template<class ElemType>
ChildSiblingTreeNode<ElemType>::ChildSiblingTreeNode()
{
	firstChild = nextSibling = NULL;
}

template<class ElemType>
ChildSiblingTreeNode<ElemType>::ChildSiblingTreeNode(ElemType val,
		ChildSiblingTreeNode<ElemType> *fChild,
		ChildSiblingTreeNode<ElemType> *nSibling)
{
	data = val;
	firstChild = fChild;
	nextSibling = nSibling;
}

#endif // __CHILD_SIBLING_FOREST_NODE_H__


