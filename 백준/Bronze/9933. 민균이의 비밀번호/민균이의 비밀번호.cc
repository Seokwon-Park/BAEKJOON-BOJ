#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	set<string> pwd;
	vector<string> v;
	for(int i = 0; i<n;i++)
	{
		string s;
		cin >> s;
		pwd.insert(s);
		v.push_back(s);
	}

	string ans;
	for (int i = 0; i < n; i++)
	{
		string tmp(v[i].rbegin(), v[i].rend());
		if (pwd.find(tmp) != pwd.end())
		{
			ans = tmp;
			break;
		}
	}
	cout << ans.size() << ' ' << ans[ans.size() / 2];

	return 0;
}