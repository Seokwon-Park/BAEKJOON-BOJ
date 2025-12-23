#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'007;
//const int MOD = 987'654'321;
template <typename key, typename value>
using Hash = unordered_map<key, value>;

vector<int> p(3005, -1);

struct vec2
{
	ll x = 0;
	ll y = 0;

	vec2 operator-(vec2 p)
	{
		vec2 res;
		res.x = x - p.x;
		res.y = y - p.y;
		return res;
	}

	bool operator>(vec2 p)
	{
		if (x == p.x)
		{
			return y > p.y;
		}
		return x > p.x;
	}

	bool operator>=(vec2 p)
	{
		if (x == p.x)
		{
			return y >= p.y;
		}
		return x >= p.x;
	}
};

int ccw(vec2 v1, vec2 v2)
{
	int x1 = v1.x;
	int y1 = v1.y;
	int x2 = v2.x;
	int y2 = v2.y;

	int res = x1 * y2 - x2 * y1;
	if (res > 0) return 1;
	else if (res == 0) return 0;
	else return -1;
}

bool isCross(pair<vec2, vec2> line1, pair<vec2, vec2> line2) // AB, CD
{
	vec2 A = line1.first;
	vec2 B = line1.second;
	vec2 C = line2.first;
	vec2 D = line2.second;

	vec2 line1v = A - B; // A<-B vector
	vec2 line2v = C - D; // C<-D vector
	vec2 v1 = A - C; // A<-C vector
	vec2 v2 = A - D; // A<-D vector
	vec2 v3 = C - A; // C<-A vector
	vec2 v4 = C - B; // C<-B vector
	int res1 = ccw(line1v, v1) * ccw(line1v, v2);
	int res2 = ccw(line2v, v3) * ccw(line2v, v4);

	if (res1 == 0 && res2 == 0)
	{
		if (A > B) swap(A, B);
		if (C > D) swap(C, D);

		return D >= A && B >= C;
	}

	return res1 <= 0 && res2 <= 0 ;

}

int find(int x)
{
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
	{
		p[a] += p[b];
		p[b] = a;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<pair<vec2, vec2>> lines;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		pair<vec2, vec2> line;
		cin >> line.first.x >> line.first.y >> line.second.x >> line.second.y;
		lines.push_back(line);
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (isCross(lines[i], lines[j]))
			{
				uni(i, j);
			}
		}
	}

	set<int> parents;
	int mx = 0;
	for (int i = 0; i < n; i++)
	{
		int pp = find(i);
		parents.insert(pp);
		mx = max(mx, -p[pp]);
	}

	cout << parents.size() << '\n' << mx;


	return 0;
}