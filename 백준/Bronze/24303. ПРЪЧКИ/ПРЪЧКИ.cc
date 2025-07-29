#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;
template <typename key, typename value>
using hashm = unordered_map<key, value>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> a(3), b(3);
	for (int i = 0; i < 3; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < 3; i++)
	{
		cin >> b[i];
	}
	int l;
	cin >> l;

	int mn = INF;

	for (int i = 0; i <= b[0]; i++)
	{
		for (int j = 0; j <= b[1]; j++)
		{
			for (int k = 0; k <= b[2]; k++)
			{
				if (i * a[0] + j * a[1] + k * a[2] >= l)
				{
					mn = min(mn, i + j + k);
				}
			}
		}
	}
	cout << (mn == INF ? 0 : mn);
	


	return 0;
}