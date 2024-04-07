#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, l;
	cin >> n >> l;
	int t = 0;
	int cur = 0;
	for (int i = 0; i < n; i++)
	{
		int d, r, g;
		cin >> d >> r >> g;
		t += d - cur;
		cur = d;
		while (t % (r + g) < r)
			t++;
	}
	t += l - cur;
	cout << t;

	return 0;
}