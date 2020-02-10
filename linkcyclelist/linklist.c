/*************************************************************************
    > File Name: linklist.c
# File Name: linklist.c
# Author :彭敬
# QQ : 784915651
# Email:784915651@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年11月22日 星期三 16时02分32秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"linklist.h"

//创建链表
Linklist * linklist_create(){
	Linklist *head = (Linklist *)malloc(sizeof(Linklist));
	if(NULL == head){
		return NULL;
	}
	head->data = -1;
	head->next = head;
	return head;
}
//获取链表长度
int linklist_get_length(Linklist *head){
	if(NULL == head){
		return -1;
	}
	Linklist *p = head;
	int len=0;
	while(p->next != head){
		len++;
		p = p->next;
	}
	return len;
}
//增加链表元素
bool linklist_insert(Linklist *head, int pos, data_t data){
	if(NULL == head){
		return false;
	}
	int len = linklist_get_length(head);
	if(pos < 0 || pos > len){
		return false;
	}
	Linklist *p = head;
	while(pos-- > 0){
		p = p->next;
	}
	Linklist *new = linklist_create();
	if(NULL == new){
		return false;
	}
	new->data = data;
	new->next = p->next;
	p->next = new;
	return true;
}
//删除链表元素通过索引
bool linklist_delete_byindex(Linklist *head, int pos){
	if(NULL == head){
		return false;
	}
	int len = linklist_get_length(head);
	if(len <= 0){
		return false;
	}
	if(pos < 0 || pos > len){
		return false;
	}
	Linklist *p = head;
	while(pos-- > 0){
		p = p->next;
	}
	Linklist *pdel = p->next;
	p->next = pdel->next;
	free(pdel);
	pdel = NULL;
	return true;
}
//删除链表元素通过值
bool linklist_delete_byvalue(Linklist *head, data_t value){
	if(NULL == head){
		return false;
	}
	int len = linklist_get_length(head);
	if(len <= 0){
		return false;
	}
	Linklist *p = head->next;
	Linklist *p_front = head;
	while(p != head){
		if(value == p->data){
			p_front->next = p->next;
			free(p);
			p = p_front->next;
			continue;
		}
		p_front = p;
		p = p->next;

	}
	p = NULL;
	p_front = NULL;
	return true;
}
//编辑链表元素通过索引
bool linklist_modify_byindex(Linklist *head, int pos, data_t data){
	if(NULL == head){
		return false;
	}
	int len = linklist_get_length(head);
	if(len <= 0){
		return false;
	}
	if(pos < 0 || pos > len-1){
		return false;
	}
	Linklist *p = head->next;
	while(pos-- > 0){
		p = p->next;
	}
	p->data = data;
	return true;
}
//编辑链表元素通过值
bool linklist_modify_byvalue(Linklist *head, data_t oldval, data_t newval){
	if(NULL == head){
		return false;
	}
	int len = linklist_get_length(head);
	if(len <= 0){
		return false;
	}
	Linklist *p = head->next;
	while(p != head){
		if(p->data == oldval){
			p->data = newval;
		}
		p = p->next;
	}
	return true;
}

//按位置查找元素
bool linklist_find_byindex(Linklist *head, int pos, Linklist **retnode){
	if(NULL == head){
		return false;
	}
	int len = linklist_get_length(head);
	if(len <= 0){
		return false;
	}
	if(pos < 0 || pos > len-1){
		return false;
	}
	Linklist *p = head->next;
	while(pos-- > 0){
		p = p->next;
	}
	*retnode = p;
	p = NULL;
	return true;
}
//按值查找元素
bool linklist_find_byvalue(Linklist *head, data_t value, Linklist **retnode, int *pos){
	*pos = -1;
	if(NULL == head){
		return false;
	}
	int len = linklist_get_length(head);
	if(len <= 0){
		return false;
	}
	*pos = 0;
	Linklist *p = head->next;
	while(p != head){
		if(p->data == value){
			*retnode = p;
			return true;
		}
		*pos++;
		p = p->next;
	}
	return false;
}
//清空链表
void linklist_clear(Linklist *head){
	if(NULL == head){
		return;
	}
	Linklist *p = head->next;
	Linklist *p_next = NULL;
	while(p != head){
		p_next = p->next;
		free(p);
		p = p_next;
	}
	head->next = head;
}
//销毁链表
void linklist_destroy(Linklist **head){
	linklist_clear(*head);
	free(*head);
	*head = NULL;
}
//打印链表
void linklist_print(Linklist *head){
	if(NULL == head){
		return ;
	}
	Linklist *p = head->next;
	while(p != head){
		printf("%2d ", p->data);
		p = p->next;
	}
	printf("\n");
}
