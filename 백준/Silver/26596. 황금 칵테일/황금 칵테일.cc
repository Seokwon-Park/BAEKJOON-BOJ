#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	unordered_map<string, int> um;
	for (int i = 0; i < n; i++)
	{
		string s;
		int m;
		cin >> s >> m;
		um[s] += m;
	}



	multiset<int> st;
	vector<int> v;
	for (auto [a, b] : um)
	{
		st.insert(b);
		v.push_back(b);
	}
	sort(v.begin(), v.end());

	for (auto i : v)
	{
		st.erase(st.find(i));
		int res = (int)(i * 1.618);
		if (st.find(res) != st.end())
		{
			cout << "Delicious!";
			return 0;
		}
	}

	cout << "Not Delicious...";

	return 0;
}