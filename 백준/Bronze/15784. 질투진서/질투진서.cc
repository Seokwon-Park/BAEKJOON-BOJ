#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;


//애드혹
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, r, c;
	cin >> n >> r >> c;
	vector<vector<int>> b(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}

	bool isAngry = false;
	int jinseo = b[r-1][c-1];
	for (int i = 0; i < n; i++)
	{
		if (b[i][c - 1] > jinseo || b[r-1][i] > jinseo)
			isAngry = true;
	}

	cout << (isAngry ? "ANGRY" : "HAPPY");

	return 0;
}

