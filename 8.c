// 8、所谓回文是正读和反读均相同的字符串，
// 例如abcba或abba是回文，而abcda不是回文。
// 请用学过的高级语言，给出判断给定字符串是否是回文的程序。建议用函数实现。
//P66_4 队列队列知识
//下面是简单函数实现 存在问题应该 建议看书


#include<stdio.h>
#include<string.h>
int main(){
	int i, sign=1, length; 	//符号变量sign 
	char str[10];			//定义一个字符数组 
	printf("输入长度不超过10的字符串：\n");
	gets(str);				//直接接收一个字符串并存入数组(需先导入string.h) 
	length=strlen(str);		//测量所输入字符串的长度 
	for(i=0; i<length/2; i+=2){	 
		if(str[i]!=str[length-2-i])		//从两端开始比较每一个字符是否相等 
			sign=0;break;				//如果对比时出现不相等情况，使sign置0并立即跳出循环 
	}
	if(sign) printf("该字符串是回文");	//通过sign值判断该字符串是否为回文
	else  printf("该字符串不是回文");
	return 0;                	
} 