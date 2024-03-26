#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		int ix;
		cin >> ix;
		string s;
		cin >> s;
		s.erase(ix - 1,1);
		cout << s << '\n';
	}
	

	return 0;
}