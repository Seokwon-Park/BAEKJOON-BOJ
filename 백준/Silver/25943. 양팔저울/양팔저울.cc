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
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int l = v[0];
	int r = v[1];
	for (int i = 2; i < n; i++)
	{
		if (l == r)
			l += v[i];
		else if (l < r)
			l += v[i];
		else
			r += v[i];
	}

	int gap = 0;
	if (l != r)
		gap = abs(l - r);

	vector<int> choo = { 100, 50, 20 ,10 ,5, 2, 1 };
	int ans = 0;
	for (int i = 0; i < choo.size(); i++)
	{
		int tmp = gap / choo[i];
		ans += tmp;
		gap -= tmp * choo[i];
	}
	cout << ans;


	return 0;
}