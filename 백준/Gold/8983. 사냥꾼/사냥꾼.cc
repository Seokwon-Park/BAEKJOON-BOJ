#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n, l;
	cin >> m >> n >> l;
	vector<int> xv(m);
	for (int i = 0; i < m; i++)
	{
		cin >> xv[i];
	}
	sort(xv.begin(), xv.end());

	vector<pii> animal(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		animal[i] = { x,y };
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		auto [x, y] = animal[i];
		int lb = lower_bound(xv.begin(), xv.end(), x)-xv.begin();
		if (lb > 0 && abs(xv[lb-1] - x)+y <= l)
		{
			ans++;
		}
		else if (lb < m && abs(xv[lb] - x) + y <=l)
		{
			ans++;
		}
	}
	cout << ans;


	return 0;
}