// 7、假设有两个数组，A和B，分别存储了一组有序的数据，
// 比如，A=（2 4 6 8 10），B=（1,3,5,8,9），将数组A与数组B的元素合并，
// 使合并后的数组仍有序，变为C=（1,2,3,4,5,6,8,8,9）。
// 请用你学过的高级语言，写出将两个有序的数组合并为一个有序的数组的程序。建议用函数实现。

//  先创建一个新数组，此数组的大小大于或者等于两个已知数组大小的和。
//通过比较两个有序数组中的元素，谁小就把谁放到空数组，直到其中一个数组为空，最后把剩下的数组全部放到创建的数组里

#include<stdio.h>
#include<stdlib.h>
int* Merge(int*array1,int size1, int* array2,int size2)
{
    int index1 = 0;
    int index2 = 0;
    int index = 0;
    int*pTemp =malloc(sizeof(sizeof(int)*(size1+size2)));//创建一个大小为已知两个数组大小和的数组，用pTemp标记
    while (index1 < size1&&index2 < size2)//循环到其中一个数组为空，就退出循环
    {
        if (array1[index1] < array2[index2])//如果数组1的元素小于数组2的元素，就把数组1的元素放到新数组
            pTemp[index++] = array1[index1++];
        else
            pTemp[index++] = array2[index2++];//否则就把数组2的元素放到新数组
    }
    if (array1[index1])//退出循环后，如果数组1的元素未空，就把数组1的元素都放到新数组中，因为数组1是有序的，所以不用排序
        pTemp[index++] = array1[index1++];
    if (array2[index2])//退出循环后，如果数组2的元素未空，就把数组2的元素都放到新数组中，因为数组2是有序的，所以不用排序
        pTemp[index++] = array2[index2++];
    return pTemp;
}
int main()
{
    int *p;
    int size1 = 0;
    int size2 = 0;
    //int num = 0;
    int array1[] = { 1, 4, 6, 7, 9, 12 };
    int array2[] = { 2, 3, 4, 5, 6, 7, 8, 10 };
    size1 = sizeof(array1) /sizeof (array1[0]);//数组1的元素个数
    size2 = sizeof(array2) / sizeof (array2[0]); //数组2的元素个数
    int num = size1 + size2;
    int array[20] = { 0 };//新数组，此数组的大小必须大于或者等于数组1和数组2的大小之和
    p=Merge(array1, size1, array2, size2);
    for (int i = 0; i < num; ++i)//打印新数组
    {
        array[i] = *(p++);
        printf("%d \t",array[i]);

    }
    printf("\n");
    return 0;
}