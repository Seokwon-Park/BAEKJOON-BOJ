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

int v[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	string ans;

	int cur = 0;
	while (v[0] > 0)
	{
		while (cur < n && v[cur] >0)
		{
			v[cur]--;
			ans += 'R';
			cur++;
		}
		while (cur - 1 >= 0 && v[cur - 1] > v[cur])
		{
			cur--;
			ans += 'L';
			v[cur]--;
		}
	}

	cout << ans;

	return 0;
}