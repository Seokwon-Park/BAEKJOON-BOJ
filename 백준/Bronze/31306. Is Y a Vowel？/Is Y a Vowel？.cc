#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	int a = 0, b = 0;
	for (char c : s)
	{
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		{
			a++;
			b++;
		}
		if (c == 'y')
		{
			b++;
		}
	}
	cout << a << ' ' << b;

	return 0;
}