
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "IVFDSeqLinkList.h"
#include <QDebug>


SeqLinkList* SeqLinkList_Create(int capacity)
{
	TSeqLinkList *ret = NULL;
	if (capacity < 0)
	{
		return NULL;
	}
	ret = (TSeqLinkList *)malloc(sizeof(TSeqLinkList) + sizeof(unsigned int )*capacity );
	if (ret == NULL)
	{
		return NULL;
	}
	memset(ret, 0, sizeof(sizeof(TSeqLinkList)) + sizeof(unsigned int )*capacity );
	ret->node = (unsigned int *)(ret +1); //ret向后跳sizeof（TSeqLinkList）
	ret->capacity = capacity;
	ret->length = 0;
	return ret;
}

void SeqLinkList_Destroy(SeqLinkList* list)
{
	if (list == NULL)
	{
		return ;
	}
	free(list);
	return ;
}

//链表清零 。。。长度为零
void SeqLinkList_Clear(SeqLinkList* list)
{
	TSeqLinkList *tList = NULL; 

	if (list == NULL)
	{
		return ;
	}
	tList  = (TSeqLinkList *)list;
	tList->length = 0;
	return ;
}

int SeqLinkList_Length(SeqLinkList* list)
{
	TSeqLinkList *tList = NULL; 
	tList = (TSeqLinkList *)list;
	if (list == NULL)
	{
		return -1;
	}

	return tList->length;
}

//线性表的容量和线性表长度是不一样的
int SeqLinkList_Capacity(SeqLinkList* list)
{
	TSeqLinkList *tList = NULL; 
	tList = (TSeqLinkList *)list;
	if (list == NULL)
	{
		return -1;
	}

	return tList->capacity;
}

int SeqLinkList_Insert(SeqLinkList* list, SeqLinkListNode* node, int pos)
{
	int i = 0;
	TSeqLinkList *tList = NULL; 
	tList  = (TSeqLinkList *)list;

	if (list == NULL || node == NULL) 
	{
		return -1;
	}

	//查看是不是满了
	if (tList->length >= tList->capacity)
	{
		return -2;
	}

	//位置错误判断
	if (pos<0 || pos>=tList->capacity)
	{
		return -3;
	}

	//优化的容错。。。
	if (pos >=tList->length)
	{
		pos = tList->length;
	}

	//插入算法
	//从pos位置处开始，把数组后面的元素依此后移
	for(i=tList->length; i>pos; i--)
	{
		//把前的元素往后移
		tList->node[i] = tList->node[i-1];
	}
	//循环跳出以后，pos正好是，要出入的位置
	tList->node[pos] = (unsigned int)node;
	tList->length ++;
	return 0;
}

SeqLinkListNode* SeqLinkList_Get(SeqLinkList* list, int pos)
{

	SeqLinkListNode *ret = NULL;
	TSeqLinkList *tList = NULL;
	tList = (TSeqLinkList *)list;
	if (list == NULL || pos<0 || pos>=tList->length)
	{
		return NULL;
	}
	ret = (SeqLinkListNode*)tList->node[pos];
	return ret;
}

SeqLinkListNode* SeqLinkList_Delete(SeqLinkList* list, int pos)
{
    int	i;
    TSeqLinkList *tList = NULL;
    SeqLinkListNode	*ret = NULL;
	tList = (TSeqLinkList *)list;

    if(list==NULL){
        qDebug() << "3 SeqLinkListNode* SeqLinkList_Delete:list==NULL ";
        return NULL;
    }

    if (pos<0 || pos>=tList->length)
	{
//        qDebug() << "3 SeqLinkListNode* SeqLinkList_Delete:|| pos<0 || pos>=tList->length, pos = " << pos << "length = " << tList->length\

//                 << " tList->capacity=" << tList->capacity;
        return NULL;
	}

	//赋给a3之前，要把a3元素缓存下来
	ret = (SeqLinkListNode *)tList->node[pos];
	//删除算法
	for (i=pos+1; i<tList->length; i++)
	{
		tList->node[i-1] = tList->node[i];
	}
	tList->length --;

	return ret;
}
