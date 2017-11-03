//-線段樹區間最大值
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<string>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<vector>
#include<unordered_map>
using namespace std;



#define scanf scanf_s	
#define LL long long

struct Node{
	Node *lc, *rc;
	int val, tag;
	Node(){
		lc = rc = NULL;
		val = -1; tag = 0;
	}
	void pull(){
		val = max(lc->val, rc->val);
		tag = (lc->tag&rc->tag);
	}
};
Node* root;
Node* build(int l, int r){
	Node* node = new Node();
	if (l == r){
		if (l != 1)node->val = 1000;
		else node->val = 1;
		return node;
	}
	int m = (l + r) / 2;
	node->lc = build(l, m);
	node->rc = build(m+1, r);
	node->pull();
	return node;
}
void update(Node* node, int l, int r, int pos, int val){
	if (l == r){
		node->val = val;
		node->tag = 1;
		return;
	}
	int m = (l + r) / 2;
	if (node->lc->tag == 0 && m >= pos)update(node->lc, l, m, pos, val);
	if (node->rc->tag == 0 && m < pos)update(node->rc, m+1, r, pos, val);
	node->pull();
}
int query(Node* node, int L, int R, int l, int r){
	if (R<l || L>r)return -1;
	else if (l <= L&&R <= r)return node->val;
	int m = (L + R) >> 1;
	return max(query(node->lc, L, m, l, r), query(node->rc, m + 1, R, l, r));
}
LL p[3000010] = {};
//20000002
int find(LL n){
	if (n < 3000010 && p[n])
		return p[n];
	if (n > 1000000){
		if ((n & 1))return find(n * 3 + 1) + 1;
		return find(n / 2) + 1;
	}
	if (n == 1)return p[n] = 1;
	if ((n & 1) == 0){
		p[n] = find(n / 2) + 1;
		update(root, 1, 1000000, n, p[n]);
		return p[n];
	}
	p[n] = 1 + find(n * 3 + 1);
	update(root, 1, 1000000, n, p[n]);
	return p[n];
}

int main(){
	root = build(1, 1000000);
	int a, b;
	while (scanf("%d%d", &a, &b) == 2){
		int aa = min(a, b), bb = max(a, b);
		if (query(root, 1, 1000000, aa, bb) == 1000)
			for (int x = aa; x <= bb; x++)
				if (p[x] == 0)find(x);
		printf("%d %d %lld\n", a, b, query(root, 1, 1000000, aa, bb));
	}
}
