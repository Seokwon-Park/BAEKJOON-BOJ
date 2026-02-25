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

	vector<int> v(15);
	for (int& i : v)
	{
		cin >> i;
	}

	auto itr = max_element(v.begin(), v.end());
	if (itr == v.end() - 1)
	{
		cout << *itr;
	}
	else
	{
		cout << *itr + 1;
	}


	return 0;
}