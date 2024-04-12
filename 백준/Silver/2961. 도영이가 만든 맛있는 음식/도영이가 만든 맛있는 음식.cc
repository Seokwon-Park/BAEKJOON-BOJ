#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

int n;
int s[10];
int b[10];
bool picked[10];
int ss = 1, bb;
int gap = INT_MAX;

void func(int pick)
{
	if (pick == n)return;
	for (int i = 0; i < n; i++)
	{
		if (picked[i]) continue;
		int tmp = abs((ss * s[i]) - (bb + b[i]));
		//2if (tmp >= gap) continue;
		gap = min(tmp, gap);
		picked[i] = true;
		ss *= s[i];
		bb += b[i];
		func(pick + 1);
		bb -= b[i];
		ss /= s[i];
		picked[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i] >> b[i];
	}
	func(0);

	cout << gap;

	return 0;
}