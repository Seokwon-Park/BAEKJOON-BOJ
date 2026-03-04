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

int v[5];
int cur;
int x, y;
bool buy;

void func(int k)
{
	if (k == 5)
	{
		if (cur >= x && cur <= y)
			buy = true;
		return;
	}
	func(k + 1);
	cur += v[k];
	func(k + 1);
	cur -= v[k];

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		buy = 0;
		cur = 0;
		cin >> x >> y;
		for (int i = 0; i < 5; i++)
		{
			cin >> v[i];
		}
		func(0);
		cout << (buy ? "YES" : "NO") << '\n';
	}
	return 0;
}