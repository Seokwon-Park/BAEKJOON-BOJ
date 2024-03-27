#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<int> v(3);
	for (int& i : v)
	{
		cin >> i;
	}

	sort(v.begin(), v.end());

	if (v[0] + v[1] == v[2])
		cout << 1;
	else if (v[0] * v[1] == v[2])
		cout << 2;
	else
		cout << 3;
	
	
	return 0;
}