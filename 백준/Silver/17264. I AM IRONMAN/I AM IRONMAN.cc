#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int ans = 0;
	int n, p;
	cin >> n >> p;
	int w, l, g;
	cin >> w >> l >> g;
	unordered_map<string, char> um;
	for (int i = 0; i < p; i++)
	{
		string name;
		char res;
		cin >> name >> res;
		um[name] = res;
	}

	bool isIronman = true;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (um.find(s) != um.end())
		{
			if (um[s] == 'W')
			{
				ans += w;
				if (ans >= g)
					isIronman = false;
			}
			else
			{
				ans = max(0, ans - l);
			}
		}
		else
		{
			ans = max(0, ans - l);
		}
	}

	cout << (isIronman ? "I AM IRONMAN!!" : "I AM NOT IRONMAN!!");

	return 0;
}

