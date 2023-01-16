#include "xint.h"

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

  for (int i = -1000; i < 1000; i++)
    for (int j = -1000; j < 1000; j++) {
      Xint q(i);
      Xint w(j);
      Xint e(i * j);
      Xint f;
      f = q * w;
      auto e_l = e.len;
      auto f_l = f.len;
      if (e != f || e_l != f_l)
        cout << q << "*" << w << "=" << f << " " << e << endl;
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
  return 0;
}