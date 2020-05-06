#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct Lnode *lptr;
struct Lnode
{
    int data;
    lptr ptr;
};
lptr p;
void insertFront(int x)
{
    lptr q;
    q=(lptr)malloc(sizeof(struct Lnode));
    q->data=x;
    q->ptr=p;
    p=q;
}
void insertEnd(int x)
{
    lptr q,r;
    if(p=NULL)
    {
        p=(lptr)malloc(sizeof(struct Lnode));
        p->data=x;
        p->ptr=NULL;
    }
    else
    {
        q=p;
        while(q->ptr!=NULL)
        {
            q=q->ptr;
        }
        r=(lptr)malloc(sizeof(struct Lnode));
        r->data=x;
        r->ptr=NULL;
        q->ptr=r;
    }
}
void insertAfter(int z,int x)
{
    lptr q,t;
    q=p;
    while(q!=NULL)
    {
        if(q->data==z)
        {
            t=(lptr)malloc(sizeof(struct Lnode));
            t->data=x;
            t->ptr=q->ptr;
            q->ptr=t;
            break;
        }
        else
        {
            q=q->ptr;
        }
    }
}
int deleteBegin()
{
    int x;
    lptr q;
    q=p;
    p=p->ptr;
    x=q->data;
    free(q);
    return x;
}
int deleteLast()
{
    lptr q,r;
    q=p;
    while(q!=NULL)
    {
        if(q->ptr==NULL)
        {
            int k=q->data;
            free(q);
            return k;
        }
        else
        {
            if(q->ptr->ptr==NULL)
            {
                r=q->ptr;
                int k=r->data;
                free(r);
                q->ptr=NULL;
                return k;
            }
            else
            {
                q=q->ptr;
            }
        }
    }
}
int deleteParticular(int z)
{
    lptr q,r;
    q=p;
    if(q->data==z)
    {
        p=q->ptr;
        int x=q->data;
        free(q);
        return x;
    }
    else
    {
        r=q;
        while(q!=NULL)
        {
            if(q->data==z)
            {
                r->ptr=q->ptr;
                int k=q->data;
                free(q);
                return k;
            }
            else
            {
                r=q;
                q=q->ptr;
            }
        }
    }
}
void insertAfterPosition(int pos,int x)
{
    lptr t,q;
    t=p;
    int c=1;
    while(t!=NULL)
    {
        if(c==pos)
        {
            q=(lptr)malloc(sizeof(struct Lnode));
            q->data=x;
            q->ptr=t->ptr;
            t->ptr=q;
            break;
        }
        else
        {
            t=t->ptr;
            c++;
        }
    }
    if(t==NULL)
        printf("\n Entered Wrong position value...");
}
int find(int ele)
{
    lptr q;
    q=p;
    int c=1;
    while(q!=NULL)
    {
        if(q->data==ele)
            return c;
        else
            c++;
            q=q->ptr;
    }
    if(q==NULL)
        printf("\n Entered NON Existing element...");
}
void makeEmpty()
{
    lptr q,r;
    q=p;
    while(q!=NULL)
    {
        r=q;
        q=q->ptr;
        free(r);
    }
    p=NULL;
}
void display()
{
    lptr q;
    q=p;
    printf("\n");
    while(q!=NULL)
    {
        printf("%d ",q->data);
        q=q->ptr;
    }
}

int main()
{
    int c,b,bl,d,y,w,k,f,j,pos,x2,ele,pn;
    do
    {
        printf("\n 1.insertFront \n 2.insertLast \n 3.insertAfter ");
        printf("\n 4.deleteBegin \n 5.deleteLast \n 6.deleteParticular \n 7.display ");
        printf("\n 8.insertAfterPosition \n 9.find \n 10.makeEmpty ");
        printf("\n Enter your choice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("\n Enter an element at begin : ");
                scanf("%d",&b);
                insertFront(b);
                break;
            case 2:
                printf("\n Enter an element at last : ");
                scanf("%d",&bl);
                insertEnd(bl);
                break;
            case 3:
                printf("\n Enter values of element after which you want to insert and element to be inserted : ");
                scanf("%d%d",&d,&y);
                insertAfter(d,y);
                break;
            case 4:
                w=deleteBegin();
                printf("\n The element at the beginning is : %d",w);
                break;
            case 5:
                k=deleteLast();
                printf("\n The last element is : %d",k);
                break;
            case 6:
                printf("\n Enter element to be deleted : ");
                scanf("%d",&j);
                f=deleteParticular(j);
                printf("\n The deleted element is : %d",f);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("\n Enter the position and element to be inserted : ");
                scanf("%d%d",&pos,&x2);
                insertAfterPosition(pos,x2);
                break;
            case 9:
                printf("\n Enter the element to know the position : ");
                scanf("%d",&ele);
                pn=find(ele);
                printf("\n Position of %d is : %d",ele,pn);
                break;
            case 10:
                makeEmpty();
                break;
            
            default :
                break;
        }
    }
    while(c<=10);
    getch();
    return 0;
}

