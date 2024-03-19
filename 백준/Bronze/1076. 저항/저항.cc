#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;
template <typename T>
using vec = vector<T>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	unordered_map<string, pair<int, ll>> um;

	um["black"] = make_pair(0, 1);
	um["brown"] = make_pair(1, 10);
	um["red"] = make_pair(2, 100);
	um["orange"] = make_pair(3, 1000);
	um["yellow"] = make_pair(4, 10000);
	um["green"] = make_pair(5, 100000);
	um["blue"] = make_pair(6, 1000000);
	um["violet"] = make_pair(7, 10000000);
	um["grey"] = make_pair(8, 100000000);
	um["white"] = make_pair(9, 1000000000);

	string a, b, c;
	cin >> a >> b >> c;
	ll res = 0;
	res += um[a].first*10;
	res += um[b].first;
	res *= um[c].second;

	cout << res;

	return 0;
}