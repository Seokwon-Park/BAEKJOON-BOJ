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

	int n;
	cin >> n;
	vector<int>v(n);
	vector<int> price(n);
	for (int& i : v)
		cin >> i;
	for (int& i : price)
		cin >> i;

	int ix = max_element(v.begin(), v.end()) - v.begin();
	int second = 0;
	for(int i = 0; i< n;i++)
	{
		if (i == ix) continue;
		second = max(second, v[i]);
	}
	
	vector<int> chance(n);
	for (int i = 0; i < n; i++)
	{
		if (ix == i)
		{
			chance[i] = second - price[i];
		}
		else
		{
			chance[i] = v[ix] - price[i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << v[i] - chance[i] - price[i] << ' ';
	}

	return 0;
}