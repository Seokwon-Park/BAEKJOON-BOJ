#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

bool isLine(vector<int> a, vector<int>b, vector<int>c)
{
	int x1 = b[0] - a[0]; 
	int y1 = b[1] - a[1];
	int x2 = c[0] - b[0];
	int y2 = c[1] - b[1];

	int res = x1 * y2 - x2 * y1;
	if (res == 0) return true;
	return false;


}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<int>> xy(3);
	for (int i = 0; i < 3; i++)
	{
		int x, y;
		cin >> x >> y;
		xy[i] = { x,y };
	}

	if (isLine(xy[0], xy[1], xy[2]))
	{
		cout << "WHERE IS MY CHICKEN?";
	}
	else
	{
		cout << "WINNER WINNER CHICKEN DINNER!";
	}
	
	return 0;
}