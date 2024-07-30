#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int price[10005];
pair<string, int> my_list[100005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int u, n;
	cin >> u >> n;
	fill(price, price + 10005, INF);
	for (int i = 0; i < n; i++)
	{
		string s;
		int n;
		cin >> s >> n;
		my_list[i] = { s,n };
		if (price[n] == INF)
		{
			price[n] = 1;
		}
		else
		{
			price[n]++;
		}
	}

	int* mn = min_element(price, price + 10005);

	int pr = mn - price;
	for (int i = 0; i < n; i++)
	{
		if (my_list[i].second == pr)
		{
			cout << my_list[i].first << ' ' << my_list[i].second;
			return 0;
		}
	}

	return 0;
}