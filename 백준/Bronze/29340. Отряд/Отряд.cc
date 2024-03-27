#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string a, b, c;
	cin >> a >> b;
	for (int i = 0; i < a.size(); i++)
	{
		c += (a[i] < b[i] ? b[i] : a[i]);
	}
	cout << c;
	
	
	return 0;
}