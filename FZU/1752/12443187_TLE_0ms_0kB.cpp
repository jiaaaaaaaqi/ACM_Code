#include<stdio.h>
unsigned long long int c;
unsigned long long fast_mul(unsigned long long int a,unsigned long long int b)
{
	unsigned long long int ans=0;
	while(b)
	{
		if(b&1)
		{
			ans=ans+a;
			while(ans>=c)
				ans-=c;
		}
		a=a+a;
		while(a>=c)
			a-=c;
		b=b>>1;
	}
	return ans;
}
int main()
{
	unsigned long long int a,b;
	while(scanf("%lld%lld%lld",&a,&b,&c)!=EOF)
	{
		unsigned long long int ans=1;
		while(b)
		{
			if(b&1)
				ans=fast_mul(ans, a);
			a=fast_mul(a, a);
			b=b>>1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
