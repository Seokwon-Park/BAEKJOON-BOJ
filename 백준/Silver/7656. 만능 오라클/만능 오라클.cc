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

	string s;
	getline(cin, s);

	vector<string> v;
	string tmp;
	for (int i = 0; i< s.size(); i++)
	{
		tmp += s[i];
		if (s[i] == '.')
		{
			tmp = "";
		}
		if (s[i] == '?')
		{
			tmp = tmp.substr(tmp.find("What"));
			tmp.replace(0, 4, "Forty-two");
			tmp[tmp.size() - 1] = '.';
			v.push_back(tmp);
			tmp = "";
		}
	}

	for (auto s : v)
	{
		cout << s << '\n';
	}

	return 0;
}