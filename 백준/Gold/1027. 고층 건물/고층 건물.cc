#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int cnt[55];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<double> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		double prev = -1e9;
		for (int j = i + 1; j < n; j++)
		{
			double a = (v[i] - v[j]) / (i - j);
			if (a > prev)
			{
				cnt[i]++;
				cnt[j]++;
				prev = a;
			}
		}
	}
	cout << *max_element(cnt, cnt+n) << '\n';

	return 0;
}