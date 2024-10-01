#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int fence[105];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	int c, d;
	cin >> c >> d;

	fill(fence + a, fence + b, 1);
	fill(fence + c, fence + d, 1);
	cout << count(fence, fence + 105, 1);


	return 0;
}