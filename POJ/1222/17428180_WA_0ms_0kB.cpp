/*
		  .
		 ';;;;;.
		'!;;;;;;!;`
	   '!;|&#@|;;;;!:
	  `;;!&####@|;;;;!:
	 .;;;!&@$$%|!;;;;;;!'.`:::::'.
	 '!;;;;;;;;!$@###&|;;|%!;!$|;;;;|&&;.
	 :!;;;;!$@&%|;;;;;;;;;|!::!!:::;!$%;!$%`	'!%&#########@$!:.
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
	:;!@$|;;;;;;;::''''''''''':;;;;;;;;!%&@$:				 !@#$'
	  |##@@&%;;;;;::''''''''':;;;;;;;!%&@#@$%:			  '%%!%&;
	  |&%!;;;;;;;%$!:''''''':|%!;;;;;;;;|&@%||`			'%$|!%&;
	  |@%!;;!!;;;||;:'''''':;%$!;;;;!%%%&#&%$&:		   .|%;:!&%`
	  !@&%;;;;;;;||;;;:''::;;%$!;;;;;;;|&@%;!$;		  `%&%!!$&:
	  '$$|;!!!!;;||;;;;;;;;;;%%;;;;;;;|@@|!$##;		 !$!;:!$&:
	   |#&|;;;;;;!||;;;;;;;;!%|;;;;!$##$;;;;|%'	  `%$|%%;|&$'
		|&%!;;;;;;|%;;;;;;;;$$;;;;;;|&&|!|%&&;  .:%&$!;;;:!$@!
		`%#&%!!;;;;||;;;;;!$&|;;;!%%%@&!;;;!!;;;|%!;;%@$!%@!
		!&!;;;;;;;;;||;;%&!;;;;;;;;;%@&!;;!&$;;;|&%;;;%@%`
	   '%|;;;;;;;;!!|$|%&%;;;;;;;;;;|&#&|!!||!!|%$@@|'
	   .!%%&%'`|$;	   :|$#%|@#&;%#%.
*/
#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
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
const int    maxn = 1e2 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int a[maxn][maxn];
int x[maxn];
int dis[5][2] = {-1, 0, 1, 0, 0, 1, 0, -1, 0, 0};

bool check(int x, int y) {
    if(x < 0 || y < 0)		return 0;
    if(x >= 5 || y >= 6)	return 0;
    return 1;
}

void build() {
    for(int i=0; i<5; i++) {
        for(int j=0; j<6; j++) {
            for(int k=0; k<5; k++) {
                int x = i + dis[k][0];
                int y = j + dis[k][1];
                if(check(x, y)) {
                    a[i*6+j][x*6+y] = 1;
                }
            }
        }
    }
}

int gauss(int equ, int var) {	//equ个方程，var个变量
    int i, j, k, col, max_r;
    for(k=0, col=0; k<equ && col<var; k++, col++) {
        max_r = k;
        for(i=k+1; i<equ; i++) {
            if(abs(a[i][col]) > abs(a[max_r][col])) {
                max_r = i;
            }
        }
        if(a[max_r][col] == 0)	return 0;	//无解
        if(k != max_r) {
            swap(a[k], a[max_r]);
            swap(x[k], x[max_r]);
        }
        for(i=k+1; i<equ; i++) {
			if(a[i][col]) {
				for(int j=col; j<=var; j++) {
					a[i][j] ^= a[k][j];
				}
			}
        }
    }
	for(int i=var-1; i>=0; i--) {
		for(int j=i+1; j<var; j++) {
			x[i] ^= (a[i][j] && x[j]);
		}
	}
}

int main() {
    cas = 1;
    scanf("%d", &T);
    while(T--) {
        n = 30;
        mes(a, 0);
        for(int i=0; i<n; i++)
            scanf("%d", &x[i]);
        build();
        gauss(n, n);
        printf("PUZZLE #%d\n", cas++);
        for(int i=0; i<n; i++) {
            printf("%d", x[i]);
            if((i+1)%6 == 0)
                printf("\n");
            else
                printf(" ");
        }
    }
    return 0;
}
