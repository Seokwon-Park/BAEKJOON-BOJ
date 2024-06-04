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

	int n;
	cin >> n;
	n -= 2013;

	int gan = 9;
	int ji = 'F' - 'A';

	gan += n;
	ji += n;
	gan %= 10;
	ji %= 12;

	if (ji < 0) ji += 12;
	if (gan < 0) gan += 10;
	cout << (char)('A' + ji) << gan;




	return 0;
}