#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int hh, mm;
	cin >> hh >> mm;
	cout << (hh - 9) * 60 + mm;
	return 0;
}