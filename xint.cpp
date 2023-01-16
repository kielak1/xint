#include "xint.h"

Xint &Xint::inc_pos() {
  int i, n = number.size();
  for (i = 0; i < n && number[i] == 9; i++)
    number[i] = 0;
  if (i == n)
    number.push_back(1);
  else
    number[i]++;
  return *this;
};

Xint &Xint::dec_pos() {

  int i, n = number.size();
  for (i = 0; number[i] == 0 && i < n; i++)
    number[i] = 9;
  number[i]--;
  if (n > 1 && number[n - 1] == 0)
    number.pop_back();
  return *this;
};

Xint &Xint::plus_assign(Xint &b) {
  int t = 0, s, i;
  int n = len;
  int m = b.len;
  if (m > n)
    for (int i = n; i < m; i++)
      number.push_back(0);
  n = max(n, m);
  for (i = 0; i < n; i++) {
    if (i < m)
      s = (number[i] + b.number[i]) + t;
    else
      s = number[i] + t;
    t = s / 10;
    number[i] = (s % 10);
  }
  if (t)
    number.push_back(t);
  len = number.size();
  return *this;
}

Xint &Xint::minus_assign(Xint &b) {
  int n = len, m = b.len;
  int i, t = 0, s;
  for (i = 0; i < n; i++) {
    if (i < m)
      s = number[i] - b.number[i] + t;
    else
      s = number[i] + t;
    if (s < 0)
      s += 10, t = -1;
    else
      t = 0;
    number[i] = s;
  }
  while (n > 1 && number[n - 1] == 0)
    number.pop_back(), n--;
  len = number.size();
  return *this;
}

bool operator<(Xint &a, Xint &b) {
  if (a.sign == -1 and b.sign == 1)
    return true;
  if (a.sign == 1 and b.sign == -1)
    return false;
  int n = a.len, m = b.len;
  if (a.sign == -1 and b.sign == -1) {
    if (n != m)
      return n > m;
    while (n--)
      if (a.number[n] != b.number[n])
        return a.number[n] > b.number[n];
    return false;
  }
  if (n != m)
    return n < m;
  while (n--)
    if (a.number[n] != b.number[n])
      return a.number[n] < b.number[n];
  return false;
}
bool operator>(Xint &a, Xint &b) { return b < a; }
bool operator>=(Xint &a, Xint &b) { return !(a < b); }
bool operator<=(Xint &a, Xint &b) { return !(a > b); }

istream &operator>>(istream &in, Xint &a) {
  string s;
  in >> s;
  int n = s.size();
  a.number.clear();
  a.sign = 1;
  int last = 0;
  if (s[0] == '-') {
    a.sign = -1;
    last = 1;
  }
  for (int i = n - 1; i >= last; i--) {
    if (!isdigit(s[i])) {
      cerr << "Invalid number\n";
      exit(1);
    }
    a.number.push_back(s[i] - '0');
  }
  a.len = a.number.size();
  if (a.len == 1 and a.number[0] == 0)
    a.sign = 1;
  return in;
}

ostream &operator<<(ostream &out, const Xint &a) {
  if (a.sign == -1)
    cout << '-';
  for (int i = a.number.size() - 1; i >= 0; i--)
    cout << (short)a.number[i];
  return cout;
}

Xint::Xint(unsigned long long n) {
  sign = 1;
  do {
    number.push_back(n % 10);
    n /= 10;
  } while (n);
  len = number.size();
}

Xint::Xint(long long n) {
  if (n < 0) {
    sign = -1;
    n = -n;
  } else
    sign = 1;
  do {
    number.push_back(n % 10);
    n /= 10;
  } while (n);
  len = number.size();
}

Xint::Xint(unsigned int n) {
  sign = 1;
  do {
    number.push_back(n % 10);
    n /= 10;
  } while (n);
  len = number.size();
}

Xint::Xint(int n) {
  if (n < 0) {
    sign = -1;
    n = -n;
  } else
    sign = 1;
  do {
    number.push_back(n % 10);
    n /= 10;
  } while (n);
  len = number.size();
}

Xint::Xint(string &s) {
  number.clear();
  int n = s.size();
  for (int i = n - 1; i >= 0; i--) {
    if (!isdigit(s[i])) {
      cerr << "Invalid number\n";
      exit(1);
    }
    number.push_back(s[i] - '0');
  }
  sign = 1;
  len = number.size();
}

Xint::Xint(const char *s) {
  number.clear();
  for (int i = strlen(s) - 1; i >= 0; i--) {
    if (!isdigit(s[i])) {
      cerr << "Invalid number\n";
      exit(1);
    }
    number.push_back(s[i] - '0');
  }
  sign = 1;
  len = number.size();
}

Xint::Xint(Xint &x) {
  number = x.number;
  sign = x.sign;
  len = x.len;
}

Xint &Xint::operator++() {
  if (sign == 1)
    inc_pos();
  else {
    dec_pos();
    if (number.size() == 1 && number[0] == '\0')
      sign = 1;
  }
  return *this;
};

Xint Xint::operator++(int temp) {
  Xint aux;
  aux = *this;
  ++(*this);
  return aux;
};

Xint &Xint::operator--() {
  if (zero()) {
    number[0] = '\1';
    sign = -1;
    return *this;
  }

  if (sign == -1) {
    inc_pos();
    if (zero())
      sign = 1;
  } else
    dec_pos();

  return *this;
};

Xint Xint::operator--(int temp) {
  Xint aux;
  aux = *this;
  --(*this);
  return aux;
}

Xint &operator+=(Xint &a, Xint &b) {
  if (a.sign == 1 && b.sign == 1)
    return a.plus_assign(b);
  if (a.sign == -1 && b.sign == -1)
    return a.plus_assign(b);
  if (a.sign == 1 && b.sign == -1) {
    if (b.less(a))
      return a.minus_assign(b);
    if (b.greater(a)) {
      Xint tmp(a);
      a = b;
      a.sign = -1;
      return a.minus_assign(tmp);
    }
    a.number.clear();
    a.number.push_back('\0');
    a.sign = 1;
    a.len = 1;
    return a;
  }
  if (b.less(a))
    return a.minus_assign(b);
  if (b.greater(a)) {
    Xint tmp = a;
    a = b;
    a.sign = 1;
    return a.minus_assign(tmp);
  }
  a.number.clear();
  a.number.push_back('\0');
  a.sign = 1;
  a.len = 1;
  return a;
}

Xint &operator-=(Xint &a, Xint &b) {
  if (a.sign == 1 && b.sign == -1)
    return a.plus_assign(b);
  if (a.sign == -1 && b.sign == 1)
    return a.plus_assign(b);
  if (a.sign == 1 && b.sign == 1) {
    if (b.less(a))
      return a.minus_assign(b);
    if (b.greater(a)) {
      Xint tmp = a;
      a = b;
      a.sign = -1;
      return a.minus_assign(tmp);
    }
    a.number.clear();
    a.number.push_back('\0');
    a.len = 1;
    a.sign = 1;
    return a;
  }
  if (b.less(a))
    return a.minus_assign(b);
  if (b.greater(a)) {
    Xint tmp = a;
    a = b;
    a.sign = 1;
    return a.minus_assign(tmp);
  }
  a.number.clear();
  a.number.push_back('\0');
  a.sign = 1;
  a.len = 1;
  return a;
}

bool Xint::less(Xint &b) {
  int n = len, m = b.len;
  if (n != m)
    return n < m;
  while (n--)
    if (number[n] != b.number[n])
      return number[n] < b.number[n];
  return false;
}

bool Xint::greater(Xint &b) {
  int n = len, m = b.len;
  if (n != m)
    return n > m;
  while (n--)
    if (number[n] != b.number[n])
      return number[n] > b.number[n];
  return false;
}

Xint operator+(Xint &a, Xint &b) {
  Xint temp;
  temp = a;
  temp += b;
  return temp;
}

Xint operator-(Xint &a, Xint &b) {

  Xint temp;
  temp = a;
  temp -= b;
  return temp;
}

Xint &operator*=(Xint &a, Xint &b) {
  if (a.zero() || b.zero()) {
    a = Xint();
    return a;
  }
  a.sign *= b.sign;
  int n = a.number.size(), m = b.number.size();
  vector<int> v(n + m, 0);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      v[i + j] += (a.number[i]) * (b.number[j]);
    }
  n += m;
  a.number.resize(v.size());
  for (int s, i = 0, t = 0; i < n; i++) {
    s = t + v[i];
    v[i] = s % 10;
    t = s / 10;
    a.number[i] = v[i];
  }
  for (int i = n - 1; i >= 1 && !v[i]; i--)
    a.number.pop_back();
  a.len = a.number.size();
  return a;
}
Xint operator*(Xint &a, Xint &b) {
  Xint temp;
  temp = a;
  temp *= b;
  return temp;
}

Xint operator*(Xint &a, int b) {
  Xint temp1(b);
  temp1 *= a;
  return temp1;
}

Xint operator+(Xint &a, int b) {
  Xint temp1(b);
  temp1 += a;
  return temp1;
}

pair<string, string> Xint::divide(Xint &b){

};

Xint &operator/=(Xint &a, Xint &b) {}
