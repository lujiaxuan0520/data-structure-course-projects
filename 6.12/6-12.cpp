template<class ElemType>
ThreadBinTreeNode<ElemType>*
PreThreadBinTree<ElemType>::Next(ThreadBinTreeNode<ElemType>* p) const
{
    if(p->leftTag==0)//有左孩子
    {
        return p->leftChild;
    }
    else//有右孩子或者无孩子
    {
        return p->rightChild;
    }
}
