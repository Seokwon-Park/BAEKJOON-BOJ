#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int v[725];
int res[725];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		int dir = a + 180;
		int st = dir - b;
		int en = dir + b;

		v[st] += 1;
		v[en + 1] += -1;
	}

	res[0] = v[0];
	for (int i = 1; i < 725; i++)
	{
		res[i] = res[i - 1] + v[i];
	}

	for (int i = 360; i < 725; i++)
	{
		if (res[i] > 0)
		{
			res[i % 360] = 1;
		}
	}

	cout << count_if(res, res + 360, [](const auto& a) {return a > 0; });



	return 0;
}