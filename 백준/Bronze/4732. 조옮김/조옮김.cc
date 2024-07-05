#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

map<string, string> nxt;
map<string, string> pre;
string sound[12] = {
"A",
"A#",
"B",
"C",
"C#",
"D",
"D#",
"E",
"F",
"F#",
"G",
"G#" };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 12; i++)
	{
		nxt[sound[i]] = sound[(i + 1) % 12];
		pre[sound[i]] = sound[(i + 11) % 12];
	}

	while (1)
	{
		string s;
		getline(cin, s);
		if (s == "***")break;
		int dir;
		cin >> dir;
		cin.ignore();
		istringstream iss(s);
		string tmp;
		vector<string> ans;
		while (getline(iss, tmp, ' '))
		{
			// 전처리
			if (tmp.size() == 2)
			{
				if (nxt.find(tmp) == nxt.end() && tmp[1] == 'b')
					tmp = pre[tmp.substr(0, 1)];
				if (nxt.find(tmp) == nxt.end() && tmp[1] == '#')
					tmp = nxt[tmp.substr(0, 1)];
			}
			if (dir == 1)
			{
				tmp = nxt[tmp];
			}
			else
			{
				tmp = pre[tmp];
			}
			ans.push_back(tmp);
		}
		for (auto str : ans)
			cout << str << ' ';
		cout << '\n';
	}

	return 0;
}