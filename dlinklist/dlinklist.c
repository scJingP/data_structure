/*************************************************************************
    > File Name: dlinklist.c
# File Name: dlinklist.c
# Author :彭敬
# QQ : 784915651
# Email:784915651@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年11月23日 星期四 10时30分55秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef enum bool {false = 0, true = 1}bool;
typedef int data_t;
typedef struct dlinklist{
	data_t data;
	struct dlinklist *prior;
	struct dlinklist *next;
}Dlinklist;

//创建双向链表
Dlinklist * dlinklist_create(){
	Dlinklist *head = (Dlinklist *)malloc(sizeof(Dlinklist));
	if(NULL == head){
		return NULL;
	}
	head->data = -1;
	head->prior = NULL;
	head->next = NULL;
	return head;
}
//获取双向链表长度
int dlinklist_get_length(Dlinklist *head){
	if(NULL == head){
		return -1;
	}
	int len = 0;
	Dlinklist *p = head->next;
	while(p != NULL){
		len++;
		p = p->next;
	}
	return len;
}
//判断双向链表空
bool dlinklist_is_empty(Dlinklist *head){
	if(NULL == head){
		return -1;
	}
	return (head->next == head->prior) ? true : false;
}
//双向链表插入元素
bool dlinklist_insert(Dlinklist *head, int pos, data_t data){
	if(NULL == head){
		return false;
	}
	int len = dlinklist_get_length(head);
	if(pos < 0 || pos > len){
		return false;
	}
	Dlinklist *new = (Dlinklist *)malloc(sizeof(Dlinklist));
	if(NULL == new){
		return false;
	}
	Dlinklist *p = head;
	while(pos-- > 0){
		p = p->next;
	}
	new->prior = p;
	new->next = p->next;
	new->data = data;
	if(p->next != NULL) p->next->prior = new;
	p->next = new;
	return true;
}
//打印双向链表
void dlinklist_print(Dlinklist *head){
	if(NULL == head){
		return;
	}
	Dlinklist *p = head->next;
	while(p != NULL){
		printf("%2d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//查询元素通过索引
Dlinklist * dlinklist_find_byindex(Dlinklist *head, int pos){
	if(NULL == head){
		return NULL;
	}
	int len = dlinklist_get_length(head);
	if(pos < 0 || pos >= len){
		return NULL;
	}
	Dlinklist *p = head->next;
	while(pos-- > 0){
		p = p->next;
	}
	return p;
}
//查询元素通过值
Dlinklist * dlinklist_find_byvalue(Dlinklist *head, data_t data){
	if(NULL == head){
		return NULL;
	}
	Dlinklist *p = head->next;
	while(p != NULL){
		if(p->data == data){
			return p;
		}
		p = p->next;
	}
	return NULL;
}
//修改元素值通过索引
bool dlinklist_modify_byindex(Dlinklist *head, int pos, data_t value){
	if(NULL == head){
		return false;
	}
	int len = dlinklist_get_length(head);
	if(pos < 0 || pos >= len){
		return false;
	}
	Dlinklist *p = head->next;
	while(pos-- > 0){
		p = p->next;
	}
	p->data = data;
	return true;
}
//修改元素值通过值
bool dlinklist_modify_byvalue(Dlinklist *head, data_t oldval, data_t newval){
	if(NULL == head){
		return false;
	}
	Dlinklist *p = head->next;
	while(p != NULL){
		if(p->data == oldval){
			p->data = newval;
		}
		p = p->next;
	}
	return true;
}
//删除一个元素通过索引
bool dlinklist_deleteone(Dlinklist *head, int pos){
	if(NULL == head){
		return false;
	}
	int len = dlinklist_get_length(head);
	if(pos < 0 || pos >= len){
		return false;
	}
	Dlinklist *p = head;
	while(p != NULL){
		p = p->next;
	}
	Dlinklist *p_curr = p->next;
	p->next = p_curr->next;
	p_curr->prior = p;
	free(p_curr);
	return true;
}
//删除多个元素通过索引、长度
bool dlinklist_deletemany(Dlinklist *head, int pos, int length){
	if(NULL == head){
		return false;
	}
	int len = dlinklist_get_length(head);
	if(pos < 0 || pos >= len){
		return false;
	}
	if(length < 0 || pos + length >= len){
		return false;
	}
	while(length-- > 0){
		if(dlinklist_deleteone(head, pos) == false){
			return false;
		}
	}
	return true;
}
//清空元素
void dlinklist_clear(Dlinklist *head){
	if(NULL == head){
		return ;
	}
	Dlinklist *p = head->next;
	Dlinklist *p_next = NULL;
	while(p != NULL){
		p_next = p->next;
		free(p);
		p = p_next;
	}
	head->next = NULL;
}
//销毁Dlinklist
void dlinklist_destroy(Dlinklist **head){
	dlinklist_clear(*head);
	free(*head);
	*head = NULL;
}

int main(int argc, char *argv[])
{
	Dlinklist *dlink = dlinklist_create();
	if(NULL == dlink){
		printf("dlink create fail\n");
		return -1;
	}
	bool isempty = dlinklist_is_empty(dlink);
	if(true == isempty){
		printf("dlink is empty\n");
	}
	int i=0;
	while(i < 10){
		dlinklist_insert(dlink, i, i);	
		i++;
	}
	dlinklist_print(dlink);
	
}
