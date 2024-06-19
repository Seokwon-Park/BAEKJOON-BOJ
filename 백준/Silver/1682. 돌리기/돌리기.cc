#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

vector<int> target(8);
map<vector<int>, bool> v;

int bfs()
{
	queue<vector<int>> q;
	q.push({ 1,2,3,4,5,6,7,8 });
	v[{ 1, 2, 3, 4, 5, 6, 7, 8 }] = true;
	int ans = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int k = 0; k < qs; k++)
		{
			vector<int> cur = q.front();
			q.pop();
			if (cur == target)
			{
				return ans;
			}

			vector<int> nxt = cur;
			//A
			for (int i = 0; i < 4; i++)
			{
				swap(nxt[i], nxt[7-i]);
			}
			if (!v[nxt])
			{
				q.push(nxt);
				v[nxt] = true;
			}

			nxt = cur;
			int up = nxt[3];
			int down = nxt[4];
			for (int i = 3; i >0; i--)
			{
				nxt[i] = nxt[i-1];
				nxt[8-i-1] = nxt[8-i];
			}
			nxt[0] = up;
			nxt[7] = down;
			if (!v[nxt])
			{
				q.push(nxt);
				v[nxt] = true;
			}

			nxt = cur;
			int upleft = nxt[1];
			nxt[1] = nxt[2];
			nxt[2] = nxt[5];
			nxt[5] = nxt[6];
			nxt[6] = upleft;
			if (!v[nxt])
			{
				q.push(nxt);
				v[nxt] = true;
			}

			nxt = cur;
			swap(nxt[0], nxt[4]);
			if (!v[nxt])
			{
				q.push(nxt);
				v[nxt] = true;
			}
		}
		ans++;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	for (int i = 0; i < 8; i++)
	{
		cin >> target[i];
	}

	cout << bfs();

	

	return 0;
}