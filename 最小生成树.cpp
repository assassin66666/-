#include<stdio.h>
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
/*���GΪ����ͼ��
       1������ɾ�����ж���<=1�ĵ㣬Ȼ������Щ�����������е�Ķ���-1��Ȼ�����ж���Ϊ1�ĵ���������
       2���Զ����е�ÿ���㣬�ظ�����1�����������û��ɾ���Ľڵ㣬��ô֤����ͼһ�����ڻ�·��
*/ 
int cycle(int a,int array[][3],int array3[100],int m)//(a��ͼ�ı���g����������ֱ���a[][]��b[][]��m���ܵ���,�ж��Ƿ��л�·)
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
	int n,m,d=0,e=0,g=0;//mΪ������nΪ����,d��e��forѭ���������� 
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
	        }//����ð�������Ƿ���ȷ
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
	    }//����ͼ�е�Ķ��� 
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
		}printf("\n");printf("%d %d\n",cycle(g,b,c,m),g);*/   //���� 
	    if(cycle(g,b,c,m)==0) //(a��ͼ�ı���g����������ֱ���a[][]��b[][],m���ܵ���)
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
