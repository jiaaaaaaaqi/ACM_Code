#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>

using namespace std;

int main() {
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--) {
		long long int n;
		scanf("%lld", &n);
		long long int k = sqrt(n);
		long long int ans = 0;
		for(int i=1; i<=k; i++) {
			ans += n/i;
			ans += (n/i-n/(i+1)) * i;
		}
		if(k*k == n)
			ans -= k;
		printf("Case %d: %lld\n", cas++, ans);
	}
	return 0;
}