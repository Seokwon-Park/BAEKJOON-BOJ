#include <bits/stdc++.h>

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int abc[3];
	cin >> abc[0] >> abc[1] >> abc[2];
	sort(abc, abc + 3);
	cout << abc[1];

	return 0;
}