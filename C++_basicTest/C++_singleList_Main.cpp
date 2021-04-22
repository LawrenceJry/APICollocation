#include <iostream>
#include <windows.h>
#include "LinkList.h"

using namespace std;

void drawData(Node *pNode) {
	cout <<"Address: "<<pNode<< "    Float: " << pNode->data.fdata << "   Int: " << pNode->data.idata << endl;
}

int main(){

	//cout << "Data:	" << sizeof(Data) << endl;
	//cout << "Node:	" << sizeof(Node) << endl;
	//cout << "List:	" << sizeof(List) << endl;
	//cout << "List*:	" << sizeof(List*) << endl;
	//cout << "LinkList:	" << sizeof(LinkList) << endl;

	LinkList lList;
	List *pList;//定义一个指针
	lList.InitList(&pList);//指针初始化

	Data data;
	Data *pdata = &data;

	int InsertTimes;
	cout << "Input Insert Times: " << endl;
	cin >> InsertTimes;

	while (InsertTimes--) {
		LinkNode *lNode=(LinkNode*)malloc(sizeof(LinkNode));//在循环中，需要分配地址，让局部变量的地址发生变化
		data.fdata = rand()%1000/10;
		data.idata = rand()%2048;
		lNode->creatNode(pdata);
		lList.insertNode(pList, &lNode->node);
		Sleep(100);
	}
	lList.TraversalList(pList, drawData);

	return 0;
}
