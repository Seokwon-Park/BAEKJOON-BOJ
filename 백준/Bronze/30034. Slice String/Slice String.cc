#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

bool isDeli[256];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		isDeli[c] = true;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		char c;
		cin >> c;
		isDeli[c] = true;
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		char c;
		cin >> c;
		isDeli[c] = false;
	}
	int l;
	cin >> l;
	cin.ignore();
	string s;
	getline(cin, s);
	vector<string> ans;
	string tmp = "";
	for (auto c : s)
	{
		if (isDeli[c] || c== ' ')
		{
			if (!tmp.empty())
			{
				ans.push_back(tmp);
				tmp = "";
			}
		}
		else
		{
			tmp += c;
		}
	}
	if (!tmp.empty())
	{
		ans.push_back(tmp);
		tmp = "";
	}

	for (auto str : ans)
	{
		cout << str << '\n';
	}
	

	return 0;
}