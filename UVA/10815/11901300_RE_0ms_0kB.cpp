#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
	int num;
	char str3[5500][50];
	char str1[300]={0};
	char str2[5500][200]={0};
	int i,j,r,c,m;
	r=0;
	while(scanf("%s",str1)!=EOF)
	{
		int len=strlen(str1);
		for(i=0; i<len; i++)
			str1[i]=tolower(str1[i]);
		
		for(m=0; m<len; m++)		//存进str2 
		{	
			c=0;
			int flag=0;
			while(isalpha(str1[m]))
			{
				str2[r][c]=tolower(str1[m]);
				c++,m++,flag=2;
			}
			if(flag==2) 
				r++;
		}
	}
	
	char str4[200]={0};
	int p;
	num=0;
	for(j=0 ;j<r; j++)
	{
		int flag=0;
		if(num==0)
		{
		strcpy(str3[num],str2[j]);
		num++;
		continue;		
		}

		for(i=0; i<num; i++)
		{
			if(strcmp(str3[i],str2[j])==0)
			{
				flag=1;
				break;
			}
		}
					
		if(!flag)
		{
		strcpy(str3[num],str2[j]);
		num++;
		}
	}
	
	for(i=0; i<num; i++)
	{
		p=i;
		for(j=i+1; j<num; j++)
		if(strcmp(str3[j],str3[p])<0)
			p=j;
		if(p!=i)
		{
			strcpy(str4,str3[i]);
			strcpy(str3[i],str3[p]);
			strcpy(str3[p],str4);
		}
	}
	
	for(i=0; i<num; i++)
		printf("%s\n",str3[i]);
	return 0;
}