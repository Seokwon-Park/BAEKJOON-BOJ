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

	cout << "int a;\n";
	for (int i = 1; i <= n; i++)
	{
		cout << "int ";
		for (int j = 0; j < i; j++)
			cout << "*";
		cout << "ptr";
		if (i != 1)
			cout << i;
		cout << " = &";
		if (i == 1)
			cout << "a;\n";
		else if (i == 2)
			cout << "ptr;\n";
		else
			cout << "ptr" << i-1 << ";\n";
	}

	return 0;
}