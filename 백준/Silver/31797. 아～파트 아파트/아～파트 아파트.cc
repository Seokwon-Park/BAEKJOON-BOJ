#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	map<int, int> hand;
	for (int i = 1; i <= m; i++)
	{
		int l, r;
		cin >> l >> r;
		hand[l] = i;
		hand[r] = i;
	}

	vector<int> v;
	for (auto [height, player] : hand)
	{
		v.push_back(player);
	}


	cout << v[(n-1) % (m * 2)];

	return 0;
}