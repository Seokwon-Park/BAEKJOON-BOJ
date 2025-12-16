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

int popcount(unsigned int n)
{
	n = (n >> 1 & 0x5555) + (n & 0x5555);
	n = (n >> 2 & 0x3333) + (n & 0x3333);
	n = (n >> 4 & 0x0F0F) + (n & 0x0F0F);
	n = (n >> 8 & 0x00FF) + (n & 0x00FF);
	return n;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int x, chk;
		cin >> x >> chk;
		int cmp = (popcount(x) % 2 == 1);
		cout << (chk == cmp ? "Valid" : "Corrupt") << '\n';
	}



	return 0;
}
