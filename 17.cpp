// 17、带头结点递增有序的单链表A，B(元素个数m、n)，请用你熟悉的高级语言，
// 写出求A-B，结果存储在A中保持递增程序。建议用函数实现。

/*
 * 题目：已知递增有序的单链表A、B (A、B中元素个数分别为m、n,
 *      且A、B都带有头结点)分别存储了一个集合，请设计算法，
 *     以求出两个集合A和B的差集A-B (仅由在A中出现而不在B中
 *    出现的元素所构成的集合)。将差集保存在单链表A中，并保
 *   持元素的递增有序性。
 */
#include <stdio.h>
#include <stdlib.h>
// 声明单链表的结构体
struct LNode {
	int data;
	struct LNode *next;
};
 
/* 使用尾插法建立单链表，即新添加的元素添加到链表的尾部 */
/* *&C指的是建立的单链表；a[]指的是批量添加的元素数组；n表示数组长度 */
void createListL(LNode *&C,int a[],int n) {
	LNode *temp,*node;
	// 创建一个带头节点的单链表
	C=(LNode *)malloc(sizeof(LNode));
	C->next=NULL;
	temp=C;
	// 循环遍历数组，批量为链表插入数据
	for(int i=0; i<n; i++) { // 循环申请n个结点来接收a中的元素
		node=(LNode *)malloc(sizeof(LNode)); // 创建新结点
		node->data=a[i]; // 为新结点赋予数据
		temp->next=node; // 将原尾结点的下一个结点指向新结点
		temp=temp->next; // 指向终端结点，以便接收下一个结点
	}
	temp->next=NULL; // 所有元素已经填装完成，将终端结点置为NULL
}
 
/* 打印单链表 */
/* *list指的是要被打印输出的单链表 */
void printList(LNode *list) {
	printf("\n");
	LNode *temp=list->next;
	while(temp!=NULL) { // 循环单链表
		printf("%ld\t",temp->data); // 打印单链表中的data数据
		temp=temp->next; // 遍历至下一个结点
	}
	printf("\n"); // 换行
}
 
/* 求递增链表A和递增链表B的差集A-B并保存在A链表中 */
/* *LA指的是链表A；*LB指的是链表B */
void difference(LNode *LA,LNode *LB) {
	/* 为什么需要一个pre呢？由于要删除结点，而链表需要将被删除结点的前一个结点与后一个结点连接起来，如果没有这个pre，那么就不清楚被删除结点的前一个结点了，也就不能连接起来链表 */
	LNode *la=LA->next,*lb=LB->next;// 将la指向LA的开始结点（即链表的第一个结点）；将lb指向LB的开始结点
	LNode *temp;// 临时指针变量，用来临时保存A链表中与B链表中相等的结点（也是要被删除的结点）
	LNode *pre=LA;// 用来记录A链表的头结点
	while(la!=NULL&&lb!=NULL) { // 循环A、B链表中的结点
		if(la->data<lb->data) { // 当la所指结点的元素值小于lb所指结点的元素值时
			pre=la;// 置为A表中的开始结点
			la=la->next;// la指向下一个结点
		} else if(la->data==lb->data) {// 当la所指结点的元素值等于lb所指结点的元素值时
			pre->next=la->next; // 将开始结点的next指向要被删除结点的next
			temp=la;// 临时保存被删除结点（也就是A表中与B表中元素值相等的结点 */
			la=la->next;// la指向下一个结点
			free(temp);// 是否结点资源
		} else if(la->data>lb->data) {// 当la所指结点的元素值大于lb所指结点的元素值时
			lb=lb->next;// lb指向下一个结点
		}
	}
}
 
int main() {
	LNode *LA,*LB;
	int a[]= {1,2,5};// 注意：在修改数组元素后，必须修改createListL()函数中的数组元素个数
	int b[]= {2,4,5};// 注意：在修改数组元素后，必须修改createListL()函数中的数组元素个数
	createListL(LA,a,3);// 创建A链表
	createListL(LB,b,3);// 创建B链表
	printList(LA);// 打印A链表
	printList(LB);// 打印B链表
 
	difference(LA,LB);// 求A-B
	printList(LA);// 打印A-B的差集后的链表
 
	return 0;
}