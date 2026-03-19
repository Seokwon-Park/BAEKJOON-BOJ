#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

vector<int> adj[2005];
int p[2005];
int depth[2005];
int unused = 1;
vector<int> apple;
int in[2005];
int out[2005];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;
	int a, b;
	cin >> a >> b;
	a--;
	b--;


	//0을 더미 노드로 두자.
	int cur = 0;
	for (int i = 0; i < s.size(); i++)
	{
		bool nxt = s[i] - '0';
		if (!nxt)
		{
			if (i == a || i == b)
			{
				apple.push_back(unused);
			}

			adj[cur].push_back(unused);
			depth[unused] = depth[cur] + 1;
			in[unused] = i;
			p[unused] = cur;
			cur = unused++;
		}
		else
		{
			if (i == a || i == b)
			{
				apple.push_back(cur);
			}
			out[cur] = i;
			cur = p[cur];
		}
	}
	
	int x = apple[0];
	int y = apple[1];
	int cut = 0;
	if (x == y)
	{
		cout << in[x] + 1 << ' ' << out[x] + 1;
	}
	else
	{
		while (x != y)
		{
			if (depth[x] < depth[y])
			{
				y = p[y];
			}
			else if(depth[x] > depth[y])
			{
				x = p[x];
			}
			else
			{
				x = p[x];
				y = p[y];
			}
		}
		cout << in[x] + 1 << ' ' << out[x] + 1;
	}


	return 0;
}