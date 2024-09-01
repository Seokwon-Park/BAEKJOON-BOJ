#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int caseA = 0;
	int caseB = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a == b) continue;
		// 1이 2를 이기는 경우 2는 3을 이기고 3은 1을 이긴다.
		// 1이 3을 이기는 경우 3은 2를 이기고 2는 1을 이긴다.
		if ((a == 1 && b == 2) || (a == 2 && b == 3) || (a == 3 && b == 1))
			caseA++;
		if ((a == 1 && b == 3) || (a == 3 && b == 2) || (a == 2 && b == 1))
			caseB++;
	}

	cout << max(caseA, caseB);

	return 0;
}