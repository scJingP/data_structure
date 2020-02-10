/*************************************************************************
    > File Name: linklist.h
# File Name: linklist.h
# Author :彭敬
# QQ : 784915651
# Email:784915651@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年11月22日 星期三 16时05分03秒
 ************************************************************************/

#ifndef LINKLIST_H
#define LINKLIST_H

#include<stdio.h>
typedef enum bool{false=0, true=1} bool;
typedef int data_t;
typedef struct Linklist_t{
	data_t data;
	struct Linklist_t *next;
}Linklist;

//创建链表
Linklist * linklist_create();
//获取链表长度
int linklist_get_length(Linklist *head);
//增加链表元素
bool linklist_insert(Linklist *head, int pos, data_t data);
//删除链表元素通过索引
bool linklist_delete_byindex(Linklist *head, int pos);
//删除链表元素通过值
bool linklist_delete_byvalue(Linklist *head, data_t value);
//编辑链表元素通过索引
bool linklist_modify_byindex(Linklist *head, int pos, data_t data);
//编辑链表元素通过值
bool linklist_modify_byvalue(Linklist *head, data_t oldval, data_t newval);
//按位置查找元素
bool linklist_find_byindex(Linklist *head, int pos, Linklist **retnode);
//按值查找元素
bool linklist_find_byvalue(Linklist *head, data_t value, Linklist **retnode, int *pos);
//清空链表
void linklist_clear(Linklist *head);
//销毁链表
void linklist_destroy(Linklist **head);
//打印链表
void linklist_print(Linklist *head);

#endif
