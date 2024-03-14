#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	cin.ignore(); //flush
	for (int i = 1; i <= n; i++)
	{
		string s;
		getline(cin, s);
		cout << i << ". " << s << '\n';
	}
	return 0;
}