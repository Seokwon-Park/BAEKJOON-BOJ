#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

unordered_map<char, vector<pii>> um;
map<char, int> p;
string s;

bool check()
{
	for (auto [c, cnt] : p)
	{
		if (cnt > um[c].size())
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			char c;
			cin >> c;
			um[c].push_back({ x,y });
		}
	}

	cin >> s;
	int x = 0;
	int y = 0;
	string res; 
	int prize = 0;
	for (auto c : s)
	{
		p[c]++;
	}

	while (check())
	{
		prize++;
		for (int i = 0; i < s.size(); i++)
		{
			auto [tx, ty] = um[s[i]].back();
			um[s[i]].pop_back();
			int dx = tx - x;
			int dy = ty - y;
			for (int i = 0; i < abs(dx); i++)
			{
				res += (dx > 0) ? 'R' : 'L';
			}
			for (int i = 0; i < abs(dy); i++)
			{
				res += (dy > 0) ? 'D' : 'U';
			}
			res += 'P';
			x = tx;
			y = ty;
		}
	}
	int dx = m - x - 1;
	int dy = n - y - 1;
	for (int i = 0; i < abs(dx); i++)
	{
		res += (dx > 0) ? 'R' : 'L';
	}
	for (int i = 0; i < abs(dy); i++)
	{
		res += (dy > 0) ? 'D' : 'U';
	}

	cout << prize << ' ' << res.size() << '\n';
	cout << res;
}