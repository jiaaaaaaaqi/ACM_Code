#include<stdio.h>
unsigned long long fast_mul(unsigned long long int a,unsigned long long int b,unsigned long long int c)
{
	unsigned long long int ans=0;
	a=a%c;
	b=b%c;
	while(b)
	{
		if(b&1)
		{
			ans+=a;
			while(ans>=c)
				ans-=c;
		}
		a=a+a;
		while(a>=c)
			a-=c;
		b>>=1;
	}
	return ans;
}
int main()
{
	unsigned long long int a,b,c;
	while(scanf("%I64u%I64u%I64u",&a,&b,&c)!=EOF)
	{
		unsigned long long int ans=1;
		a=a%c;
		while(b)
		{
			if(b&1)
				ans=fast_mul(ans, a, c);
			a=fast_mul(a, a, c);
			b>>=1;
		}
		printf("%I64u\n",ans);
	}
	return 0;
}