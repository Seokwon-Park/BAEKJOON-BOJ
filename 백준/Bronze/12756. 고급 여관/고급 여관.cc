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

	int aa, ab;
	int ba, bb;
	cin >> aa >> ab >> ba >> bb;
	while (ab > 0 && bb > 0)
	{
		ab -= ba;
		bb -= aa;
	}

	if (ab > 0)
		cout << "PLAYER A";
	else if (bb > 0)
		cout << "PLAYER B";
	else
		cout << "DRAW";
		

	return 0;
}
