#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string  s;
	cin >> n >> s;

	int so = 0;
	int tt = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 's')
		{
			so++;
		}
		else
		{
			tt++;
		}
	}

	int st = 0;
	while (st< n && so != tt)
	{
		if (s[st] == 's')
		{
			so--;
		}
		else
		{
			tt--;
		}
		st++;
	}

	cout << s.substr(st);

	return 0;
}