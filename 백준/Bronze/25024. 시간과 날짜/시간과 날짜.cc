#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int n;
vector<int> ans;
int b[1005];
int isUsed[1005];

int day[13] = { 0, 31, 29, 31,30,31,30,31,31,30,31,30,31 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		cout << ((x < 24 && y < 60) ? "Yes" : "No");
		cout << ' ';
		cout << ((x >= 1 && x <= 12) ? ((y >= 1 && y <= day[x]) ? "Yes" : "No") : "No");
		cout << '\n';
	}

	return 0;
}



