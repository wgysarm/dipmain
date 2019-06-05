#include "stdio.h"
#include "string.h"
#include "stdio.h"
#include "IVFDSeqQueue.h"
#include "IVFDSeqLinkList.h"

//java ssh 
//�������У��൱�ڴ���һ�����Ա�
SeqQueue* SeqQueue_Create(int capacity)
{
	return SeqLinkList_Create(capacity);
}

void SeqQueue_Destroy(SeqQueue* queue)
{
	SeqLinkList_Destroy(queue);
}

void SeqQueue_Clear(SeqQueue* queue)
{
	SeqLinkList_Clear(queue);
}

//����������Ԫ�أ��൱�� �����Ա��У�β������Ԫ��
int SeqQueue_Append(SeqQueue* queue, void* item)
{
	return SeqLinkList_Insert(queue, item, SeqLinkList_Length(queue));
}

//�Ӷ�����ɾ��Ԫ�أ��൱�ڴ����Ա���ɾ����һ��Ԫ��
void* SeqQueue_Retrieve(SeqQueue* queue)
{
	return SeqLinkList_Delete(queue, 0);
}

void* SeqQueue_Header(SeqQueue* queue)
{
	return SeqLinkList_Get(queue, 0);
}

int SeqQueue_Length(SeqQueue* queue)
{
	return SeqLinkList_Length(queue);
}

int SeqQueue_Capacity(SeqQueue* queue)
{
	return SeqLinkList_Capacity(queue);
}