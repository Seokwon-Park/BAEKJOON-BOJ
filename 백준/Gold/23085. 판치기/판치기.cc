#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

bool v[3005][3005];
int n, k;

int bfs(int fr, int ba)
{
	queue<pii> q;
	q.push({fr,ba});
	v[fr][ba] = true;
	int flipped = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for(int i = 0; i< qs; i++)
		{
			auto [f, b] = q.front();
			q.pop();
			if (f == 0) return flipped;
			for (int j = 0; j <= b; j++) // Flip to Front
			{
				int flipToBack = k - j;
				if (flipToBack > f) continue;
				int tf = f + j - flipToBack;
				int tb = b + flipToBack - j;
				if (tf <0 || tb <0 || tf> n || tb >n) continue;
				if (v[tf][tb]) continue;
				q.push({ tf, tb });
				v[tf][tb] = true;
			}
		}
		flipped++;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	string s;
	cin >> s;
	int f = 0;
	int b = 0;
	for (auto c : s)
	{
		if (c == 'H')
			f++; 
		if (c == 'T')
			b++;
	}

	cout << bfs(f, b);
	
	return 0;
}