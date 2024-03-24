#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n;
int mx;

void func(string s)
{
	int num = 0;
	if (!s.empty())
	{
		num = stoi(s);
		if (num > n)
			return;
		else
			mx = max(mx, stoi(s));
	}
	func(s + '7');
	func(s + '4');
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	func("");

	cout << mx;

		
	return 0;
}