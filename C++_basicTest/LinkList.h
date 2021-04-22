#pragma once
#include<stdlib.h>

struct Data {		//sizeof Data == 8
	int idata;
	float fdata;
};
struct Node {	//sizeof Node == 12
	Data data;
	Node *pNext;
};
struct List {		//sizeof List  == 12
	Node *pFront;
	Node *pRear;
	int count;
};

class LinkList {	//sizeof Data == 12
public:
	int InitList(List **ppNode) ;
	void TraversalList(List *pList, void(*Traverasl)(Node *pNode));
	int isEmpty(List *pList);
	void insertNode(List *pList, Node *pNode);
};

class LinkNode {
public:
	Node node;
	int creatNode(Data *pdata);
	void initData();
};
