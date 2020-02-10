/*************************************************************************
    > File Name: tree.c
# File Name: tree.c
# Author :彭敬
# QQ : 784915651
# Email:784915651@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年11月24日 星期五 17时10分56秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
#include"sequeue.h"

/*
 * 创建完全二叉树
 * i:编号，n:节点个数
 */
Tree* tree_create(int i, int n){
	Tree *root = (Tree *)malloc(sizeof(Tree));
	root->data = i;
	if(NULL == root){
		return NULL;
	}
	if(2*i<=n){
		root->lchild = tree_create(2*i, n);
	}else{
		root->lchild = NULL;
	}
	if(2*i+1<=n){
		root->rchild = tree_create(2*i+1, n);
	}else{
		root->rchild = NULL;
	}
	return root;
}
//先序遍历
void tree_dlr(Tree *root){
	if(NULL == root){
		return;	
	}
	printf("%d ", root->data);
	tree_dlr(root->lchild);
	tree_dlr(root->rchild);
	return;
}
//中序遍历
void tree_ldr(Tree *root){
	if(NULL == root){
		return;	
	}
	tree_ldr(root->lchild);
	printf("%d ", root->data);
	tree_ldr(root->rchild);
	return;
}
//后序遍历
void tree_lrd(Tree *root){
	if(NULL == root){
		return;	
	}
	tree_lrd(root->lchild);
	tree_lrd(root->rchild);
	printf("%d ", root->data);
	return;
}
//层次遍历
void tree_level(Tree *root){
	if(NULL == root){
		return;
	}
	Sequeue *seq = sequeue_create();
	if(NULL == seq){
		return;
	}
	sequeue_enqueue(seq, root);
	while(sequeue_is_empty(seq) == false){
		Tree *t = NULL;
		bool res = sequeue_dequeue(seq, &t);
		if(res == false){
			printf("dequeue fail\n");
			return;
		}
		printf("%d ", t->data);
		if(t->lchild != NULL){
			sequeue_enqueue(seq, t->lchild);
		}
		if(t->rchild != NULL){
			sequeue_enqueue(seq, t->rchild);
		}
	}
	return;
}
