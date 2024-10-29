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

	int n, k, a, b;
	cin >> n >> k >> a >> b;
	vector<int> v(n);

	fill(v.begin(), v.end(), k);

	int d = 1;
	
	int st = 0;
	while (1)
	{
		for (int i = 0; i < a; i++)
		{
			v[(st + i)%n] += b;
		}

		for (int i = 0; i < n; i++)
		{
			v[i]--;
		}
		st = (st+a)%n;
		if (v[st] <= 0)
		{
			cout << d;
			break;
		}
		d++;
	}

	return 0;
}