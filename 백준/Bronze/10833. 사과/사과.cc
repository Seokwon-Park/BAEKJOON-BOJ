#include<iostream>
#include<string>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	int ans = 0;
	while (tc--)
	{
		int a, b;
		cin >> a >> b;
		ans += (b % a);
	}
	cout << ans;

	return 0;
}