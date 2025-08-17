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

int n, k;
bool isEat[15];
int ans = 0;

int a[15];
int b[15];
int c[15];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> c[i];
	}

	vector<int> order(n);
	for (int i = 0; i < n; i++)
	{
		order[i] = i;
	}

	int ans = -1;
	do
	{
		int res = 0;
		bool eatall = true;
		for (int i = 1; i < n; i++)
		{
			res += a[order[i - 1]] * b[order[i]];
			if (c[order[i - 1]] * c[order[i]] > k)
			{
				eatall = false;
				break;
			}
		}
		if (eatall)
		{
			ans = max(ans, res);
		}
	} while (next_permutation(order.begin(), order.end()));
	cout << ans;

	return 0;
}