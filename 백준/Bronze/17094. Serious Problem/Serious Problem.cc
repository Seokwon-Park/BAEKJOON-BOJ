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

	int n;
	cin >> n;
	string s;
	cin >> s;
	
	int two = 0;
	int e = 0;
	for (auto c : s)
	{
		if (c == '2')
			two++;
		else
			e++;
	}

	if (two > e)
		cout << 2;
	else if (two < e)
		cout << 'e';
	else
		cout << "yee";

	return 0; 
}