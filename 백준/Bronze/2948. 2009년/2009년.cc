#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

string dd[7] = { "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday" };
int days[13] = {0,0,31, 59, 90, 120,151, 181, 212, 243, 273, 304, 334 };


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int d, m;
	cin >> d >> m;
	int total = days[m] + d-1;
	cout << dd[total % 7];
	


	return 0;
}