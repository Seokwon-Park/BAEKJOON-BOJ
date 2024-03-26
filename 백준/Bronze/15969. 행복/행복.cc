#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool banned[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& i : v)
		cin >> i;
	sort(v.begin(), v.end());

	cout << *v.rbegin() - *v.begin();
	

	return 0;
}