/*
          .
         ';;;;;.
        '!;;;;;;!;`
       '!;|&#@|;;;;!:
      `;;!&####@|;;;;!:
     .;;;!&@$$%|!;;;;;;!'.`:::::'.
     '!;;;;;;;;!$@###&|;;|%!;!$|;;;;|&&;.
     :!;;;;!$@&%|;;;;;;;;;|!::!!:::;!$%;!$%`    '!%&#########@$!:.
     ;!;;!!;;;;;|$$&@##$;;;::'''''::;;;;|&|%@$|;;;;;;;;;;;;;;;;!$;
     ;|;;;;;;;;;;;;;;;;;;!%@#####&!:::;!;;;;;;;;;;!&####@%!;;;;$%`
    `!!;;;;;;;;;;!|%%|!!;::;;|@##%|$|;;;;;;;;;;;;!|%$#####%;;;%&;
    :@###&!:;;!!||%%%%%|!;;;;;||;;;;||!$&&@@%;;;;;;;|$$##$;;;%@|
    ;|::;;;;;;;;;;;;|&&$|;;!$@&$!;;;;!;;;;;;;;;;;;;;;;!%|;;;%@%.
   `!!;;;;;;;!!!!;;;;;$@@@&&&&&@$!;!%|;;;;!||!;;;;;!|%%%!;;%@|.
%&&$!;;;;;!;;;;;;;;;;;|$&&&&&&&&&@@%!%%;!||!;;;;;;;;;;;;;$##!
!%;;;;;;!%!:;;;;;;;;;;!$&&&&&&&&&&@##&%|||;;;!!||!;;;;;;;$&:
':|@###%;:;;;;;;;;;;;;!%$&&&&&&@@$!;;;;;;;!!!;;;;;%&!;;|&%.
 !@|;;;;;;;;;;;;;;;;;;|%|$&&$%&&|;;;;;;;;;;;;!;;;;;!&@@&'
  .:%#&!;;;;;;;;;;;;;;!%|$$%%&@%;;;;;;;;;;;;;;;;;;;!&@:
  .%$;;;;;;;;;;;;;;;;;;|$$$$@&|;;;;;;;;;;;;;;;;;;;;%@%.
    !&!;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;|@#;
     `%$!;;;;;;;;;;;$@|;;;;;;;;;;;;;;;;;;;;;;;;!%$@#@|.
       .|@%!;;;;;;;;;!$&%||;;;;;;;;;;;;;;;;;!%$$$$$@#|.
           ;&$!;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;%#####|.
           |##$|!;;;;;;::'':;;;;;;;;;;;;;!%$$$@#@;
          ;@&|;;;;;;;::'''''':;;;;;;;|$&@###@|`
        .%##@|;;;;:::''''''''''::;!%&##$'
      `$##@$$@@&|!!;;;:'''''::::;;;;;|&#%.
    ;&@##&$%!;;;;;;::''''''''::;!|%$@#@&@@:
     .%@&$$|;;;;;;;;;;:'''':''''::;;;%@#@@#%.
    :@##@###@$$$$$|;;:'''':;;!!;;;;;;!$#@@#$;`
     `%@$$|;;;;;;;;:'''''''::;;;;|%$$|!!&###&'
     |##&%!;;;;;::''''''''''''::;;;;;;;!$@&:`!'
    :;!@$|;;;;;;;::''''''''''':;;;;;;;;!%&@$:                 !@#$'
      |##@@&%;;;;;::''''''''':;;;;;;;!%&@#@$%:              '%%!%&;
      |&%!;;;;;;;%$!:''''''':|%!;;;;;;;;|&@%||`            '%$|!%&;
      |@%!;;!!;;;||;:'''''':;%$!;;;;!%%%&#&%$&:           .|%;:!&%`
      !@&%;;;;;;;||;;;:''::;;%$!;;;;;;;|&@%;!$;          `%&%!!$&:
      '$$|;!!!!;;||;;;;;;;;;;%%;;;;;;;|@@|!$##;         !$!;:!$&:
       |#&|;;;;;;!||;;;;;;;;!%|;;;;!$##$;;;;|%'      `%$|%%;|&$'
        |&%!;;;;;;|%;;;;;;;;$$;;;;;;|&&|!|%&&;  .:%&$!;;;:!$@!
        `%#&%!!;;;;||;;;;;!$&|;;;!%%%@&!;;;!!;;;|%!;;%@$!%@!
        !&!;;;;;;;;;||;;%&!;;;;;;;;;%@&!;;!&$;;;|&%;;;%@%`
       '%|;;;;;;;;!!|$|%&%;;;;;;;;;;|&#&|!!||!!|%$@@|'
       .!%%&%'`|$;       :|$#%|@#&;%#%.
*/
#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <cfloat>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  pii        pair<int, int>
#define  INOPEN     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e3 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn];
int dp[1<<11][11];

int calc(int p, int state) {
	if(n-p <= 10)	return state>>1;
	else	return (state>>1) | (1<<9);
}

int dfs(int p, int state) {
	if(p == n+1) {
		return state == 0;
	}
	if(dp[state][p] != -1)	return dp[state][p];
	dp[state][p] = 0;
	if(state&1) {
		for(int i=1, j=0; i<=9&&j<5; i++) {
			if(state & (1<<(i))) {
				j++;
				if(a[i+p] == a[p]) {
					int nst = state & (~1) & (~(1<<i));
					if(dfs(p+1, calc(p, nst))) {
						dp[state][p] = 1;
						return 1;
					}
				}
			}
		}
	} else {
		dp[state][p] = dfs(p+1, calc(p, state));
	}
	return dp[state][p];
}

int main() {
	while(~scanf("%d", &n)) {
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[n-i+1]);
		}
		if(n&1) {
			printf("0\n");
			continue;
		}
		mes(dp, -1);
		int state = (1<<(min(10, n)))-1;
		if(dfs(1, state))	cout << "1" << endl;
		else	cout << "0" << endl;
	}
	return 0;
}
