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

int main() {

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
  // int dza = 0;
  // int dza = 763423;

  // int dza = 10;
  // int dzk = 3;
  // Xint dzielna(dza), dzielnik(dzk);

  // cout << dza << "/" << dzk << "=" << dza / dzk << "   " << dza << "%" << dzk << "=" << dza % dzk << endl;
  // cout << dzielna << "/" << dzielnik << "=";
  // dzielna /= dzielnik;
  // cout << dzielna << endl;

  for (int dz1 = -1000000; dz1 < 1000000; dz1 += 1007)
    for (int dz2 = -1000000; dz2 < 1000000; dz2 += 97)
      if (dz2 != 0)
      {
        Xint dzielna(dz1), dzielnik(dz2);
        Xint dz3(dzielna);
        dz3 /= dzielnik; // cout << "#"<<dz3<<endl;
        Xint dz4(dz1 / dz2);
        if (dz4 != dz3)
          cout << dz1 << "/" << dz2 << "=" << dz1 / dz2 << "   " << dz1 << "%" << dz2 << "=" << dz1 % dz2 << "     "
               << dzielna << "/" << dzielnik << "=" << dz3 << "  dz4=" << dz4 << endl;
      }

  // auto outcome = dzielna.divide(dzielnik);
  // Xint o1(outcome.first), o2(outcome.second);
  // cout << o1 << " ! " << o2 << endl;

  // outcome = dzielna.divide(dzielnik);

  // Xint o3(outcome.first), o4(outcome.second);
  // cout << o3 << " ! " << o4 << endl;

  // outcome = dzielnik.divide(dzielna);
  // Xint o5(outcome.first), o6(outcome.second);
  // cout << o5 << " ! " << o6 << endl;
  // cout << "\n------------\n\n";
  // Xint x1(234);
  // vector<int8_t> x2;
  // x2.pb(2);
  // x2.pb(1);
  // x2.pb(4);
  // Xint xx2(x2);
  // cout << "x1=" << x1 << "  x2=" << xx2 << endl;
  // auto xxw = (x2 < x1);
  // cout << "w=" << xxw << endl;
  return 0;
}