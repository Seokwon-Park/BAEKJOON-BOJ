#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;


int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

map<string, bool> v;

string flip(int rc, string s)
{
	int r = rc / 3;
	int c = rc % 3;
	s[rc] = s[rc] == '1' ? '0' : '1';
	for (int i = 0; i < 4; i++)
	{
		int tx = c + dx[i];
		int ty = r + dy[i];
		if (tx < 0 || ty < 0 || tx >= 3 || ty >= 3) continue;
		s[ty*3+tx] = s[ty * 3 + tx] == '1' ? '0' : '1';
	}
	return s;
}

int bfs(string target)
{
	queue<string> q;
	q.push(string(9, '0'));
	v[string(9, '0')] = 1;
	int clicked = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int j = 0; j < qs; j++)
		{
			string cur = q.front();
			q.pop();
			for (int i = 0; i < 9; i++)
			{
				string nxt = flip(i, cur);
				if (v[nxt]) continue;
				if (nxt == target)
				{
					return clicked + 1;
				}
				q.push(nxt);
				v[nxt] = true;
			}
		}
		clicked++;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		v.clear();
		string target(9,0);
		for (int i = 0; i < 3; i++)
		{
			for(int j = 0; j<3; j++)
			{
				char c;
				cin >> c;
				if (c == '*')
					target[i * 3 + j] = '1';
				else
					target[i * 3 + j] = '0';
			}
		}
		cout << bfs(target) << '\n';
		
	}
	
	return 0;
}