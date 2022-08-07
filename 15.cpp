// 15、A、B是两个带头节点的元素递增有序的单链表。
// 请用你熟悉的高级语言写出实现将A、B合并成非递减有序的单链表C的程序。
// 建议用函数实现。

//https://blog.csdn.net/qq_39445165/article/details/94123616

#include<stdio.h>
#include<malloc.h>
typedef struct LNode{
	int data;
	LNode *next;
}LNode;
LNode *A, *B, *C;
void merge(LNode *A, LNode *B, LNode *&C){
	LNode *p = A->next;
	LNode *q = B->next;
	LNode *r;
	C = A;
	C->next = NULL;
	free(B);
	r = C;
	while(p != NULL && q != NULL){
		if(p->data <= q->data){
			r->next = p;
			p = p->next;
			r = r->next;
		}
		else{
			r->next = q;
			q = q->next;
			r = r->next;
		}
	}
	r->next = NULL;
	if(p != NULL){
		r->next = p;
	}
	if(q != NULL){
		r->next = q;
	}
}
 
void createLinkList(){
	LNode *pa;
	LNode *pb;
	//创建AB链表的头结点 
	A = (LNode*)malloc(sizeof(LNode));
	B = (LNode*)malloc(sizeof(LNode));
	pa = A;
	pb = B;
	//一开始的是要将其指针域赋值为空 
	pa->next = NULL;
	pb->next = NULL;
	
	for(int i = 1; i <= 20; i += 4){
		LNode *newNode = (LNode*)malloc(sizeof(LNode));
		newNode->data = i;
		pa->next = newNode;
		pa = pa->next;
	} 
	pa->next = NULL;
	for(int i = 2; i <= 8; i += 2){
		LNode *newNode = (LNode*)malloc(sizeof(LNode));
		newNode->data = i;
		pb->next = newNode;
		pb = pb->next;
	} 
	pb->next = NULL;
}
 
int main(void){
	createLinkList();
	merge(A, B, C);
	LNode *p = C;
	while(p->next != NULL){
		printf("%d ", p->next->data);
		p = p->next;
	} 
	return 0;
} 