/*************************************************************************
    > File Name: seqlist.h
# File Name: seqlist.h
# Author :彭敬
# QQ : 784915651
# Email:784915651@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年11月21日 星期二 19时09分36秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int data_t;

typedef enum bool{false=0, true=1} bool;
#define SIZE 100

typedef struct{
	data_t data[SIZE];
	int last;
}Seqlist;

Seqlist *seqlist_create();
void seqlist_clear(Seqlist *seq);
bool seqlist_is_empty(Seqlist *seq);	
bool seqlist_is_full(Seqlist *seq);
int seqlist_get_length(Seqlist *seq);
bool seqlist_insert(Seqlist *seq, int pos, data_t value);
void seqlist_print(Seqlist *seq);
int seqlist_getvalue_byindex(Seqlist *seq, int pos);
bool seqlist_remove_byindex(Seqlist *seq, int pos);
//通过条件(函数指针)删除元素
bool seqlist_remove_bycondition(Seqlist *seq, bool(*condition)(data_t*, void*), void *cmpvalue);	
int seqlist_find_byvalue(Seqlist *seq, data_t value);
//按条件(函数指针)查找
int seqlist_find_bycondition(Seqlist *seq, bool(*condition)(data_t*, void*), void *cmpvalue);	
//遍历顺序表,并操作(函数指针)
bool seqlist_traverse(Seqlist *seq, void(*operate)(data_t*));
bool seqlist_modify_byindex(Seqlist *seq, int pos, data_t value);
