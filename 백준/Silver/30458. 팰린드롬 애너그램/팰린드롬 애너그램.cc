
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



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> v(26, 0);
	for (int i = 0; i < s.size() / 2; i++)
	{
		v[s[i] - 'a']++;
		v[s[s.size() - i - 1] - 'a']++;
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] % 2)
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	


	return 0;
}
