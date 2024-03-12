#include <bits/stdc++.h>

using namespace std;

bool vow(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	for (char c : s)
	{
		if (vow(c))
			cnt++;
	}
	cout << cnt;
	
}