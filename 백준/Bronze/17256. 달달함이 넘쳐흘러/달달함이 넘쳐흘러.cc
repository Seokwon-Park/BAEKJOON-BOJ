#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int ax, ay, az;
	int cx, cy, cz;
	cin >> ax >> ay >> az;
	cin >> cx >> cy >> cz;

	//cx = az + bx => bx = cx -az;
	cout << cx - az << ' ' << cy / ay << ' ' << cz - ax;


	return 0;
}