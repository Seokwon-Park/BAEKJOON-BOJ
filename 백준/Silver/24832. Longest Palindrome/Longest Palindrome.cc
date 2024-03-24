#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<string> sv;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	set<string> st;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		sv.push_back(s);
		st.insert(s);
	}

	string mid;
	string left;
	for (int i = 0; i < n; i++)
	{
		string t = string(sv[i].rbegin(), sv[i].rend());
		if (t == sv[i])
		{
			mid = t;
			continue;
		}
		if (st.find(t) != st.end())
		{
			left += sv[i];
			st.erase(sv[i]);
			st.erase(t);
		}
	}

	string ans = left + mid + string(left.rbegin(), left.rend());
	cout << ans.size() << '\n';
	cout << ans;

	return 0;
}