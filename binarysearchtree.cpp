#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXSIZE 100
#define item int
typedef struct treenode{
	item data;
	struct treenode *lchild,*rchild;
};
typedef struct treenode *treeptr;
void queue_insert(treeptr x);
treeptr queue_delete();
int queue_empty();
treeptr q[100];
int front,rear;
treeptr iterative_bst_insert(treeptr root,item x);
treeptr recursive_bst_insert(treeptr root,item x);
treeptr iterative_bst_search(treeptr root,item x);
treeptr iterative_bst_search(treeptr root,item x);
treeptr bst_delete(treeptr root,item x);
void inorder(treeptr root,item x);
void inorder(treeptr root);
void print_in_between(treeptr root,item low_value,item high_value);
{
	treeptr root=NULL;int x;
	front=rear=0;
	scanf("%d",&x);
	while(x!=0)
	{
		root=iterative_bst_insert(root,x);
		scanf("%d",&x);
	}
	treeptr iterartive_bst_insert(treeptr root,item x)
	{
		treeptr p,t,parent;
		p=(treeptr)malloc(sizeof(struct treenode));
		p->data=x;
		p->lchild=p->rchild=NULL;
		if(r==NULL)
		return p;
		t=r;
		while(t!=NULL)
		{
			parent=t;
			if(x<t->data)
			t=t->lchild;
			else if(x>t->data)
			t=t->rchild;
			else
			{
				printf("duplicate node");
				free(p);
				return r;
			}
			
		}
		if(x<parent->data)
		parent->lchild=p;
		else 
		parent->rchild=p;
		return r;
	}
}
