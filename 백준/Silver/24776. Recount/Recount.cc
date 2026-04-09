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

	Hash<string, int> v;
	string s;
	int mx = 0;
	while (getline(cin, s))
	{
		if (s == "***") break;
		v[s]++;
		mx = max(v[s], mx);
	}

	int find = 0;
	string name;
	for (auto [a, b] : v)
	{
		if (b == mx)
		{
			if (find == 0)
			{
				name = a;
			}
			find++;
		}
	}
	if (find > 1)
	{
		cout << "Runoff!";
	}
	else
	{
		cout << name;
	}



	return 0;
}