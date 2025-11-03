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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int p;
	cin >> p;
	int k = 0;
	vector<int> v(1000001);
	for (int i = 1; i <= 1000000; i++)
	{
		k += i * i;
		v[i] = k;
	}

	while (p--)
	{
		int i;
		cin >> i;
		cout << v[i] << '\n';
	}

	return 0;
}