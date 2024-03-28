#include<iostream>
#include<unordered_map>
#include<climits>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	int x, y = INT_MAX;
	while (tc--)
	{
		int xx, yy;
		cin >> xx >> yy;
		if (yy < y)
		{
			y = yy;
			x = xx;
		}
	}
	cout << x << ' ' << y;

	return 0;
}