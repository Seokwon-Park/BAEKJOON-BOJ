#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<int> sq1(4, 0);
	for (auto& i : sq1)
		cin >> i;
	
	vector<int> sq2(4, 0);
	for (auto& i : sq2)
		cin >> i;
	
	int xmin = min({ sq1[0],sq1[2], sq2[0], sq2[2] });
	int xmax = max({ sq1[0],sq1[2], sq2[0], sq2[2] }); 
	int ymin = min({ sq1[1],sq1[3], sq2[1], sq2[3] }); 
	int ymax = max({ sq1[1],sq1[3], sq2[1], sq2[3] }); 

	int n = max(xmax - xmin, ymax - ymin);
	cout << n * n;
	
	return 0;
}