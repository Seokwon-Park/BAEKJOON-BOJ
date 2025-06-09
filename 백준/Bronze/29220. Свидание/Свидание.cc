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

	int k;
	cin >> k;
	int n;
	cin >> n;
	int total = 0;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		total += v[i];
	}

	bool isYes = false;
	for (int i = 0; i < n; i++)
	{
		if (total - v[i] >= k)
		{
			isYes = true;
			break;
		}
	}
	
	cout << (isYes ? "YES" : "NO");

	return 0;
}