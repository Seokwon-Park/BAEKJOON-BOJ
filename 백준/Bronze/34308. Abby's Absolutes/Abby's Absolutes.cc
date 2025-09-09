#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int x;
		cin >> x;
		int a = n - x;
		int b = x - 1;
		if (a < b)
		{
			cout << n;
		}
		else
		{
			cout << 1;
		}
		cout << ' ';
	}
	return 0;
}