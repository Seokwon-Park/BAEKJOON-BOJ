#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int times[55];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, l;
	cin >> n >> m >> l;

	int mx = 1;
	int cur = 0;
	int thr = 0;
	times[0] = 1;
	while (mx < m)
	{
		if (times[cur] % l)
			cur = (cur + l) % n;
		else
			cur = (n + cur - l) % n;
		times[cur]++;
		mx = max(mx, times[cur]);
		thr++;
	}
	cout << thr;

	return 0;
}