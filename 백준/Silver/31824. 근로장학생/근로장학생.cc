#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	unordered_map<string, string> um;
	for (int i = 0; i < n; i++)
	{
		string a, b;
		cin >> a >> b;
		um[a] = b;
	}

	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		string res;
		for (int j = 0; j < s.size(); j++)
		{
			for (int k = 1; k <= s.size() - j; k++)
			{
				auto tmp = s.substr(j, k);
				if (um.find(tmp) != um.end())
				{
					res += um[tmp];
				}
			}
		}
		cout << (res.empty()? "-1" : res) << '\n';
	}

	return 0;
}
