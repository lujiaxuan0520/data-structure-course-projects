template<class ElemType>
ThreadBinTreeNode<ElemType>*
PreThreadBinTree<ElemType>::Next(ThreadBinTreeNode<ElemType>* p) const
{
    if(p->leftTag==0)//������
    {
        return p->leftChild;
    }
    else//���Һ��ӻ����޺���
    {
        return p->rightChild;
    }
}
