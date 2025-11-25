#include <bits/stdc++.h>

using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int inorder[100005];
int postorder[100005];
int position[100005];

int root = -1;
int l[100005];
int r[100005];

int solve(int inst, int inen, int post, int poen)
{
	if (inst > inen || post > poen) return -1;

	int sroot = postorder[poen];

	int rootpos = position[sroot];
	int lsize = rootpos - inst;

	l[sroot] = solve(inst, rootpos - 1, post, post + lsize - 1);
	r[sroot] = solve(rootpos + 1, inen, post + lsize, poen - 1);

	return sroot;
}

void preorder(int node)
{
	cout << node << ' ';
	if (l[node] != -1) preorder(l[node]);
	if (r[node] != -1) preorder(r[node]);

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> inorder[i];

		position[inorder[i]] = i;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> postorder[i];
	}

	solve(0, n - 1, 0, n - 1);

	preorder(postorder[n - 1]);
	
	
	return 0;
}
