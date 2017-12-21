#define BS 12
#include<stdio.h>
int a[BS][BS];
int me;

int en_count(int me,int i,int j)
{
	int count=0;
	if(me==1)
	{
		if(j==0)
		{
			for(int x=i+1;x<=BS-1;x++)
			{
				if(a[x][j]==0)
					count++;
				if(a[x][j+1]==0)
					count++;
			}
		}
		else if(j==BS-1)
		{
			for(int x=i+1;x<=BS-1;x++)
			{
				if(a[x][j]==0)
					count++;
				if(a[x][j-1]==0)
					count++;
			}
		}
		else
		{
			for(int x=i+1;x<=BS-1;x++)
			{
				if(a[x][j]==0)
					count++;
				if(a[x][j+1]==0)
					count++;
				if(a[x][j-1]==0)
					count++;
			}
		}
		return count ;
	}
	else
	{
		if(j==0)
		{
			for(int x=i-1;x>=0;x--)
			{
				if(a[x][j]==1)
					count++;
				if(a[x][j+1]==1)
					count++;
			}
		}
		else if(j==BS-1)
		{
			for(int x=i-1;x>=0;x--)
			{
				if(a[x][j]==1)
					count++;
				if(a[x][j-1]==1)
					count++;
			}
		}
		else
		{
			for(int x=i-1;x>=0;x--)
			{
				if(a[x][j]==1)
					count++;
				if(a[x][j+1]==1)
					count++;
				if(a[x][j-1]==1)
					count++;
			}
		}
	}
	return count;
}

int risk(int me,int i,int j)
{
	if(me==1)
	{
		if(i==BS-1)
			return 0;
		if(j==0)
		{
			if(a[i+1][j+1]==0)
				return 1;
			else
				return 0;
		}
		else if(j==BS-1)
		{
			if(a[i+1][j-1]==0)
				return 1;
			else
				return 0;
		}
		else
		{
			if(a[i+1][j+1]==0||a[i+1][j-1]==0)
				return 1;
			else
				return 0;
		}
	}
	else
	{
		if(i==0)
			return 0;
		if(j==0)
		{
			if(a[i-1][j+1]==1)
				return 1;
			else
				return 0;
		}
		else if(j==BS-1)
		{
			if(a[i-1][j-1]==1)
				return 1;
			else
				return 0;
		}
		else
		{
			if(a[i-1][j+1]==1||a[i-1][j-1]==1)
				return 1;
			else
				return 0;
		}
	}
}

void random_old()
{
	if(me==1)
	{
		for(int i=0;i<BS-1;i++)
		{
			for(int j=0;j<BS;j++)
			{
				if(a[i][j]==me)
				{
					if(a[i+1][j]==-1)
						printf("%d %d %d %d\n",i,j,i+1,j);
					if(a[i+1][j+1]==-1 && j!=BS-1)
						printf("%d %d %d %d\n",i,j,i+1,j+1);
					if(a[i+1][j-1]==-1 && j!=0)
						printf("%d %d %d %d\n",i,j,i+1,j-1);
				}
			}
		}
	}		
	else
	{
		for(int i=BS-1;i>0;i--)
		{
			for(int j=0;j<BS;j++)
			{
				if(a[i][j]==me)
				{
					if(a[i-1][j]==-1)
						printf("%d %d %d %d\n",i,j,i-1,j);
					if(a[i-1][j+1]==-1 && j!=BS-1)
						printf("%d %d %d %d\n",i,j,i-1,j+1);
					if(a[i-1][j-1]==-1 && j!=0)
						printf("%d %d %d %d\n",i,j,i-1,j-1);
				}
			}
		}
	}
}

void random()
{
	if(me==1)
	{
		for(int i=0;i<BS-1;i++)
		{
			for(int j=0;j<BS;j++)
			{
				if(a[i][j]==me)
				{
					if(a[i+1][j]==-1 && risk(me,i+1,j)==0)
						printf("%d %d %d %d\n",i,j,i+1,j);
					if(a[i+1][j+1]==-1 && j!=BS-1 && risk(me,i+1,j+1))
						printf("%d %d %d %d\n",i,j,i+1,j+1);
					if(a[i+1][j-1]==-1 && j!=0 && risk(me,i+1,j-1))
						printf("%d %d %d %d\n",i,j,i+1,j-1);
				}
			}
		}
	}		
	else
	{
		for(int i=BS-1;i>0;i--)
		{
			for(int j=0;j<BS;j++)
			{
				if(a[i][j]==me)
				{
					if(a[i-1][j]==-1 && risk(me,i-1,j)==0)
						printf("%d %d %d %d\n",i,j,i-1,j);
					if(a[i-1][j+1]==-1 && j!=BS-1 && risk(me,i-1,j+1))
						printf("%d %d %d %d\n",i,j,i-1,j+1);
					if(a[i-1][j-1]==-1 && j!=0 && risk(me,i-1,j-1))
						printf("%d %d %d %d\n",i,j,i-1,j-1);
				}
			}
		}
	}
}

int main()
{
	scanf("%d",&me);
	for(int i=0;i<BS;i++)
	{
		for(int j=0;j<BS;j++)
			scanf("%d",&a[i][j]);
	}
	if(me==1)
	{
		for(int i=BS-2;i>=0;i--)
		{
			for(int j=0;j<=BS-1;j++)
			{
				if(a[i][j]==me)
				{
					if(i==5 && (j==2||j==3))
					{
						if(a[i+1][8]==-1 && en_count(me,i+1,8)==0)
							printf("%d %d %d %d\n",i,j,i+1,8);
						else if(a[i+1][9]==-1 && en_count(me,i+1,9)==0)
							printf("%d %d %d %d\n",i,j,i+1,9);
					}
					if(i==5 && (j==8||j==9))
					{
						if(a[i+1][2]==-1 && en_count(me,i+1,2)==0)
							printf("%d %d %d %d\n",i,j,i+1,2);
						else if(a[i+1][3]==-1 && en_count(me,i+1,3)==0)
							printf("%d %d %d %d\n",i,j,i+1,3);
					}
					if(en_count(me,i,j)==0)
					{
						printf("%d %d %d %d\n",i,j,i+1,j);
					}
					if(j==0)
					{
						if(en_count(me,i+1,j+1)==0)
							printf("%d %d %d %d\n",i,j,i+1,j+1);
					}
					else if(j==BS-1)
					{
						if(en_count(me,i+1,j-1)==0)
							printf("%d %d %d %d\n",i,j,i+1,j-1);
					}
					else
					{
						if(en_count(me,i+1,j+1)==0)
							printf("%d %d %d %d\n",i,j,i+1,j+1);
						else if(en_count(me,i+1,j-1)==0)
							printf("%d %d %d %d\n",i,j,i+1,j-1);
					}
				}
			}
		}
	}
	else
	{
		for(int i=1;i<=BS-1;i++)
		{
			for(int j=0;j<=BS-1;j++)
			{
				if(a[i][j]==me)
				{
					if(i==6 && (j==2||j==3))
					{
						if(a[i-1][8]==-1 && en_count(me,i-1,8)==0)
							printf("%d %d %d %d\n",i,j,i-1,8);
						else if(a[i-1][9]==-1 && en_count(me,i-1,9)==0)
							printf("%d %d %d %d\n",i,j,i-1,9);
					}
					if(i==6 && (j==8||j==9))
					{
						if(a[i-1][2]==-1 && en_count(me,i-1,2)==0)
							printf("%d %d %d %d\n",i,j,i-1,2);
						else if(a[i-1][3]==-1 && en_count(me,i-1,3)==0)
							printf("%d %d %d %d\n",i,j,i-1,3);
					}
					if(en_count(me,i,j)==0)
					{
						printf("%d %d %d %d\n",i,j,i-1,j);
					}
					if(j==0)
					{
						if(en_count(me,i-1,j+1)==0)
							printf("%d %d %d %d\n",i,j,i-1,j+1);
					}
					else if(j==BS-1)
					{
						if(en_count(me,i-1,j-1)==0)
							printf("%d %d %d %d\n",i,j,i-1,j-1);
					}
					else
					{
						if(en_count(me,i-1,j+1)==0)
							printf("%d %d %d %d\n",i,j,i-1,j+1);
						else if(en_count(me,i-1,j-1)==0)
							printf("%d %d %d %d\n",i,j,i-1,j-1);
					}
				}
			}
		}
	}
	if(me==1)
	{
		for(int i=0;i<=BS-2;i++)
		{
			for(int j=0;j<BS;j++)
			{
				if(a[i][j]==me)
				{
					if(a[i+1][j+1]==0&&j<=BS-2)
						printf("%d %d %d %d\n",i,j,i+1,j+1);
					else if(a[i+1][j-1]==0&&j>=1)
						printf("%d %d %d %d\n",i,j,i+1,j-1);
				}
			}
		}
	}
	else
	{
		for(int i=BS-1;i>=1;i--)
		{
			for(int j=0;j<BS;j++)
			{
				if(a[i][j]==me)
				{
					if(a[i-1][j+1]==1&&j<=BS-2)
						printf("%d %d %d %d\n",i,j,i-1,j+1);
					else if(a[i-1][j-1]==1&&j>=1)
						printf("%d %d %d %d\n",i,j,i-1,j-1);
				}
			}
		}
	}
	random();
	random_old();
	return 0;
}