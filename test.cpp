#include "xint.h"

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
#define dbg(x)                                                                           \
  { cerr << __LINE__ << "\t" << #x << ": " << x << endl; }
#define dbg0(x, n)                                                                       \
  {                                                                                      \
    cerr << __LINE__ << "\t" << #x << ": ";                                              \
    for (int ABC = 0; ABC < n; ABC++)                                                    \
      cerr << x[ABC] << ' ';                                                             \
    cerr << endl;                                                                        \
  }
#else
#define dbg(x) ;
#define dbg0(x, n) ;
#endif

int main() {

  //   Xint krok(-2);
  //   Xint koniec(300000000);
  //   Xint start(-32);
  //   //   for (Xint a = start; a < koniec; a *= krok)
  //   //     cout << a << endl;

  //   cout << "strtt.number:" << start.number << " &" << start << endl;
  //   //   koniec /= start;
  //   //   cout << koniec << endl;
  //   Xint a(-321);
  //   Xint zero;
  //   Xint b("123");
  //   Xint c(b);
  //   Xint d;
  //   cout << a << " " << b << " " << c << " " << zero << " " << d << endl;
  //   cout << a.len << " " << b.len << " " << c.len << " " << zero.len << " "
  //   << d.len
  //        << endl;
  //   // cout << a - b << endl;
  //   cout << b - a << endl;
  //   // cout << a + b << endl;
  //   // cout << b + a << endl;

  for (int i = -1000; i < 1000; i += 10)
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

  Xint a(23);
  Xint b(111);
  Xint c;
  c = a + b;
  cout << a << "+" << b << "=" << c << endl;
  a++;
  b--;
  c = a + b;
  cout << a << "+" << b << "=" << c << endl;
  --a;
  ++b;
  c = a + b;
  cout << a << "+" << b << "=" << c << endl;

  for (int i = -1000; i < 1000; i += 10)
    for (int j = -1000; j < 1000; j += 10)
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

  Xint dzielna("230"), dzielnik("300");
  auto outcome = dzielna.divide(dzielnik);
  Xint o1(outcome.first), o2(outcome.second);
  cout << o1 << " ! " << o2 << endl;

  outcome = dzielna.divide(dzielna);
  Xint o3(outcome.first), o4(outcome.second);
  cout << o3 << " ! " << o4 << endl;

  outcome = dzielnik.divide(dzielna);
  Xint o5(outcome.first), o6(outcome.second);
  cout << o5 << " ! " << o6 << endl;
  return 0;
}