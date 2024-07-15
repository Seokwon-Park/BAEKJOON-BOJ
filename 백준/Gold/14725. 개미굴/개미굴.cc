#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

const int root = 1;
int unused = 2;
const int MX = 1000 * 15 + 5; // 묹자열이 최대 1000개 * 15개 만큼 들어올 수 있음.
bool chk[MX]; // 이 노드가 어떤 문자열의 마지막인지
//int nxt[MX][26]; // 어떤 노드의 다음 노드가 있는지 여부 없으면 -1;

map<string, int> nxt[MX];

int c2i(char c)
{
	if (c >= 'a' && c <= 'z')
		return c - 'a';
	if (c >= 'A' && c <= 'Z')
		return c - 'A';
}

void insert(vector<string>& s)
{
	int cur = root;
	for (auto c : s)
	{
		if (nxt[cur].find(c) == nxt[cur].end())
		{
			nxt[cur][c] = unused++;
		}
		cur = nxt[cur][c];
	}
	chk[cur] = true;
}

void dfs(int node, int depth)
{
	for (auto [str, nxt] : nxt[node])
	{
		for (int i = 0; i < depth * 2; i++)
		{
			cout << '-';
		}
		cout << str << '\n';
		dfs(nxt, depth + 1);
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
		int k;
		cin >> k;
		vector<string> vs;
		for (int j = 0; j < k; j++)
		{
			string s;
			cin >> s;
			vs.push_back(s);
		}
		insert(vs);
	}

	dfs(1, 0);

	return 0;
}