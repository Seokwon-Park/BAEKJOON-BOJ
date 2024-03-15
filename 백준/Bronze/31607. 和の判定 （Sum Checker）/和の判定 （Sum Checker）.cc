#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vi abc(3);
	cin >> abc[0] >> abc[1] >> abc[2];
	sort(abc.begin(), abc.end());

	if (abc[2] == abc[0] + abc[1])
		cout << 1;
	else
		cout << 0;

	return 0;
}
