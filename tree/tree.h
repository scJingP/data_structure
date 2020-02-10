/*************************************************************************
    > File Name: tree.h
# File Name: tree.h
# Author :彭敬
# QQ : 784915651
# Email:784915651@qq.com
# Blog：http://www.cnblogs.com/shenlanqianlan/
# Created Time: 2017年11月27日 星期一 10时38分05秒
 ************************************************************************/
#ifndef TREE_H
#define TREE_H

#include<stdio.h>
typedef int data_tree_t;
typedef struct tree{
	data_tree_t data;
	struct tree *lchild, *rchild;
}Tree;
/*
 * 创建完全二叉树
 * i:编号，n:节点个数
 */
Tree* tree_create(int i, int n);
//先序遍历
void tree_dlr(Tree *root);
//中序遍历
void tree_ldr(Tree *root);
//后序遍历
void tree_lrd(Tree *root);
//层次遍历
void tree_level(Tree *root);


#endif
