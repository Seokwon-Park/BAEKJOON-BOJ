#include<bits/stdc++.h>

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

	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	int turn = 0;
	int cur = 0;
	while (1)
	{
		if (v[cur] < x + turn)
		{
			cout << cur + 1;
			break;
		}
		turn++;
		cur = (cur + 1) % n;
	}

	return 0;
}

