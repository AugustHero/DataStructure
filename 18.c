// 18、请用你熟悉的高级语言，
// 写出删除递增非空单链表中的重复结点的程序。
// 建议用函数实现。


void delete(LNode *L)
{
	LNode *p,*q;
	p = L->next;//p指向第一个结点
	while(p != NULL)
	{
		if(p->data == p->next->data)//如果相等则删除q指向的结点 
		{
			q = p->next;//q指向要删除的结点 
			p->next = q->next;
			free(q);
		}
		else
		{
			p = p->next;
		}
	} 
} 
