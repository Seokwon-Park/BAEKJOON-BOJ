#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

unordered_map<string, vector<string>> m;
unordered_map<string, bool> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string a, is, b;
		cin >> a >> is >> b;
		m[a].push_back(b);
	}

	queue<string> q;
	q.push("Baba");
	v["Baba"] = true;
	vector<string> ans;
	while (!q.empty())
	{
		string cur = q.front();
		q.pop();
		for (string s : m[cur])
		{
			if (v[s]) continue;
			v[s] = true;
			ans.push_back(s);
			if (m.find(s) != m.end())
			{
				q.push(s);
			}
		}
	}

	sort(ans.begin(), ans.end());

	for (auto s : ans)
		cout << s << '\n';

	return 0;
}