#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	ll b, n, m;
	cin >> b >> n >> m;
	unordered_map<string, ll> um;
	for (int i = 0; i < n; i++)
	{
		string s;
		ll p;
		cin >> s >> p;
		um[s] = p;
	}

	ll res = 0;
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		res += um[s];
	}
	if (res <= b)
	{
		cout << "acceptable";
	}
	else
	{
		cout << "unacceptable";
	}

	return 0;
}