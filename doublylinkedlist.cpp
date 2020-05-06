#include<stdio.h>
#include<malloc.h>
typedef struct dnode*dptr;
dptr p;
struct dnode{
	int data;
	dptr lptr;
	dptr rptr;

};
void insertfront(int n)
{
	dptr q;
	q=(dptr)malloc(sizeof(struct dnode));
	q->data=n;
	q->rptr=p;
	q->lptr=NULL;
	if(p!=NULL)p->lptr=q;
	p=q;
}
void insertend(int x)
 {
 	dptr q,t;
 	if(p==NULL)
 	{
 		p=(dptr)malloc(sizeof(struct dnode));
 		p->lptr=NULL;
 		p->data=x;
 		p->rptr=NULL;
	return;
	}
	else
	{
		q=p;
		while(q->rptr!=NULL)
		{
			q=q->rptr;
		}
		t=(dptr)malloc(sizeof(struct dnode));
		t->lptr=q;
		t->data=x;
		t->rptr=NULL;
		q->rptr=t;
	
	}
}
void insertafter(int ele,int x)
{
	dptr q,t;
	q=p;
	while(q!=NULL)
	{
		if(q->data==ele)
		{
			t=(dptr)malloc(sizeof(struct dnode));
			t->data=x;
			t->lptr=q;
			t->rptr=q->rptr;
			if(q->rptr!=NULL)q->rptr->lptr=t;
			q->rptr=t;
			break;
		}
		else q=q->rptr;
	}
}
void insertafterposition(int pos,int x)
{
	dptr q,t;
	q=p;
	int c=1;
	while(q!=NULL)
	{ if(c==pos)
	{
		t=(dptr)malloc(sizeof(struct dnode));
		t->data=x;
		t->lptr=q;
		t->rptr=q->rptr;
		if(q->rptr!=NULL)q->rptr->lptr=t;
		q->rptr=t;
		break; 
	}
	else
	{
		q=q->rptr;
		c++;
	}
	}
	if(q==NULL)printf("entered wrong position value");
 } 
 int deletefront()
 {dptr q;
 q=p;
 p=p->rptr;
 int r=q->data;
 free(q);
 p->lptr=NULL;
 return r;
 }
 int deleteend()
 {
 	dptr q,t;
 	q=p;
 	while(q!=NULL)
 	{
 		if(q->rptr==NULL)
 		{
 			t=q->lptr;
 			int f=q->data;
 			free(q);
 			t->rptr=NULL;
 			return f;
		}
		else q=q->rptr;
	}
 }
 int deletemiddle(int z)
 {
 	dptr q,t;
	q=p;
	if(q->data==z)
	{
		p=p->rptr;
		int e=q->data;
		p->lptr=NULL;
		free(q);
		return e;
	  } 
	  else{
	  	while(q!=NULL)
	  	{
	  		if(q->data==z)
	  		{
	  			q->lptr->rptr=q->rptr;
	  			q->rptr->lptr=q->lptr;
	  			int e=q->data;
	  			free(q);
	  			return e;
			  }
			  else q=q->rptr;
		  }
	  }
 }
 void display()
 {
 	dptr q;
 	printf("\n");
 	for(q=p;q!=NULL;q=q->rptr)
 	printf("%d",q->data);
 	
 }
 int main()
 {
 	p=NULL;
 	int c,a,b,w,pos,w1,k,s,g,h;
 	do{
 		printf("\n 1.insertbegin\n 2.insertend\n3.insert after\n4.insertafterposition\n5.deletebegin\n6.deleteend\n7.deleteelement\n8.display\n9.exit");
 		printf("\nenter ur own choice");
 		scanf("%d",&c);
 		switch(c)
 		{
 			case 1:
 				printf("enter element");
 				scanf("%d",&a);
 				insertfront(a);
 				break;
 			case 2:
				printf("enter ele to b inserted at last");
				scanf("%d",&b);
				insertend(b);
				break;
			case 3:
			   printf("enter ele after which has to be inserted");
			   scanf("%d",&c);
			   printf("enter element to be inserted");
			   scanf("%d",&w);
			   insertafter(c,w);
			   break;
			case 4:
				printf("enter ele and pos");
				scanf("%d%d",&pos,&w1);
				insertafterposition(pos,w1);
				break;
			case 5:
				k=deletefront();
				printf("%d",k);
				break;
	       case 6:
		        s=deleteend();
				printf("%d",s);
				break;
			case 7:
			   printf("enter element to be deleted");
			   scanf("%d",&g);
			   h=deletemiddle(g);
			   printf("%d",&h);
			   break;
			case 8:
			      display();
			      break;
			default:
			  break;     
			  
			        	
		}
	}while(c<=8);
 }
	
0000
