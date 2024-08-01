#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, t;
	cin >> n >> t;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int s, l, c;
		cin >> s >> l >> c;
		for (int j = 0; j < c; j++)
		{
			v.push_back(s + l * j);
		}
	}
	sort(v.begin(), v.end());

	int lb = lower_bound(v.begin(), v.end(), t)- v.begin();
	if (lb >= v.size())
	{
		cout << -1;
	}
	else
	{
		cout << v[lb] - t;
	}
	

	return 0;
}