#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'009;

string v[1005];
int t;

bool isSimulated[1005];
const int topIx = 0;
const int leftIx = 6;
const int rightIx = 2;

string rotate(string s, int dir)
{
	string res = "";
	if (dir == 1)
	{
		res = s[s.size() - 1] + s.substr(0, 7);
	}
	else
	{
		res = s.substr(1, 7) + s[0];
	}
	return res;
}

void simulate(int ix, int dir)
{
	isSimulated[ix] = true;
	if (ix - 1 > 0 && !isSimulated[ix - 1] && v[ix - 1][rightIx] != v[ix][leftIx])
	{
		simulate(ix - 1, (dir == 1) ? -1 : 1);
	}
	if (ix + 1 <= t && !isSimulated[ix + 1] && v[ix + 1][leftIx] != v[ix][rightIx])
	{
		simulate(ix + 1, (dir == 1) ? -1 : 1);
	}
	v[ix] = rotate(v[ix], dir);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	for (int i = 1; i <= t; i++)
		cin >> v[i];
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		fill(isSimulated, isSimulated + 1005, false);
		int n, d;
		cin >> n >> d;
		simulate(n, d);
	}

	int ans = 0;
	for (int i = 1; i <= t; i++)
	{
		ans += (v[i][topIx] == '1');
	}
	cout << ans;

	return 0;
}

