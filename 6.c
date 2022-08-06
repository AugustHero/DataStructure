// 假设有一组数，例如，A=（9,5,7,6,8,2），存储在一个一维数组中，
// 现在我们要在7的前面插入一个数3，使得这组数变为了，A=（9,5,3,7,6,8,2）。
// 利用你学过的高级语言，请写出在已经存储数据的数组中，实现在其某个位置插入数据的程序。
// 若要实现删除数组中某个位置的数据，又如何实现，请给出实现程序。建议用函数实现。


#include<stdlib.h>
//插入函数
void insert(int* arr,int length,int i,int num){
	int* p,*q;
	p=&arr[length-2];
	q=&arr[i-1];
	for(;p>=q;p--){		
		*(p+1)=*p;
	}
	*q=num;
}

// 删除长度为len的数组dat中索引为idx的元素。
void  remove ( int  *dat,  int len,  int  idx)
{
     (len)--;
     if  (idx < 0 || idx >= len)
         return ;
     for  ( int  i = idx; i < len; i++)
         dat[i] = dat[i+1];
}

int main(int argc, char* argv[])
{
	
	int a[10]={0};
	a[0]=2;
	a[1]=3;
	a[2]=4;
	insert(a,sizeof(a)/sizeof(int),3,1);

	for(int i=0;i<10;i++)
	{
		printf("%d \t",a[i]);
	}
    remove(a,sizeof(a)/sizeof(int),3);

  	for(int i=0;i<10;i++)
	{
		printf("%d \t",a[i]);
	}
	return 0;
}


