#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int v[26];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;
	for (auto c : s)
	{
		v[c - 'a']++;
	}

	string pat = "uospc";

	int ans = INF;
	for (int i = 0; i < 5; i++)
	{
		ans = min(v[pat[i]-'a'], ans);
	}
	cout << ans;
	

	return 0;
}