#ifndef _IVFDSEQLINKLIST_H_ 
#define _IVFDSEQLINKLIST_H_

typedef void SeqLinkList;
typedef void SeqLinkListNode;

typedef struct _tag_SeqLinkList
{
    int capacity;
    int length;
    unsigned int *node; //unsigned int array[capacity]
}TSeqLinkList;

SeqLinkList* SeqLinkList_Create(int capacity);

void SeqLinkList_Destroy(SeqLinkList* list);

void SeqLinkList_Clear(SeqLinkList* list);

int SeqLinkList_Length(SeqLinkList* list);

int SeqLinkList_Capacity(SeqLinkList* list);

int SeqLinkList_Insert(SeqLinkList* list, SeqLinkListNode* node, int pos);

SeqLinkListNode* SeqLinkList_Get(SeqLinkList* list, int pos);

SeqLinkListNode* SeqLinkList_Delete(SeqLinkList* list, int pos);


#endif  
