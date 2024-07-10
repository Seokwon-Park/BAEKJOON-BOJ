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

	if (k == n)
	{
		cout << "Impossible";
		return 0;
	}
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		v[i] = i + 1;
	}

	int tmp = v[n - k-1];
	for (int i = n-k-1; i >0 ; i--)
	{
		v[i] = v[(i +n - k-1) % (n - k)];
	}
	v[0] = tmp;

	for (auto i : v)
		cout << i << ' ';

	return 0;
}