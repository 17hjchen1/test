
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define le 100
struct point
{
	char key[11];
};

//ð�������㷨 
int maopao(point c[])
{
	point a,b[le];
	int i,j,jh=0,bj=0,q;
	for(i=0;i<le;i++)
	{
		b[i]=c[i];
	}
	for(i=0;i<le;i++)
	{
		for(j=le-1;j>i;j--)
		{
			bj=bj+1;q=strcmp(b[i].key,b[j].key);
			if(q==1)
			{
				a=b[i];
				b[i]=b[j];
				b[j]=a;
				jh=jh+3;
			}
		}
	}
	printf("\nð�ݷ���:\n");
	for(i=0;i<le;i++){
		printf("%s\n",b[i].key);
	}
	printf("�Ƚϴ�����%d��\n����������%d��\n",bj,jh);
}
//ֱ�Ӳ�������
void zhijiecharu(point c[])
{
	point b[le+1];
	int i,j,jh=0,bj=0,q;
	for(i=0;i<le;i++){
		b[i+1]=c[i];
	}
	for(i=2;i<=le+1;i++)
	{
		q=strcmp(b[i].key,b[i-1].key);
		bj=bj+1;
		if(q==-1)
		{
			b[0]=b[i];
			b[i]=b[i-1];jh=jh+2;
			q=strcmp(b[0].key,b[i-2].key);bj=bj+1;
			for(j=i-2;q==-1;j--){
				b[j+1]=b[j];jh=jh+1;
				q=strcmp(b[0].key,b[j-1].key);bj=bj+1;
			}
			b[j+1]=b[0];jh=jh+1;
		}
	}
	printf("\nֱ��:\n");
	for(i=1;i<le+1;i++){
		printf("%s\n",b[i].key);
	}
printf("�Ƚϴ�����%d��\n����������%d��\n",bj,jh);
}
//ϣ�������㷨
 
void shellinsert(point c[],int dk,int d[])
{
	int j,i,q;
	point a;
	for(i=dk+1;i<le+1;i++)
	{
		q=strcmp(c[i].key,c[i-dk].key);d[0]=d[0]+1;
		if(q==-1)
		{
			a=c[i];q=strcmp(a.key,c[i-dk].key);d[0]=d[0]+1;d[1]=d[1]+1;
			for(j=i-dk;j>0&&q==-1;j=j-dk)
			{
				c[j+dk]=c[j];d[1]=d[1]+1;
				q=strcmp(a.key,c[j-dk].key);
			}
			c[j+dk]=a;d[1]=d[1]+1;
		}
	}
}
void shellsort(point c[],int dlta[],int t)
{
	int k,d[2],i;d[0]=0;d[1]=0;
	point b[le+1];
	for(k=0;k<le;k++)
	{
		b[k+1]=c[k];
	}
	for(k=0;k<t;k++)shellinsert(b,dlta[k],d);
		printf("\nϣ��������ɵ���������:\n");
	for(i=1;i<le+1;i++){
		printf("%s\n",b[i].key);
	}
	printf("�����бȽ�%d��,���н���%d��\n",d[0],d[1]);
}
//ϣ������
void xier(point c[])
{
	int dlta[20],t,i;t=le/2;
	for(i=0;i<20;i++)
	{		
		dlta[i]=t+1;
		if(t==0)break;
		t=t/2;
	}
	t=i+1;
	shellsort(c,dlta,t);
}
//��ѡ������
void jiandanxuanze(point c[])
{
	point a,b[le];
	int i,j,jh=0,bj=0,q,w;
	for(i=0;i<le;i++)
	{
		b[i]=c[i];
	}
	for(i=0;i<le-1;i++)
	{
		q=i;
		for(j=i+1;j<le;j++)
		{
			bj=bj+1;
			w=strcmp(b[q].key,b[j].key);
			if(w==1)q=j;
		}
		if(q==i)continue;
		else {
			a=b[i];
			b[i]=b[q];
			b[q]=a;
			jh=jh+3;
		}
	}
		printf("\n��ѡ��������ɵ���������:\n");
	for(i=0;i<le;i++){
	printf("%s\n",b[i].key);
	}
		printf("�����бȽ�%d��,���н���%d��\n",bj,jh);
}
int partition(point c[],int low,int high,int d[])
{
	point a,b;
	int jh=0,bj=0,q;
	a=c[low];
	while(low<high)
	{
		q=strcmp(c[high].key,a.key);d[0]=d[0]+1;
		while(low<high&&q!=-1){high--;q=strcmp(c[high].key,a.key);d[0]=d[0]+1;
		}
		b=c[low];
		c[low]=c[high];
		c[high]=b;
		d[1]=d[1]+3;
		q=strcmp(c[low].key,a.key);d[0]=d[0]+1;
		while(low<high&&q!=1){low++;q=strcmp(c[low].key,a.key);d[0]=d[0]+1;
		}	
		b=c[low];
		c[low]=c[high];
		c[high]=b;
		d[1]=d[1]+3;
	}
	return(low);
}
void qsort(point c[],int low,int high,int d[])
{
	int pivotloc;
	if(low<high)
	{
		pivotloc=partition(c,low,high,d);
		qsort(c,low,pivotloc-1,d);
		qsort(c,pivotloc+1,high,d);
	}
}

//��������
void kuaisu(point c[])
{
	point b[le];
	int i,d[2];
	d[0]=0;d[1]=0;
	for(i=0;i<le;i++)
	{
		b[i]=c[i];
	}
	qsort(b,0,le-1,d);
	printf("\n����������ɵ���������:\n");
	for(i=0;i<le;i++)
	{
	printf("%s\n",b[i].key);
	}
printf("�����бȽ�%d��,���н���%d��\n",d[1],d[0]);
}
void diu(point b[],int we,int *jh,int *bj)
{
	point a;int i,q;
	for(i=we/2-1;i>=0;i--)
	{
		q=strcmp(b[i].key,b[2*i].key);*bj=*bj+1;
		if(q==-1)
		{
			a=b[i];b[i]=b[2*i];b[2*i]=a;*jh=*jh+3;
		}
		if(2*i+1<we)
		{
			q=strcmp(b[i].key,b[2*i+1].key);*bj=*bj+1;
			if(q==-1)
			{
			a=b[i];b[i]=b[2*i+1];b[2*i+1]=a;*jh=*jh+3;
			}
		}
	}
	a=b[we-1];b[we-1]=b[0];b[0]=a;*jh=*jh+3;
}
//������
void diup(point c[])
{
	point b[le];
	int i,jh=0,bj=0,*j,*bl;
	j=&jh;bl=&bj;
	for(i=0;i<le;i++)
	{
		b[i]=c[i];
	}
	for(i=le;i>1;i--)
	{
		diu(b,i,j,bl);
	}
	printf("\n��������ɵ���������:\n");
	for(i=0;i<le;i++){
	printf("%s\n",b[i].key);
	}
	printf("�����бȽ�%d��,���н���%d��\n",bj,jh);
}
int main()
{
	int i,j,n,ans,an;
	char b[]="abcdefghijklmnopqrstuvwxyz";
	point a[le];
	for(i=0;i<le;i++)
	{
		n=10;
		an=rand()*(n-1)/RAND_MAX+1;
		n=26;
		for(j=0;j<an;j++){
			ans=rand()*(n-0)/RAND_MAX+0;
			a[i].key[j]=b[ans];
		}
a[i].key[j]='\0';
	}
	printf("�������������:\n");
	for(i=0;i<le;i++)
	{printf("%s\n",a[i].key);
	}
	int m;
	printf("ѡ��Ҫ���з��������򷽷�:\n");
	printf("1ð������\n2ֱ������\n3ϣ������\n4������\n5��������\n6������\n");
	scanf("%d",&m);
	if(m==1)
	maopao(a);
	else if(m==2)
	zhijiecharu(a);
	else if(m==3) 
	xier(a);
	else if(m==4)
	jiandanxuanze(a);
	else if(m==5)
	kuaisu(a);
	else if(m==6)
	diup(a);
int x;
printf("����0�˳���");
scanf("%d",&x);
for(;;)
{
if(x==0)
break;
}
return 0 ;
}
 
