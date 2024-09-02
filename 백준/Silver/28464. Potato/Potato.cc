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
	deque<int> dq;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		dq.push_back(k);
	}
	sort(dq.begin(), dq.end());

	int sw = 0;
	int park = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			park += dq.back();
			dq.pop_back();
		}
		else
		{
			sw += dq.front();
			dq.pop_front();
		}
	}

	cout << sw << ' ' << park;

	return 0;
}