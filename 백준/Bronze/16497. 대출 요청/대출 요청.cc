#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int counter[32];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int st, en;
		cin >> st >> en;
		for (int j = st; j < en; j++)
		{
			counter[j]++;
		}

	}
	int k;
	cin >> k;
	int res = count_if(counter + 1, counter + 32, [&](int a) { return a > k; });
	if (res > 0)
		cout << 0;
	else
		cout << 1;

	return 0;
}
