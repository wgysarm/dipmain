#include "stdio.h"
#include "string.h"
#include "stdio.h"
#include "IVFDSeqQueue.h"
#include "IVFDSeqLinkList.h"

//java ssh 
//创建队列，相当于创建一个线性表
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

//向队列中添加元素，相当于 向线性表中，尾部插入元素
int SeqQueue_Append(SeqQueue* queue, void* item)
{
	return SeqLinkList_Insert(queue, item, SeqLinkList_Length(queue));
}

//从队列中删除元素，相当于从线性表中删除第一个元素
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