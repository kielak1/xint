/** @file
 * xint header
 *
 * @author Tadeusz Kielak <tadeusz@kielak.com>
 * @copyright Tadeusz Kielak
 * @date 2023
 */

/*! \mainpage Xint class implements operation on large integer numbers
 *
 * \section Limitations
 *
 * The only limitation on the size of the number are computer resources.
 *
 * \subsection Complexity
 *
 * .......
 */

#include <cstdint>
#include <cstring>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

//!  A Xint class.
/*!
  Exact operation on large integers.
*/
class Xint
{
private:
  /**
   * The number representation is stored in the number vector.
   * Least significant digit in number[0].
   * Most significant digit in number[len-1].
   */
  vector<int8_t> number;
  short sign;
  int len;

public:
  // constructors
  Xint();
  Xint(unsigned long long n);
  Xint(unsigned long n);
  Xint(long long n);
  Xint(long n);
  Xint(unsigned int n);
  Xint(int n);
  Xint(string &);
  Xint(const char *);
  Xint(const Xint &);
  Xint(vector<int8_t> &);
  // operator int() const {
  //   long long outcome = 0;
  //   long long mul = 1;
  //   for (int i = 0; i < number.size(); i++)
  //   {
  //     outcome += number[i] * mul;
  //     mul *= 10;
  //   }
  //   return outcome * sign;
  // }
  // operator long long() const {
  //   long long outcome = 0;
  //   long long mul = 1;
  //   for (int i = 0; i < number.size(); i++)
  //   {
  //     outcome += number[i] * mul;
  //     mul *= 10;
  //   }
  //   return outcome * sign;
  // }
  // operator unsigned long() const {
  //   long long outcome = 0;
  //   long long mul = 1;
  //   for (int i = 0; i < number.size(); i++)
  //   {
  //     outcome += number[i] * mul;
  //     mul *= 10;
  //   }
  //   return outcome * sign;
  // }

private:
  // auxiliary methods
  Xint &inc_pos();
  Xint &dec_pos();
  Xint &plus_assign(Xint &b);
  Xint &minus_assign(Xint &b);
  bool less(Xint &b);
  bool greater(Xint &b);
  pair<vector<int8_t>, vector<int8_t>> divide(Xint &b);

public:
  bool zero() { return (number.size() == 1 && number[0] == 0) ? true : false; }

  // incrementation and decrementation
  Xint &operator++();
  Xint operator++(int temp);
  Xint &operator--();
  Xint operator--(int temp);
  Xint &operator=(long long &b);
  Xint &operator=(unsigned long &b);
  Xint add(Xint &b);
  Xint sub(Xint &b);
  Xint mul(Xint &b);
  Xint div(Xint &b);
  friend Xint &operator+=(Xint &, Xint &);
  friend Xint &operator-=(Xint &, Xint &);
  friend bool operator==(const Xint &x1, const Xint &x2);
  friend bool operator!=(const Xint &x1, const Xint &x2);

  friend Xint &operator/=(Xint &, Xint &);
  friend Xint &operator%=(Xint &, Xint &);
  friend bool operator<(Xint &a, Xint &b);
  friend bool operator<(Xint &a, long long b);
  friend bool operator<(long long a, Xint b);
  friend bool operator>(Xint &a, long long b);
  friend bool operator>(long long a, Xint b);
  friend bool operator<=(Xint &a, long long b);
  friend bool operator<=(long long a, Xint b);
  friend bool operator>=(Xint &a, long long b);
  friend bool operator>=(long long a, Xint b);

  friend bool operator<(vector<int8_t> number, Xint &b);
  friend Xint &operator*=(Xint &a, Xint &b);

  friend Xint operator+(Xint a, Xint b);
  friend Xint operator-(Xint a, Xint b);
  friend Xint operator*(Xint a, Xint b);
  friend bool operator>(Xint &a, Xint &b);
  friend bool operator>=(Xint &a, Xint &b);
  friend bool operator<=(Xint &a, Xint &b);
  friend Xint operator%(Xint &a, Xint &b);
  friend Xint operator/(Xint a, Xint b);
  friend ostream &operator<<(ostream &, const Xint &);
  friend istream &operator>>(istream &, Xint &);

  long long to_long();
};
