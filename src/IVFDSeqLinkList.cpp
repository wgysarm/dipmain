
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
	ret->node = (unsigned int *)(ret +1); //ret�����sizeof��TSeqLinkList��
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

//�������� ����������Ϊ��
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

//���Ա�����������Ա����ǲ�һ����
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

	//�鿴�ǲ�������
	if (tList->length >= tList->capacity)
	{
		return -2;
	}

	//λ�ô����ж�
	if (pos<0 || pos>=tList->capacity)
	{
		return -3;
	}

	//�Ż����ݴ�����
	if (pos >=tList->length)
	{
		pos = tList->length;
	}

	//�����㷨
	//��posλ�ô���ʼ������������Ԫ�����˺���
	for(i=tList->length; i>pos; i--)
	{
		//��ǰ��Ԫ��������
		tList->node[i] = tList->node[i-1];
	}
	//ѭ�������Ժ�pos�����ǣ�Ҫ�����λ��
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

	//����a3֮ǰ��Ҫ��a3Ԫ�ػ�������
	ret = (SeqLinkListNode *)tList->node[pos];
	//ɾ���㷨
	for (i=pos+1; i<tList->length; i++)
	{
		tList->node[i-1] = tList->node[i];
	}
	tList->length --;

	return ret;
}
