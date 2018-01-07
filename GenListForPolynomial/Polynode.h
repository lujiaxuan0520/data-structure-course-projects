#ifndef POLY_NODE_
#define POLY_NODE_
enum Triple {var,ptr,num};//tag的类型

class PolyNode
{
    PolyNode *tlink;//指向下一个结点的指针
    int exp;//指数
    Triple tag;//标记
    union
    {
        char vble;//基于的变元名
        PolyNode *hlink;
        int coef;//系数
    };
};
#endif // POLY_NODE_
