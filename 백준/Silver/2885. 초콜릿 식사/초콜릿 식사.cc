#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, ll>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k;
	cin >> k;
	int bit = 0;
	while (k > (1 << bit))
	{
		bit++;
	}

	int n = (1 << bit);
	cout << n << ' ';
	
	if (n == k)
	{
		cout << 0;
		return 0;
	}

	int cur = 0;
	int tmp = n;
	int cut = 0;
	while (cur != k)
	{
		if (cur + tmp/2 <= k)
		{
			cur += tmp/2;
		}
		tmp /= 2;
		cut++;
	}

	cout << cut;


	return 0;
}
