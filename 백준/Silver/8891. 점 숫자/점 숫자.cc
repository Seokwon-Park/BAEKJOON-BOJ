#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'009;

pii FindCoord(int n)
{
	int st = 1;
	int sum = 0;
	while (sum < n)
	{
		sum += st++;
	}
	int gap = sum - n;
	int x = st - 1;
	int y = 1;
	for (int i = 0; i < gap; i++)
	{
		x--;
		y++;
	}

	return { x,y };
}

int FindVal(int x, int y)
{
	int sum = 0;
	int tmpx = x + y - 1;
	for (int i = 1; i <= tmpx; i++)
	{
		sum += i;
	}

	sum -= tmpx - x;

	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	int tc;
	cin >> tc;
	while (tc--)
	{
		int a, b;
		cin >> a >> b;
		auto [ax, ay] = FindCoord(a);
		auto [bx, by] = FindCoord(b);
		int tx = ax + bx;
		int ty = ay + by;
		cout << FindVal(tx, ty) << '\n';
	}

	return 0;
}

