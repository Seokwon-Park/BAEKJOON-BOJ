#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int wc, hc, ws, hs;
	cin >> wc >> hc >> ws >> hs;
	cout << (wc - ws >= 2 && hc - hs >= 2);

	return 0;
}