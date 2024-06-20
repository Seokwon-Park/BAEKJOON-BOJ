#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> abc(3);
	while (cin >> abc[0] >> abc[1] >> abc[2])
	{
		int moved = 0;
		int a = abc[1] - abc[0] - 1;
		int b = abc[2] - abc[1] - 1;
		cout << max(a, b) << '\n';
	}

	return 0;
}