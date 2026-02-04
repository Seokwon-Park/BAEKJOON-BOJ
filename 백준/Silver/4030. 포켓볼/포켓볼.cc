#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

int b[25][25];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	int cs = 1;
	vector<int> sq;
	for (int i = 1; i*i < 1e9; i++)
	{
		sq.push_back(i * i);
	}

	vector<int> sum;
	int cur = 0;
	for (int i = 1; i+cur < 1e9; i++)
	{
		cur += i;
		sum.push_back(cur);
	}

	while (cin >> a >> b)
	{
		if (a == 0 && b == 0) break;
		int ans = 0;
		for (int i = 0; i < sq.size(); i++)
		{
			if (a >= sq[i] || b <= sq[i]) continue;
			ans += binary_search(sum.begin(), sum.end(), sq[i] - 1);
		}
		cout << "Case " << cs << ": " << ans << '\n';
		cs++;
	}


	return 0;
}