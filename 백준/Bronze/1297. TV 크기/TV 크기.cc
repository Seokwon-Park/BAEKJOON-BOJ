#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int d, h, w;
	cin >> d >> h >> w;
	double dd = d * d;
	double hh = h * h;
	double ww = w * w;
	int height = sqrt(dd * hh / (hh + ww));
	int width=  sqrt(dd * ww/ (hh + ww));

	cout << height << ' ' << width;
	

	return 0;
}