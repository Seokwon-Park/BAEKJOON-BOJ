#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int b[1005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;
	int k;
	cin >> k;

	int ix = 0;
	while (ix <n && s[ix] == '0')ix++;
	if (ix == n)
	{
		cout << "YES";
		return 0;
	}
	else
	{
		s = s.substr(ix);
		n = s.size();
	}
	if (k >= n)
	{
		cout << "NO";
		return 0;
	}
	for (int i = 0; i < k; i++)
	{
		if (s[n-i-1] == '1')
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

	return 0;
}