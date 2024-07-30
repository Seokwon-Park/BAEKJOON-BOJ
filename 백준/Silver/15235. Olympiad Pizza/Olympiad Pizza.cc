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

	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> ft(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int t = 0;
	int cur = 0;
	while (1)
	{
		if (v[cur] == 0)
		{
			cur = (cur + 1) % n;
			continue;
		}
		t++;
		v[cur]--;
		if (v[cur] == 0)
		{
			ft[cur] = t;
		}
		cur = (cur + 1) % n;
		if (count(v.begin(), v.end(), 0) == n)
			break;
	}
	for (auto i : ft)
		cout << i << ' ';

	return 0;
}