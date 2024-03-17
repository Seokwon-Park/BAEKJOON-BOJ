#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vd = vector<double>;
using ll = long long;
using vll = vector<ll>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	istringstream iss(s);
	string tmp;
	string ans = "";
	while (getline(iss, tmp, '-'))
	{
		ans += tmp[0];
	}
	cout << ans;

	return 0;
}
