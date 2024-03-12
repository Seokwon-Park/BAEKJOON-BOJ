#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int sol[12] = { 0,12,11,11,10,9,9,9,8,7,6,6 };
	int pen[12] = { 0,1600,894,1327,1311,1004,1178,1357,837,1055,556,773 };

	int n;
	cin >> n;
	cout << sol[n] << ' ' << pen[n];

	return 0;
}