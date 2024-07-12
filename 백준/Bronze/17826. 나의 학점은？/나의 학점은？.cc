#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v(50);
	for (int i = 0; i < 50; i++)
	{
		cin >> v[i];
	}
	int n;
	cin >> n;
	int ix = find(v.begin(), v.end(), n) - v.begin();

	ix++;
	if (ix <= 5)
		cout << "A+";
	else if (ix <= 15)
		cout << "A0";
	else if (ix <= 30)
		cout << "B+";
	else if (ix <= 35)
		cout << "B0";
	else if (ix <= 45)
		cout << "C+";
	else if (ix <= 48)
		cout << "C0";
	else
		cout << "F";

	return 0;
}