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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	while (cin >> a >> b)
	{
		vector<bool> mods(b);
		int cur = 0;
		while (!mods[cur])
		{
			mods[cur] = 1;
			cur = (cur + a) % b;
		}
		cout << setw(10) << a << setw(10) << b << ' ' << (mods[1] ? "Good Choice" : "Bad Choice") << "\n\n";
	}


	return 0;
}