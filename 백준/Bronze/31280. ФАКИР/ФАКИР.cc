#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<int> v(4);
	for (int& i : v)
		cin >> i;
	sort(v.begin(), v.end(), greater<int>());
	cout << v[0] + v[1] + v[2] + 1;

	return 0;
}