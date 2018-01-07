#ifndef __SQ_QUEUE_H__
#define __SQ_QUEUE_H__
#include "Assistance.h"	// ���������

// ѭ��������

template<class ElemType>
class SeqQueue
{
protected:
	int front, length;									 // ��ͷ��βָ��
	int maxSize;										 // ��������
	ElemType *elems;									 // Ԫ�ش洢�ռ�

public:
	SeqQueue(int size = DEFAULT_SIZE);					 // ���캯��
	virtual ~SeqQueue();								 // ��������
	int GetLength() const;								 // ����г���
	bool IsEmpty() const;								 // �ж϶����Ƿ�Ϊ��
	bool IsFull() const;
	void Clear();										 // ���������
	void Traverse(void (*Visit)(const ElemType &)) const;// ��������
	Status DelQueue(ElemType &e);					     // ���Ӳ���
	Status GetHead(ElemType &e) const;				     // ȡ��ͷ����
	Status EnQueue(const ElemType e);				     // ��Ӳ���
};

// ѭ���������ʵ�ֲ���

template<class ElemType>
SeqQueue<ElemType>::SeqQueue(int size)
// �������������һ������Ϊsize�Ŀ�ѭ������
{
	maxSize = size;							// ���ö�������
//	if (elems != NULL) delete []elems;	// �ͷ����д洢�ռ�
	elems = new ElemType[maxSize];			// ����Ԫ�ش洢�ռ�
	length = front = 0;						// ��ʼ����ͷ���β
}

template <class ElemType>
SeqQueue<ElemType>::~SeqQueue()
// ������������ٶ���
{
	delete []elems;							// �ͷ�Ԫ�ش洢�ռ�
}

template<class ElemType>
int SeqQueue<ElemType>::GetLength() const
// ������������ض��г���
{
	return length;
}

template<class ElemType>
bool SeqQueue<ElemType>::IsEmpty() const
// ��������������Ϊ�գ��򷵻�true�����򷵻�false
{
   return length==0;
}

template<class ElemType>
bool SeqQueue<ElemType>::IsFull() const
{
    if(length==maxSize) return true;
    else return false;
}

template<class ElemType>
void SeqQueue<ElemType>::Clear()
// �����������ն���
{
	length = front = 0;
}

template <class ElemType>
void SeqQueue<ElemType>::Traverse(void (*Visit)(const ElemType &)) const
// ������������ζԶ��е�ÿ��Ԫ�ص��ú���(*visit)
{
	for (int i = front; i != front+length; i = (i + 1) % maxSize)
		(*Visit)(elems[i]);
}


template<class ElemType>
Status SeqQueue<ElemType>::DelQueue(ElemType &e)
// ���������������зǿգ���ôɾ����ͷԪ�أ�����e������ֵ����������SUCCESS,
// ����������UNDER_FLOW��
{
	if (!IsEmpty()) 	{	// ���зǿ�
		e = elems[front];					// ��e���ض�ͷԪ��
		front = (front + 1) % maxSize;		// frontָ����һԪ��
		length--;
		return SUCCESS;
	}
	else	// ����Ϊ��
		return UNDER_FLOW;
}

template<class ElemType>
Status SeqQueue<ElemType>::GetHead(ElemType &e) const
// ���������������зǿգ���ô��e���ض�ͷԪ�أ���������SUCCESS,
// ����������UNDER_FLOW��
{
	if (!IsEmpty()) 	{	    // ���зǿ�
		e = elems[front];		// ��e���ض�ͷԪ��
		return SUCCESS;
	}
	else
		return UNDER_FLOW;
}

template<class ElemType>
Status SeqQueue<ElemType>::EnQueue(const ElemType e)
// ��������������������������OVER_FLOW,
// �������Ԫ��eΪ�µĶ�β������SUCCESS
{
	if (length==maxSize)
		return OVER_FLOW;
	else	{	// ����δ������ӳɹ�
		elems[(front+length)%maxSize] = e;					// ����eΪ�¶�β
		length++;
		return SUCCESS;
	}
}


#endif
