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

	vector<int> x(5), y(5);
	for (int& i : x)cin >> i;
	for (int& i : y)cin >> i;

	for (int i = 0; i < 5; i++)
	{
		if (x[i] == y[i])
		{
			cout << "N";
			return 0;
		}
	}
	cout << "Y";

	return 0;
}