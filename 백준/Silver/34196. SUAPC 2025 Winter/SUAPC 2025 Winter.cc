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
using hashmap = unordered_map<key, value>;

vector<vector<pair<bool, int>>> v =
{
{{1,0},{1,0},{1,0},{1,2},{0,1},{1,0},{1,2},{1,0},{1,0},{1,3},{1,2},{1,1},{1,0}},
{{1,0},{1,1},{1,0},{1,0},{0,8},{1,0},{1,4},{1,3},{1,2},{1,0},{1,2},{1,3},{1,3}},
{{1,0},{1,0},{1,0},{1,1},{0,1},{1,0},{0,2},{1,3},{1,0},{1,0},{1,1},{1,1},{1,0}},
{{1,0},{1,0},{1,0},{1,3},{0,0},{1,0},{0,0},{1,0},{1,1},{1,0},{1,1},{1,1},{1,0}},
{{1,0},{1,1},{1,1},{1,0},{0,0},{1,0},{0,0},{1,6},{1,4},{1,0},{1,1},{1,0},{1,1}},
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;

	while (q--)
	{
		int r;
		char c;
		cin >> r >> c;
		int rr = r - 1;
		int cc = c - 'A';

		auto [cor, wrong] = v[rr][cc];
		cout << (cor ? "Yes" : "No") << ' ' << wrong << '\n';
		

	}

	return 0;
}