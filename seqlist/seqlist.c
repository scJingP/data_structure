/*************************************************************************
    > File Name: seqlist.c
# File Name: seqlist.c
# Author :彭敬
# QQ : 784915651
# Email:784915651@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年11月21日 星期二 14时11分00秒
 ************************************************************************/

#include "seqlist.h"

//创建一个空表
Seqlist *seqlist_create(){
	Seqlist *seq = (Seqlist *)malloc(sizeof(Seqlist));
	if(seq == NULL){
		return NULL;	
	}
	memset(seq->data, 0, sizeof(seq->data));
	seq->last = -1;
	return seq;
}
//置空表
void seqlist_clear(Seqlist *seq){	
	memset(seq->data, 0, sizeof(seq->data));
	seq->last = -1;
}
//判断表是否为空
bool seqlist_is_empty(Seqlist *seq){	
	if(seq == NULL){	
		return -1;
	}
	return seq->last == -1 ? true : false;
}
//判断表是否满
bool seqlist_is_full(Seqlist *seq){	
	if(seq == NULL){	
		return -1;
	}
	return seq->last == SIZE-1 ? true : false;
}
//求表中元素个数
int seqlist_get_length(Seqlist *seq){
	if(seq == NULL){
		return -1;
	}
	return seq->last+1;
}
//插入一个元素
bool seqlist_insert(Seqlist *seq, int pos, data_t value){
	if(seq == NULL){
		return false;
	}
	if(seqlist_is_full(seq) == true){
		return false;
	}
	int len = seqlist_get_length(seq);
	if(pos < 0 || pos > len){
		return false;
	}
	int i=0;
	for(i=seq->last;i>=pos;i--){
		seq->data[i+1] = seq->data[i];
	}
	seq->data[pos] = value;
	seq->last++;
	return true;
}
//打印所有元素
void seqlist_print(Seqlist *seq){
	int len = seqlist_get_length(seq);
	int i=0;
	for(i=0;i<len;i++){
		printf("%-2d ", (seq->data)[i]);
	}
	printf("\n");
}
//获取指定位置的数据
int seqlist_getvalue_byindex(Seqlist *seq, int pos){
	if(seq == NULL) return -1;
	if(seqlist_is_empty(seq) == true) return -1;
	if(pos < 0 || pos > seq->last) return -1;
	return seq->data[pos];
}
//通过索引删除元素
bool seqlist_remove_byindex(Seqlist *seq, int pos){	
	if(seq == NULL) return false;
	if(seqlist_is_empty(seq) == true) return false;
	if(pos < 0 || pos > seq->last) return false;
	int i=0;
	for(i=pos;i<seq->last;i++){
		seq->data[i] = seq->data[i+1]; 
	}
	seq->last--;
	return true;
}
//通过条件(函数指针)删除元素
bool seqlist_remove_bycondition(Seqlist *seq, bool(*condition)(data_t*, void*), void *cmpvalue){	
	if(seq == NULL) return false;
	if(seqlist_is_empty(seq) == true) return false;
	int i=0;
	bool b_con = false;
	for(i=0;i<=seq->last;i++){
		b_con = condition(&(seq->data[i]), cmpvalue);
		if(true == b_con){
			seqlist_remove_byindex(seq, i);
		}
	}
	return true;
}
//按条件(函数指针)查找
bool seqlist_find_bycondition(Seqlist *seq, bool(*condition)(data_t*, void*), void *cmpvalue){	
	if(seq == NULL) return -1;
	if(seqlist_is_empty(seq) == true) return -1;
	int len = seqlist_get_length(seq);
	int i;
	bool b_con = false;
	for(i=0;i<len;i++){
		b_con = condition(&(seq->data[i]), cmpvalue);
		if(true == b_con) return i;
	}
	return true;
}
//遍历顺序表,并操作(函数指针)
bool seqlist_traverse(Seqlist *seq, void(*operate)(data_t*)){
	if(seq == NULL) return false;
	if(seqlist_is_empty(seq) == true) return false;
	int len = seqlist_get_length(seq);
	int i;
	for(i=0;i<len;i++){
		operate(&(seq->data[i]));
	}
	return true;
}
//按位置修改
bool seqlist_modify_byindex(Seqlist *seq, int pos, data_t value){
	if(seq == NULL) return false;
	if(seqlist_is_empty(seq) == true) return false;
	if(pos < 0 || pos > seq->last){
		return false;
	}
	seq->data[pos] = value;
	return true;
}

