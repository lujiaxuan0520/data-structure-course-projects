#ifndef POLY_NODE_
#define POLY_NODE_
enum Triple {var,ptr,num};//tag������

class PolyNode
{
    PolyNode *tlink;//ָ����һ������ָ��
    int exp;//ָ��
    Triple tag;//���
    union
    {
        char vble;//���ڵı�Ԫ��
        PolyNode *hlink;
        int coef;//ϵ��
    };
};
#endif // POLY_NODE_
