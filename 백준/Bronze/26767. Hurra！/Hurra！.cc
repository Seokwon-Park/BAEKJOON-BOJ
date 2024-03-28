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
	
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (i % 7 == 0 && i % 11 == 0)
			cout << "Wiwat!";
		else if (i % 7 == 0)
			cout << "Hurra!";
		else if (i % 11 == 0)
			cout << "Super!";
		else
			cout << i;
		cout << '\n';
	}

	return 0;
}