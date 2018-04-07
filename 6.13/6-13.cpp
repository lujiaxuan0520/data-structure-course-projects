template<class ElemType>
ThreadBinTreeNode<ElemType>*
PostThreadBinTree<ElemType>::Next(ThreadBinTreeNode<ElemType>*p) const
{
    if(p==root) return NULL;
    if(p->rightTag==1)
        return p->rightChild;
    ThreadBinTreeNode<ElemType>* t=p->parent;
    if(t->rightChild==p||t->rightTag==1)
    {
        return t;
    }
    t=t->rightChild;
    while(t->leftTag==0||t->rightTag==0)
    {
        if(t->leftTag==0) t=t->leftChild;
        else t=t->rightChild;
    }
    return t;
}
