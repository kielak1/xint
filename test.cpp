#include "xint.h"

#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <sys/time.h>

#define TEST
#define pb push_back
#define mp make_pair

#define fi(a, b) for (int i = a; i <= b; i++)
#define fj(a, b) for (int j = a; j <= b; j++)
#define fo(a, b) for (int o = a; o <= b; o++)

#define fdi(a, b) for (int i = a; i >= b; i--)
#define fdj(a, b) for (int j = a; j >= b; j--)
#define fdo(a, b) for (int o = a; o >= b; o--)

#define sz(x) (int)x.size()

#define init_v(tab, n) fo(1, n) tab.pb(0)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<ll> vll;

template <typename T> ostream &operator<<(ostream &os, vector<T> v) {
  fi(0, sz(v) - 1) os << v[i] << " ";
  return os;
}
template <typename A, typename B> ostream &operator<<(ostream &os, pair<A, B> p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template <typename T> ostream &operator<<(ostream &os, set<T> t) {
  for (auto z : t)
  {
    os << z << " ";
  }
  return os;
}
template <typename T1, typename T2> ostream &operator<<(ostream &os, map<T1, T2> t) {
  cerr << endl;
  for (auto z : t)
  {
    os << "\t" << z.first << " -> " << z.second << endl;
  }
  return os;
}

#ifdef TEST
#define dbg(x)                                                                                                         \
  { cerr << __LINE__ << "\t" << #x << ": " << x << endl; }
#define dbg0(x, n)                                                                                                     \
  {                                                                                                                    \
    cerr << __LINE__ << "\t" << #x << ": ";                                                                            \
    for (int ABC = 0; ABC < n; ABC++)                                                                                  \
      cerr << x[ABC] << ' ';                                                                                           \
    cerr << endl;                                                                                                      \
  }
#else
#define dbg(x) ;
#define dbg0(x, n) ;
#endif

vector<ll> stamps;

void time_mark() {
  struct timeval tp;
  gettimeofday(&tp, NULL);
  auto x = tp.tv_sec * 1000000 + tp.tv_usec;
  double t = (double)(x);
  t = round(t / 10000);
  t *= 10;
  stamps.pb(t);
  if (stamps.size() > 1)
  {
    ll t0, t1;

    t0 = stamps[stamps.size() - 1] - stamps[stamps.size() - 2];
    t1 = stamps[stamps.size() - 1] - stamps[0];

    auto t1s = t1 / 1000;
    auto t1ms = (t1 - (t1s * 1000));
    auto t0s = t0 / 1000;
    auto t0ms = (t0 - (t0s * 1000));
    cout << "last test: " << t0s << ".";
    if (t0ms == 0)
      cout << 0;
    else
    {
      if (t0ms < 10) cout << 0;
      if (t0ms < 100) cout << 0;
      cout << t0ms;
    }
    cout << " sek.\t";
    cout << "total: " << t1s << ".";
    if (t1ms == 0)
      cout << 0;
    else
    {
      if (t1ms < 10) cout << 0;
      if (t1ms < 100) cout << 0;
      cout << t1ms;
    }
    cout << " sek.\t" << endl;
  }
}

int main() {

  {
    Xint a, b, c, d, e;
    a = 12;
    b = 3;
    c = 5;
    d = 7;
    e = (a + b) + (c + d);

    cout << e << endl;
  }

  time_mark();
  cout << "Test: + ++ - --\n";
  ll oper = 2143421;
  Xint xoper(oper);
  for (int i = -80000; i < 80000; i += 10)
    for (int j = -1000; j < 1000; j += 10)
    {
      oper++;
      xoper++;
      Xint jj(j);
      Xint ii(i);
      oper += j;
      xoper += jj;
      ++oper;
      ++xoper;
      --oper;
      --xoper;
      oper -= j;
      xoper -= jj;
      oper--;
      xoper--;
      Xint yoper(oper);
      if (xoper != yoper) cout << "oper=" << oper << " xoper=" << xoper << endl;
    }
  time_mark();
  cout << "Test: *\n";
  for (int i = -80000; i < 80000; i += 10)
    for (int j = -1000; j < 1000; j += 10)
    {
      Xint q(i);
      Xint w(j);
      Xint e(i * j);
      Xint f;
      f = q * w;
      auto e_l = e.len;
      auto f_l = f.len;
      if (e != f || e_l != f_l) cout << q << "*" << w << "=" << f << " " << e << endl;
    }
  time_mark();

  cout << "Test: < <= > >= == !=\n";
  for (int i = -10000; i < 10000; i += 10)
    for (int j = -20000; j < 20000; j += 10)
    {
      Xint q(i);
      Xint w(j);

      if (i < j && !(q < w)) cout << q << " [<] " << endl;
      if (i <= j && !(q <= w)) cout << q << " [<=] " << endl;
      if (i > j && !(q > w)) cout << q << " [>] " << endl;
      if (i >= j && !(q >= w)) cout << q << " [>=] " << endl;
      if (i == j && !(q == w)) cout << q << " [==] " << endl;
      if (i != j && !(q != w)) cout << q << " [!=] " << endl;
    }
  time_mark();

  cout << "Test: /= %=\n";
  for (int dz1 = -1000; dz1 < 100; dz1 += 1)
    for (int dz2 = -1000; dz2 < 100; dz2 += 1)
      if (dz2 != 0)
      {
        Xint dzielna(dz1), dzielnik(dz2);
        Xint dz3(dzielna);
        dz3 %= dzielnik;
        Xint dz4(dz1 % dz2);
        if (dz4 != dz3)
          cout << dz1 << "/" << dz2 << "=" << dz1 % dz2 << "   " << dz1 << "%" << dz2 << "=" << dz1 % dz2 << "     "
               << dzielna << "/" << dzielnik << "=" << dz3 << "  dz4=" << dz4 << endl;
      }

  time_mark();

  cout << "Test: / %\n";
  for (int i = -500; i < 500; i++)
    for (int j = -300; j < 300; j++)
      if (j != 0)
      {
        Xint a(i);
        Xint b(j);
        Xint c;
        c = a / b;
        Xint d;
        d = a % b;
        Xint e(i / j);
        Xint f(i % j);
        if (c != e) cout << i << "/" << j << "=" << i / j << "    " << a << "/" << b << "=" << c << endl;
        if (d != f) cout << i << "%" << j << "=" << i % j << "    " << a << "%" << b << "=" << d << endl;
      }

  time_mark();
  cout << "Test: big number  *=\n";
  string ff_big("-1234567890");
  Xint start_big(ff_big);
  Xint big(start_big);
  for (int i = -500; i < 500; i += 10)
    for (int j = -300; j < 300; j += 10)
      if (i != 0 && j != 0)
      {
        Xint ii(i);
        Xint jj(j);
        big *= ii;
        big *= jj;
      }
  auto maxlen = big.len;
  cout << maxlen << " digits\n";
  time_mark();
  cout << "Test: big number  /=\n";
  for (int i = -500; i < 500; i += 10)
    for (int j = -300; j < 300; j += 10)
      if (i != 0 && j != 0)
      {
        Xint ii(i);
        Xint jj(j);
        big /= ii;
        big /= jj;
      }
  if (big != start_big) cout << big << endl;
  time_mark();

  // while(1)
  // {
  //   big*=big;
  //   cout<<big.len << endl;
  // }

  return 0;
}