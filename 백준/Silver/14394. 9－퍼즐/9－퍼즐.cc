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

	string a, b;
	cin >> a >> b;

	string s = "RGBY";
	vector<int> v(s.size());

	int pos = 0;
	int neg = 0;
	for (int i = 0; i < s.size(); i++)
	{
		v[i] = count(a.begin(), a.end(), s[i]) - count(b.begin(), b.end(), s[i]);
		if (v[i] < 0) neg -= v[i];
		else pos += v[i];
	}

	cout << max(neg, pos);
	

	return 0;
}