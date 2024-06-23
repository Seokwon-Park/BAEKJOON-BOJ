#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	unordered_map<string, bool> isUsed;
	vector<string> v;
	
	int n;
	cin >> n;
	int qix = 0;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (s == "?")
			qix = i;
		v.push_back(s);
		isUsed[s] = true;
	}

	

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		bool chkPrefix = true;
		bool chkSuffix = true;;
		if (isUsed[s])continue;
		if (qix > 0)
		{
			chkPrefix = v[qix - 1][v[qix - 1].size() - 1] == s[0];
		}
		if (qix < n - 1)
		{
			chkSuffix = v[qix + 1][0] == s[s.size()-1];
		}
		if (chkPrefix && chkSuffix)
		{
			cout << s;
			break;
		}
	}

	return 0;
}