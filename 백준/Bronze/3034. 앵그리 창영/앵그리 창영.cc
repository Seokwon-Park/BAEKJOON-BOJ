#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	double w, h;
	cin >> n >> w >> h;
	double s = sqrt(w * w + h * h);
	
	while (n--)
	{
		double m;
		cin >> m;
		if (m <= s)
			cout << "DA";
		else
			cout << "NE";
		cout << '\n';
	}



	return 0;
}