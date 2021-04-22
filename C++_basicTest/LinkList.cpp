#include "LinkList.h"

//��ʼ������  �ɹ�����1��ʧ�ܷ���0
int LinkList::InitList(List **ppList) {//��Ϊ�˴�Ҫ�������pList����ָ�롣����Ҫ����ָ��ĵ�ַ���ö���ָ�룩

	//*(ppList)��pList,ָ���СΪ4�ֽ�
	*ppList = (List*)malloc(sizeof(List));//�����������ָ���ַ���ռ��СΪһ��ָ���С��ָ����32λ��4�ֽڣ�64λ��8�ֽڡ�

	if (NULL == *ppList)//���Ƿ���ʧ��
		return 0;
	else {
		//���Ƿ���ռ�ɹ������Խ�ͷָ�롢βָ�롢�ͽڵ������ʼ��ΪNULL��0��
		(*ppList)->pFront = NULL;
		(*ppList)->pRear = NULL;
		(*ppList)->count = 0;
	}
	return 1;
}

//�ж������Ƿ�Ϊ��
int LinkList::isEmpty(List *pList) {
	if (pList->count == 0)
		return 1;
	else
		return 0;
}

//Ϊ�������ڵ�Node
void LinkList::insertNode(List *pList, Node *pNode) {
	//�洢�ýڵ�ĵ�ַ�����ڲ���ʱ������ָ����һ���ڵ�ĵ�ַ��
	//β�巨
	if (LinkList::isEmpty(pList)) 
		pList->pFront = pNode;
	else {
		pList->pRear->pNext = pNode;
	}
	pList->pRear = pNode;
	pList->count++;

	//ͷ�巨
	/*
		if (LinkList::isEmpty(pList)){
			pList->pFront = pNode;
			pList->pRear = pNode;
			pList->count++;
		}
		else{
			pNode->next=pList->pFront->pNext;
			pList->pFront=pNode;
			pList->count++;
		}
		
	*/
}

//�������� 
void LinkList::TraversalList(List *pList, void(*Traversal)(Node *pNode)) {
	Node *pTemp = pList->pFront;
	int listSize = pList->count;

	while (listSize){
		Traversal(pTemp);
		pTemp = pTemp->pNext;
		listSize--;
	}
}

//�����ڵ�
int LinkNode::creatNode(Data *pdata) {
	LinkNode::initData();
	node.data.fdata = pdata->fdata;
	node.data.idata = pdata->idata;
	/*��ʼ���Ľڵ㣬������pNext��ΪNULL*/
	node.pNext = NULL;
	return 1;
}

//��ʼ���ڵ������
void LinkNode::initData(){
	node.data.fdata = 0;
	node.data.idata = 0;
}