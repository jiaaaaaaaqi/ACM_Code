#include<map>
#include<queue>
#include<string>
#include<vector>
#include<math.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define inf 0x3f3f3f3f

typedef long long int ll;
using namespace std;

const int maxn = 1000005;

int tol;
int  vis[maxn];
char str2[3005];
char str[maxn][15];
int node[maxn][30];

void init() {
	tol = 1;
	memset(str, 0, sizeof(str));
	memset(vis, 0, sizeof(vis));
	memset(node[0], 0, sizeof(node[0]));
}

void build(char *str, int pos) {
	int len = strlen(str);
	int root = 0;
	int k;
	for(int i=0; i<len; i++) {
		k = str[i] - 'a';
		if(node[root][k] == 0) {
			memset(node[tol], 0, sizeof(node[tol]));
			node[root][k] = tol++;
		}
		root = node[root][k];
	}
	vis[root] = pos;
//	printf("vis[%d] = %d\n", root, pos);
	return ;
}

int query(char *str) {
	int len = strlen(str);
	int root = 0;
	int k;
	for(int i=0; i<len; i++) {
		k = str[i] - 'a';
		if(node[root][k] == 0)
			return 0;
		root = node[root][k];
	}
	return vis[root];
}

int main() {
	init();
	scanf("%s", str2);
	int num = 1;
	while(1) {
		scanf("%s", str[num]);
		if(strcmp(str[num], "END") == 0)
			break;
		memset(str2, 0, sizeof(str2));
		scanf("%s", str2);
		build(str2, num);
		num++;
	}
	scanf("%s", str2);
	getchar();
	while(1) {
		int j = 0;
		memset(str2, 0, sizeof(str2));
		char tmp[3005] = {0};
		gets(str2);
		if(strcmp(str2, "END") == 0)
			break;
		int len = strlen(str2);
		for(int i=0; i<len; i++) {
			if(islower(str2[i])) {
				tmp[j++] = str2[i];
			} else {
				tmp[j] = '\0';
				if(tmp[0] != '\0') {
					int pos = query(tmp);
					if(pos == 0)
						printf("%s", tmp);
					else
						printf("%s", str[pos]);
					j = 0;
					memset(tmp, 0, sizeof(tmp));
				}
				printf("%c", str2[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
