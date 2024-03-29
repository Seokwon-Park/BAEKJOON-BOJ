
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	string s;
	cin >> n >> s;
	if (*s.rbegin() == 'G')
		s.pop_back();
	else
		s += 'G';
	cout << s;

	return 0;
}