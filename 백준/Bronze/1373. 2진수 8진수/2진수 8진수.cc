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
	s = string(s.size() % 3 ==0? 0: 3-s.size()%3, '0') + s;
	string ans = "";
	for (int i = 0; i < s.length(); i += 3)
	{
		string tmp = s.substr(i, 3);
		bitset<3> b(tmp);
		ans += b.to_ulong()+ '0';
	}
	cout << ans;

	return 0;
}
