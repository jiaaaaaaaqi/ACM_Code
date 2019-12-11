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
const int    maxn = 2e2 + 10;
const int    maxm = 1e5 + 10;
const ll     mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = acos(-1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

struct Node {
    double l, r, h;
    int f;
    Node () {}
    Node (double _l, double _r, double _h, int _f) {
        l = _l, r = _r, h = _h, f = _f;
    }
    bool operator < (Node a) const {
        return h<a.h;
    }
} node[maxn];
double a[maxn<<2];
int cnt[maxn<<2];
vector<double> vv;

int getid(double x) {
    return lower_bound(vv.begin(), vv.end(), x)-vv.begin()+1;
}

void pushup(int l, int r, int rt) {
	if(cnt[rt])	a[rt] = vv[r]-vv[l-1];
	else if(l == r)	a[rt] = 0;
	else	a[rt] = a[rt<<1] + a[rt<<1|1];
}

void update(int l, int r, int pl, int pr, int v, int rt) {
	if(pl<=l && r<=pr) {
		cnt[rt] += v;
		pushup(l, r, rt);
		return ;
	}
	int mid = l+r>>1;
	if(pl <= mid)	update(l, mid, pl, pr, v, rt<<1);
	if(pr > mid)	update(mid+1, r, pl, pr, v, rt<<1|1);
	pushup(l, r, rt);
}

int main() {
    cas = 1;
    while(scanf("%d", &m), m) {
		mes(a, 0);
        vv.clear();
        n = 0;
        double x1, x2, y1, y2;
        for(int i=1; i<=m; i++) {
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            node[++n] = Node(x1, x2, y1, 1);
            node[++n] = Node(x1, x2, y2, -1);
            vv.push_back(x1);
            vv.push_back(x2);
        }
        sort(node+1, node+1+n);
        sort(vv.begin(), vv.end());
        vv.erase(unique(vv.begin(), vv.end()), vv.end());
        int mx = vv.size();
        double ans = 0.0;
        for(int i=1; i<n; i++) {
            double l = getid(node[i].l), r = getid(node[i].r);
            double d = node[i+1].h - node[i].h;
            update(1, mx, l, r-1, node[i].f, 1);
            ans += a[1]*d;
        }
        printf("Test case #%d\n", cas++);
        printf("Total explored area: %0.2f\n\n", ans);
    }
    return 0;
}
