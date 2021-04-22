#include "LinkList.h"

//初始化链表  成功返回1，失败返回0
int LinkList::InitList(List **ppList) {//因为此处要处理的是pList，是指针。所以要代入指针的地址（用二级指针）

	//*(ppList)即pList,指针大小为4字节
	*ppList = (List*)malloc(sizeof(List));//※这里配二级指针地址，空间大小为一级指针大小。指针在32位中4字节；64位中8字节。

	if (NULL == *ppList)//这是分配失败
		return 0;
	else {
		//这是分配空间成功，所以将头指针、尾指针、和节点个数初始化为NULL和0；
		(*ppList)->pFront = NULL;
		(*ppList)->pRear = NULL;
		(*ppList)->count = 0;
	}
	return 1;
}

//判断链表是否为空
int LinkList::isEmpty(List *pList) {
	if (pList->count == 0)
		return 1;
	else
		return 0;
}

//为链表插入节点Node
void LinkList::insertNode(List *pList, Node *pNode) {
	//存储该节点的地址，用于插入时，用于指向下一个节点的地址；
	//尾插法
	if (LinkList::isEmpty(pList)) 
		pList->pFront = pNode;
	else {
		pList->pRear->pNext = pNode;
	}
	pList->pRear = pNode;
	pList->count++;

	//头插法
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

//遍历链表 
void LinkList::TraversalList(List *pList, void(*Traversal)(Node *pNode)) {
	Node *pTemp = pList->pFront;
	int listSize = pList->count;

	while (listSize){
		Traversal(pTemp);
		pTemp = pTemp->pNext;
		listSize--;
	}
}

//创建节点
int LinkNode::creatNode(Data *pdata) {
	LinkNode::initData();
	node.data.fdata = pdata->fdata;
	node.data.idata = pdata->idata;
	/*初始化的节点，将所有pNext设为NULL*/
	node.pNext = NULL;
	return 1;
}

//初始化节点的数据
void LinkNode::initData(){
	node.data.fdata = 0;
	node.data.idata = 0;
}