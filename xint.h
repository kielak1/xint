#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <istream>
#include <string>

using namespace std;

class Xint
{
public:
  vector<int8_t> number;
  short sign;
  int len;
  Xint &inc_pos();
  Xint &dec_pos();

  Xint &plus_assign(Xint &b);
  Xint &minus_assign(Xint &b);
  bool zero() { return (number.size() == 1 && number[0] == '\0') ? true : false; }

public:
  friend ostream &operator<<(ostream &, const Xint &);
  friend istream &operator>>(istream &, Xint &);
  Xint() {
    sign = 1;
    number.push_back(0);
    len = 1;
  }
  Xint(unsigned long long n);
  Xint(long long n);
  Xint(unsigned int n);
  Xint(int n);
  Xint(string &);
  Xint(const char *);
  Xint(Xint &);
  Xint(vector<int8_t> &);
  Xint &operator++();
  Xint operator++(int temp);
  Xint &operator--();
  Xint operator--(int temp);

  friend Xint &operator+=(Xint &, Xint &);
  friend Xint &operator-=(Xint &, Xint &);
  friend bool operator==(const Xint &x1, const Xint &x2) {
    if (x1.sign == x2.sign && x1.number == x2.number)
      return true;
    else
      return false;
  }
  friend bool operator!=(const Xint &x1, const Xint &x2) {
    if (x1.sign != x2.sign || x1.number != x2.number)
      return true;
    else
      return false;
  }

  bool less(Xint &b);
  bool greater(Xint &b);
  pair<vector<int8_t>, vector<int8_t>> divide(Xint &b);
};
Xint operator+(Xint &a, Xint &b);
Xint operator-(Xint &a, Xint &b);
Xint operator*(Xint &a, Xint &b);
bool operator<(Xint &a, Xint &b);
bool operator>(Xint &a, Xint &b);
bool operator>=(Xint &a, Xint &b);
bool operator<=(Xint &a, Xint &b);