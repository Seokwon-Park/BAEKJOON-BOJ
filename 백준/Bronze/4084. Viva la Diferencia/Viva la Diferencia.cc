#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int f[100005];

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);

   while (1)
   {
      int ans = 0;
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      if (a == 0 && b == 0 && c == 0 && d == 0) break;
      while (1)
      {
         if (a == b && b == c && c == d)
         {
            break;
         }
         int na, nb, nc, nd;
         na = abs(a - b);
         nb = abs(b - c);
         nc = abs(c - d);
         nd = abs(d - a);
         a = na;
         b = nb;
         c = nc;
         d = nd;
         ans++;
      }
      cout << ans << '\n';
   }

   return 0;
}