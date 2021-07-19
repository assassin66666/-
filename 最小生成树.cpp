#include<stdio.h>
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
/*如果G为无向图：
       1）首先删除所有度数<=1的点，然后将与这些点相连的所有点的度数-1，然后将所有度数为1的点加入队列中
       2）对队列中的每个点，重复过程1），如果还有没被删除的节点，那么证明该图一定存在回路。
*/ 
int cycle(int a,int array[][3],int array3[100],int m)//(a是图的边数g，两个数组分别是a[][]和b[][]，m是总点数,判断是否有回路)
{
	int num=1,k=0,t=0;
	int array2[100];
	for(int i=0;i<m;i++)
	{
		array2[i]=array3[i];
	}
	while(num)
	{
		for(int i=0;i<m;i++)
	   {
		   if(array2[i]==1)
		   {
		   	    for(int j=0;j<a;j++)
		       {
			        if(array[j][0]==i+1)
			        {
			        	array2[array[j][1]-1]--;
					}
					if(array[j][1]==i+1)
			        {
			        	array2[array[j][0]-1]--;
					}
		       }
		       array2[i]=0;
		   }
		   
	   }
	   num=0;
	   k=0;
	   for(int i=0;i<m;i++)
	   {
	   	    if(array2[i]==1) num=1;
			if(array2[i]>0)  k=1;
	   } 
	}
	if(num==0&&k==0) t=1;
	return t;
}

int main()
{
	int n,m,d=0,e=0,g=0;//m为点数，n为边数,d，e在for循环做计数器 
	int a[100][3],b[100][3],c[100]; 
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
			b[i][j]=0;
		}
	}
	for(int i=0;i<m;i++)
	{
		c[i]=0;
	 } 
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j][2]>a[j+1][2])
			{
				swap(&a[j][2],&a[j+1][2]);
				swap(&a[j][1],&a[j+1][1]);
				swap(&a[j][0],&a[j+1][0]);
			}
			
		}
	}
	/*for(int i=0;i<n;i++)
	       {
		      for(int j=0;j<3;j++)
		      {
			   printf("%d ",a[i][j]);
		      }
		       printf("\n");
	        }//测试冒泡排序是否正确
	        printf("\n");*/
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<m;j++)
	    {
			if(a[i][0]==j+1)
			{
				c[j]++;
				d=j;
			}
			if(a[i][1]==j+1)
			{
				c[j]++;
				e=j;
			}
	    }//计算图中点的度数 
	    b[g][0]=a[i][0];
	    b[g][1]=a[i][1];
	    b[g][2]=a[i][2];
		g++;
			/*	for(int i=0;i<g;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d ",b[i][j]);
		}
		printf("\n");
		
	}	for(int i=0;i<m;i++)
		{
			printf("%d ",c[i]);
		}printf("\n");printf("%d %d\n",cycle(g,b,c,m),g);*/   //测试 
	    if(cycle(g,b,c,m)==0) //(a是图的边数g，两个数组分别是a[][]和b[][],m是总点数)
		{
			c[d]=c[d]-1;
			c[e]=c[e]-1;
			g--;
			b[g][0]=0;
	        b[g][1]=0;
	        b[g][2]=0;
	        
		}
        /*for(int i=0;i<m;i++)
		{
			printf("%d ",c[i]);
		}printf("\n");*/
	
	}
	  
	for(int i=0;i<g;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
