#include<stdio.h>
#include<conio.h>
void mergepass(int a[],int t[],int n,int s);
void merge(int a[],int t[],int b,int l,int m);
void mergesort(int a[],int n)
{
	int s,t[100];
	s=1;
	
	while(s<n)
	{
		mergepass(a,t,n,s);
		s=s*2;
		mergepass(t,a,n,s);
		s=s*2;
	}
}
void mergepass(int a[],int t[],int n,int s)
{
	int i,j;
	for(i=1;i<=n-2*s+1;i=i+2*s)
	merge(a,t,i,i+s-1,n);
	if(i+s-1<n)
	merge(a,t,i,i+s-1,n);
	else
	for(j=i;j<=n;j++)
	t[j]=a[i];
}
void merge(int a[],int t[],int b,int l,int m)
{
	int i,j,k;
	i=b;
	j=m+1;
	k=l;
	while(i<=m&&j<=l)
	{
		if(a[i]<a[j])
		{
			t[k]=a[i];
			i++;
			k++;
		}
		else
		{
			t[k]=a[j];
			j++;k++;
		}
	}
	while(i<=m)
	{
		t[k]=a[i];
		i++;
		k++;
	}
	while(j<=l)
	{
		t[k]=a[j];
		j++;k++;
	}
}
int main()
{
	int a[20],n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	mergesort(a,n);
	for(i=1;i<=n;i++)
	{
		printf("%d\t",a[i]);
	}
	getch();
}

