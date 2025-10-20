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

	int n;
	cin >> n;

	int w, h;
	cin >> w >> h;

	int l = w * w + h * h;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		cout << (x * x <= l ? "YES" : "NO") << '\n';
	}

	return 0;
}