#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

void printa(int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int i = 0; i < col; i++)
		{
			cout << '@';
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);					
	cin.tie(0);
	
	int n;
	cin >> n;
	
	printa(n, n * 5);
	printa(n, n);
	printa(n, n * 5);
	printa(n, n);
	printa(n, n * 5);

	return 0;
}