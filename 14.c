// 14、已知数组A中的存储了多个数据，其数据类型为整型，
// 现在要从数组A中删除所有重复数据，
// 要求移动元素的次数较少并使剩余数据的相对次序保持不变。
// 请用你熟悉的高级语言写出实现上述要求的程序。建议用函数实现。

#include <stdio.h>

#define N 1000

#define FLAG 0x80000000 /*特殊标记,用最小的负数表示*/
int del(int *,int);
void main()
{

    int r[N], length, i, j;    
    scanf("%d", &length);    
    for (i = 0; i < length; i++)
        scanf("%d", &r[i]);

    length = del(r,length); /*修改删除重复值后的数列的长度*/

    for (i = 0; i < length; i++)
        printf("%-9d", r[i]);
}
int del(int r[],int length){
    int  i, j;
    for (i = 0; i < length - 1; i++)
    {
        if (r[i] != FLAG)
        {
            for (j = i + 1; j < length; j++)
                if (r[j] == r[i])
                    r[j] = FLAG; /*遇到重复值,则先用特殊标记覆盖它*/
        }
    }
    for (i = 0; r[i] != FLAG; i++)
        ; /*找到第一个特殊标记*/

    for (j = i + 1; j < length;) /*删除数列中的特殊标记*/
    {
        if (r[j] != FLAG)
            r[i++] = r[j++];
        else
            j++;
    }
    return i;
}