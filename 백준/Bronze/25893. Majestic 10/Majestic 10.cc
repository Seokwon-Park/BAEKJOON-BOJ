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
	while (n--)
	{
		int cnt = 0;
		vector<int> v(3);
		for (int i = 0; i < 3; i++)
		{
			int m;
			cin >> m;
			v[i] = m;
			if (m >= 10)
				cnt++;
		}
		for (int i : v)
			cout << i << ' ';
		cout << '\n';
		if (cnt == 0)
			cout << "zilch";
		else if (cnt == 1)
			cout << "double";
		else if (cnt == 2)
			cout << "double-double";
		else
			cout << "triple-double";
		cout << "\n\n";
	}


	return 0;
}