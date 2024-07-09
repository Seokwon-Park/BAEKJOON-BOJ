#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

vector<int> fail(string s)
{
	vector<int> f(s.size(), 0);
	int j = 0;
	for (int i = 1; i < s.size(); i++)
	{
		while (j > 0 && s[i] != s[j]) j = f[j - 1];
		if (s[i] == s[j]) f[i] = ++j;
	}
	return f;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	string h, n;
	cin >> h >> n;

	vector<int> f = fail(n);

	int ans = 0;
	int j = 0;
	for (int i = 0; i < h.size(); i++)
	{
		while (j > 0 && h[i] != n[j]) j = f[j - 1];
		if (h[i] == n[j]) j++;
		if (j == n.size())
		{
			ans++;
			j = 0;
		}
	}
	cout << ans;

	return 0;
}