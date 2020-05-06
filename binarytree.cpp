#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"queue.c"
typedef struct tnode *treeptr;
struct tnode
{
	int data;
	treeptr left,right;
};
int first=1;
int hasbothchild(struct tnode*tmp)
{
	return tmp&&(tmp->left)&&(tmp->right);
}
void insert(struct tnode**r,int data)
{
	struct tnode*temp=(item)malloc(sizeof(struct tnode));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	if(!*r)
	{
		*r=temp;
		printf("this is the first node\n");
	}
	else
	{
		if(first==1)
		{
			first==0;
			front++;
		}
		struct tnode *front1=getfront();
		if(!front1->left)
		front1->left=temp;
		else if(!front1->right)
		front1->right=temp;
		if(hasbothchild(front1))
		dequeue();
	}
	enqueue(temp);
}
void levelorder(struct tnode *r)
{
		enqueue(r);
		do 
		{
			struct tnode *t=dequeue();
			printf("%d\n",t->data);
			if(t->left)
			enqueue(t->left);
			if(t->right)
			enqueue(t->right);
		}while(!isempty());
		
}
int main()
{
		struct tnode*root=NULL;
		rear=front=-1;
		int i;
		for(i=10;i<=20;i++)
		insert(&root,i);
		rear=front=-1;
		levelorder(root);
		return 0;
}

