// 将n个整数存放在一维数组R中，请用你学过的高级语言，编写程序，
//将R中的数据(X0，X1，...，Xn-1)变为(Xp，Xp+1，...，Xn-1，X0，X1，...，Xp-1)。
//建议用函数实现。P23_10

#include <stdio.h>
 
void Reverse(int R[],int from,int to){
     int temp,i;
     for(i=0;i<(to-from+1)/2;i++){//循环要逆置的元素个数次
           temp = R[from+i];
           R[from+i] = R[to-i];
           R[to-i] = temp;
     }
}
 
void Converse(int R[],int n,int p){
     Reverse(R,0,p-1);
     Reverse(R,p,n);
     Reverse(R,0,n);
}

//例子
int a[10] = {0,1,2,3,4,5,6,7,8,9};
int main()
{ 
     Converse(a,9,3);
	 for(int i=0;i<10;i++) printf("%d ",a[i]);
	 printf("\n");
     return 0;
}