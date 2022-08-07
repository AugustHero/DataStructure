//19、请用你熟悉的高级语言，
//写出删除带头结点单链表L中的唯一最小值结点的程序。
//建议用函数实现。可以参考P53_19
#include<stdio.h>
#include<stdlib.h>
typedef struct Lnode{
	int data;//数据域 
	struct Lnode *next;//指针域 
}Lnode,*LinkList;
int a[5]={9,1,3,2,5};
int n=5;
//这里使用尾插法，把数据放在L中 
void InitList(Lnode *L){
	Lnode *s,*r=L;//r为尾指针 
 
	        for(int i=0;i<n;i++){
			s=(Lnode *)malloc(sizeof(Lnode));//为指针s分配空间初始化 
			s->data=a[i];
			r->next=s;
			r=r->next;//	更新r的位置，始终指向最后一个元素，也可使用
			//r=s代替，同样是更新r的位置 
		
	}
	//依次添加完了，要把下r->next必须指向空 
	r->next=NULL;
	
} 
void PrintList(Lnode *L){
	Lnode *s=L->next;
	while(s){
		printf("%d	 ",s->data );
		s=s->next;  
	}
	printf("\n");
} 
 
 void Del_Min(LinkList &L){
    //L是带头结点的单链表，本算法是删除结点最小值的元素
    Lnode *pre=L,*p=pre->next;
    Lnode *minpre=pre,*min=p;
    while(p!=NULL){
        if(p->data<min->data){
           
            
            min=p;//遇到更小的，重新更新min的值
            minpre=pre; //同时minpre作为min的前驱结点，也要改变指向pre
            //才能保证minpre始终在min的前面一个位置
                                      
        }
        pre=p;
        p=p->next;    
    }
    minpre->next=min->next;
    free(min);
   
}
int main(){
	Lnode list;
	Lnode *L=&list;//指针初始化和引用
	InitList(L);
	PrintList(L);
 Del_Min(L);
 PrintList(L);
	return 0;
} 