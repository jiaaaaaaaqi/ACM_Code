#include<stdio.h>
#include<string.h>
void numswap(char a[],int len)
{
	int temp;
	for(int i=0; i<=len/2-1; i++)
	{
		temp=a[i];
		a[i]=a[len-i-1];
		a[len-i-1]=temp;
	}
}
int main()
{
	int z,N;
	scanf("%d",&N);
	for(z=0; z<N; z++)
	{
		char num1[1050]={0};
		char num2[1050]={0};
		char sum[1050]={0};
		scanf("%s%s",num1,num2);
		int len1=strlen(num1);
		int len2=strlen(num2);
		numswap(num1,len1);
		numswap(num2,len2);
		int i,j,up=0;
		int lenmax=len1>=len2 ? len1:len2;
		int lenmin=len1<=len2 ? len1:len2;
		for(i=0; i<lenmax; i++)
		{
			if(i<lenmin)
				{
					sum[i]=(num1[i]+num2[i]-48-48)%10+up;
					up=(num1[i]+num2[i]-48-48)/10;
				} 
			else
			{
				if(len1>len2)
				{
					sum[i]=(num1[i]-48)%10+up;
					up=(num1[i]-48)/10;
				}
				if(len2>len1)
				{
					sum[i]=(num2[i]-48)%10+up;
					up=(num2[i]-48)/10;
				}
			}
		}
		if(up)
		{
			sum[lenmax]=1;
			lenmax++;
		}
		numswap(num1,len1);
		numswap(num2,len2);
		printf("Case %d：\n",z+1);
		printf("%s+%s=",num1,num2);
		for(i=lenmax-1; i>=0; i--)
		{
			printf("%d",sum[i]);
		}
		printf("\n\n");
	}
	return 0;
} 