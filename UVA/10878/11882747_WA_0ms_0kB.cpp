#include<stdio.h>
int main()
{
	char str[11]={0};
	int num[11]={0,0,64,32,16,8,0,4,2,1,0};
	int i;
	int flag=0;
	while(1)
	{
		gets(str);
		if(str[0]=='_')
		{
			flag++;
			if(flag==1)	continue;
			if(flag==2)	break;
		}
		int ans;
		for(i=0; i<11; i++)
		{
			if(str[i]=='o')
				ans+=num[i];
		}
		if(ans!=0)
		printf("%c",ans);		
	}
	return 0;
}