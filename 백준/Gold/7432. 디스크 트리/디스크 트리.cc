#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int root = 1;
int unused = 2;
const int MX = 500 * 80;
bool chk[MX];
map<string, int> nxt[MX];

void insert(vector<string> s)
{
	int cur = root;
	for (string str : s)
	{
		if (nxt[cur].find(str) == nxt[cur].end())
		{
			nxt[cur][str] = unused++;
		}
		cur = nxt[cur][str];
	}
	chk[cur] = true;
}

void dfs(int node, int indent)
{
	for (auto [str, next] : nxt[node])
	{
		for (int i = 0; i < indent; i++)
		{
			cout << ' ';
		}
		cout << str << '\n';
		dfs(next, indent + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		istringstream iss(s);
		vector<string> v;
		string str;
		while (getline(iss, str,'\\'))
		{
			v.push_back(str);
		}
		insert(v);
	}

	dfs(1, 0);

	return 0;
}