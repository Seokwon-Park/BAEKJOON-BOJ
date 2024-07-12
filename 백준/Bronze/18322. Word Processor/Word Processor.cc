#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<string> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int cur = 0;
	for (int i = 0; i < n; i++)
	{
		if (cur + v[i].size() <= k)
		{
			if (cur != 0)
				cout << ' ';
			cout << v[i];
			cur += v[i].size();
		}
		else
		{
			cout << '\n';
			cout << v[i];
			cur = v[i].size();
		}
	}

	return 0;
}