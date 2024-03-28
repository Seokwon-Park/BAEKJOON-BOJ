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
	
	int tc;
	cin >> tc;
	while (tc--)
	{
		bool zack = false, mack = false;
		vector<int> v(10);
		for (int i = 0; i < 10; i++)
		{
			int n;
			cin >> n;
			v[i] = n;
			if (n == 17)
				zack = true;
			if (n == 18)
				mack = true;
		}
		for (int i : v)
			cout << i << ' ';
		cout << '\n';
		if (zack && mack)
			cout << "both";
		else if (zack)
			cout << "zack";
		else if (mack)
			cout << "mack";
		else
			cout << "none";
		cout << "\n\n";
	}

	return 0;
}