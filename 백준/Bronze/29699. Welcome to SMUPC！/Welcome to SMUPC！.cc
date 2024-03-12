#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s = "WelcomeToSMUPC";
	int N = s.length();
	int n;
	cin >> n;
	n--;
	cout << s[n % N];


	return 0;
}
