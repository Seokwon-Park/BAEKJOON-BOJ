#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<string> v(n);
	for (auto& i : v)
		cin >> i;
 
	if (is_sorted(v.begin(), v.end()))
		cout << "INCREASING";
	else if (is_sorted(v.begin(), v.end(), greater<string>()))
		cout << "DECREASING";
	else
		cout << "NEITHER";

	return 0;
}