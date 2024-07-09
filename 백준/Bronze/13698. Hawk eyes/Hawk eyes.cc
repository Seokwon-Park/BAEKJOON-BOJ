#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int b[4] = { 1,0,0,2 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	for (auto c : s)
	{
		if (c == 'A')
			swap(b[0], b[1]);
		if (c == 'B')
			swap(b[0], b[2]);
		if (c == 'C')
			swap(b[0], b[3]);
		if (c == 'D')
			swap(b[1], b[2]);
		if (c == 'E')
			swap(b[1], b[3]);
		if (c == 'F')
			swap(b[2], b[3]);
	}

	cout << find(b, b + 4, 1) - b + 1 << '\n';
	cout << find(b, b + 4, 2) - b + 1;
	
	return 0;
}