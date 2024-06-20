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
	
	int n, k;
	cin >> n >> k;
	int total = 0;
	for (int i = 0; i < k; i++)
	{
		int mt;
		cin >> mt;
		total += mt / 2 + mt % 2;
	}
	if (total >= n)
		cout << "YES";
	else
		cout << "NO";
	cout << "\n";

	return 0;
}