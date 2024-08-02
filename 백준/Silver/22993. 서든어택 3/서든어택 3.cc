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

	ll myA;
	cin >> myA;
	vector<ll> a(n - 1);
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < n - 1; i++)
	{
		if (myA > a[i])
		{
			myA += a[i];
		}
		else
		{
			cout << "No";
			return 0;
		}
	}

	cout << "Yes";
	return 0;
}