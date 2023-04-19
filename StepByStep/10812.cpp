#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> vec(n);
	vector<int> new_vec;

	iota(vec.begin(), vec.end(), 1);

	while (m--)
	{
		int i, j, k;
		cin >> i >> j >> k;
		new_vec.insert(new_vec.begin(), vec.begin(), vec.begin() + i-1);
		new_vec.insert(new_vec.end(), vec.begin() + k - 1, vec.begin()+j);
		new_vec.insert(new_vec.end(), vec.begin() + i - 1, vec.begin() + k- 1);
		new_vec.insert(new_vec.end(), vec.begin() + j, vec.end());
		vec = new_vec;
		new_vec.clear();
	}
	for (auto n : vec)
		cout << n << ' ';



	return 0;
}
