#include<stdio.h>#include<string.h>int next[100] = {0};int main(){	void get_next(char* p);	char a[100], b[100];	scanf_s("%s", a,100);  //输入	scanf_s("%s", b,100);	//输入	get_next(b);   //创建next	int len_a = strlen(a), len_b = strlen(b),i=0,j=0;	while (i < len_a && j < len_b)     	{ 		if (j == -1 || a[i] == b[j])		{			i++;			j++;		}		else			j = next[j];	}	/*	如果 主串第n个和模式串第一个比较如果不相等则j=-1；直接比较主串下一个和模式串第一个（j变为0）	如果主串第n个和模式串第m个不想等则让m变为前一个(m=next[m])	*/	if (j == len_b)	{		printf("ok %d",i-j);	}	return 0;}void get_next(char* p){	int len_p = strlen(p);	int i = 0, j = -1;	next[0] = j;	while (i < len_p)	{		if (j == -1 || p[i] == p[j])		{			i++;                                  //自我比对			j++;			next[i] = j;		}		else		{			j = next[j];		}	}}