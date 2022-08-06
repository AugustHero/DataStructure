// 1、已知数组A中的元素递增有序排列，其数据元素为整型，
// 现在有一个整数x，要将x插入到数组A中，并保持数组A仍递增有序。
// 请用你熟悉的高级语言写出实现上述要求的程序。建议用函数实现。

#include <stdio.h>
 
main()
{
    int a[10] = {0,1,2,3,4,6,7,8,9};
    int i=0,j=0,num=0;
    scanf("%d",&num);
    for (i=0;i<9;i++)
    {
        if (num<a[i])
        {
            for (j=8;j>=i;j--)
            {
                a[j+1] = a[j];
            }
            a[i]=num;
            break;
        }
    }
    for (i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
     
}