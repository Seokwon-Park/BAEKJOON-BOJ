#include<iostream>
#include<unordered_map>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		int a, b;
		cin >> a >> b;
		cout << a << ' ' << b << '\n';
		cout << b + (a - 1) * (b - 2) << '\n';
	}

	return 0;
}
