#include<iostream>
#include<unordered_map>
#include<climits>
#include<cmath>
#include<vector>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b;
	cin >> a >> b;
	int n;
	cin >> n;
	while (n--)
	{
		int m;
		cin >> m;
		int add = max(0, m - 1000);
		cout << m << ' ' << min(m,1000) * a + add * b << '\n';
	}


	return 0;
}