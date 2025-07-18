#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	set<string> st;
	set<char>ans;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (st.find(s) != st.end())
		{
			ans.insert(s[0] >= s[1] ? s[0] : s[1]);
			ans.insert(s[1] >= s[0] ? s[1] : s[0]);
		}
		st.insert(s);

	}

	vector<string> v(st.begin(), st.end());

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i+1; j < v.size(); j++)
		{
			ans.insert(v[i][0] >= v[j][1] ? v[i][0] : v[j][1]);
			ans.insert(v[i][1] >= v[j][0] ? v[i][1] : v[j][0]);
		}
	}

	cout << ans.size() << '\n';
	for (auto i : ans)
	{
		cout << i << ' ';
	}

	return 0;
}