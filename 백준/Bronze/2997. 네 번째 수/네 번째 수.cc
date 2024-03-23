#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v(3);
	for (int& i : v)
		cin >> i;
	sort(v.begin(), v.end());

	int gap1 = v[1] - v[0];
	int gap2 = v[2] - v[1];
	if (gap1 == gap2)
		cout << v[2] + gap1;
	else if (gap1 < gap2)
		cout << v[1] + gap1;
	else
		cout << v[0] + gap2;

	return 0;
}