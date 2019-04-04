#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <vector>


using namespace std;

class Rational
{
  public:
      Rational()
      {
          num = 0;
          denom = 1;
      }
      Rational(int numerator, int denominator)
      {
          if (numerator < 0)
          {
              sign *= -1;
              numerator *= -1;
          }
          if (denominator < 0)
          {
              sign *= -1;
              denominator *= -1;
          }
          if (numerator == 0)
          {
              denominator = 1;
          }
          if (denominator == 0)
          {
              throw invalid_argument("denominator cannot be equal 0");
          }
          gcd_n = gcd(numerator, denominator);
          num = sign * numerator / gcd_n;
          denom = denominator / gcd_n;
      }
      int Numerator() const
      {
          return num;
      }
      int Denominator() const
      {
          return denom;
      }

      Rational operator+(Rational rhs)
      {
          Rational new_rhs(rhs.Numerator(), rhs.Denominator());
          return Rational(num * new_rhs.Denominator() + new_rhs.Numerator() * denom, denom * new_rhs.Denominator());
      }

      Rational operator-(Rational rhs)
      {
          Rational new_rhs(rhs.Numerator(), rhs.Denominator());
          return Rational(num * new_rhs.Denominator() - new_rhs.Numerator() * denom, denom * new_rhs.Denominator());
      }
      Rational operator*(Rational rhs)
      {
          Rational new_rhs(rhs.Numerator(), rhs.Denominator());
          return Rational(num * new_rhs.Numerator(), denom * new_rhs.Denominator());
      }
      Rational operator/(Rational rhs)
      {
          Rational new_rhs(rhs.Numerator(), rhs.Denominator());
          if (new_rhs.Numerator() == 0)
          {
              throw domain_error("numerator of second fraction cannot be equal 0");
          }
          return Rational(num * new_rhs.Denominator(), denom * new_rhs.Numerator());
      }
      Rational operator+=(Rational rhs)
      {
          Rational new_rhs(rhs.Numerator(), rhs.Denominator());
          //Rational lhs(num * new_rhs.Denominator() + new_rhs.Numerator() * denom, denom * new_rhs.Denominator())

          //
          return Rational (num * new_rhs.Denominator() + new_rhs.Numerator() * denom, denom * new_rhs.Denominator());
      }

      Rational operator-=(Rational rhs)
      {
          Rational new_rhs(rhs.Numerator(), rhs.Denominator());
          return Rational(num * new_rhs.Denominator() - new_rhs.Numerator() * denom, denom * new_rhs.Denominator());
      }
      Rational operator*=(Rational rhs)
      {
          Rational new_rhs(rhs.Numerator(), rhs.Denominator());
          return Rational(num * new_rhs.Numerator(), denom * new_rhs.Denominator());
      }
      Rational operator/=(Rational rhs)
      {
          Rational new_rhs(rhs.Numerator(), rhs.Denominator());
          if (new_rhs.Numerator() == 0)
          {
              throw domain_error("numerator of second fraction cannot be equal 0");
          }
          return Rational(num * new_rhs.Denominator(), denom * new_rhs.Numerator());
      }

  private:
      int num;
      int denom;
      int gcd_n;
      int sign = 1;

      int gcd(const int& a, const int& b)
      {
      	if (b == 0)
      		return a;
      	else
      		return gcd(b, a%b);
      }

};
bool operator==(const Rational& lhs, const Rational& rhs)
{
    Rational new_lhs(lhs.Numerator(), lhs.Denominator());
    Rational new_rhs(rhs.Numerator(), rhs.Denominator());
    return (new_lhs.Numerator() == new_rhs.Numerator() && new_lhs.Denominator() == new_rhs.Denominator());
}
bool operator<(const Rational& lhs, const Rational& rhs)
{
    Rational new_lhs(lhs.Numerator(), lhs.Denominator());
    Rational new_rhs(rhs.Numerator(), rhs.Denominator());
    return (new_lhs.Numerator() * new_rhs.Denominator() - new_rhs.Numerator() * new_lhs.Denominator() < 0);
}
ostream& operator<<(ostream& stream, const Rational& rhs)
{
    stream << rhs.Numerator()<<"/"<<rhs.Denominator();
    return stream;
}
istream& operator>>(istream& stream, Rational& rhs)
{
    int n, d;
    char c;
    stream >> n >> c >> d;
    if (stream && c == '/')
    {
        rhs = Rational(n, d);
    }

    return stream;
}

int main()
{
    Rational r1, r2;
    char c;
    char c2;
    stringstream input;
    input<<"1/2+1/4"<<endl;
    input<<"1/2-10/4"<<endl;
    input<<"6/2*12/-4"<<endl;
    input<<"1/2/7/4"<<endl;
    input<<"1/2/-0/3"<<endl;
    input<<"33/2+1/0"<<endl;
    /*
    //I cannot reload +=, -=, *=, /= and I dont know why
    // Any ideas?
    //I reloaded these operators in class Rational and commented the block of code below
    input<<"1/2+1/4"<<endl;
    input<<"1/2-10/4"<<endl;
    input<<"6/2*12/4"<<endl;
    input<<"1/2/7/4"<<endl;
    */
    while (!input.eof()) try
    {
        input >> r1 >> c;
        if(input.peek() != '=')
        {
                input >> r2;
                if (c == '+')
                {
                    cout << r1 + r2 << endl;
                }
                else if (c == '-')
                {
                    cout << r1 - r2 << endl;
                }
                else if (c == '*')
                {
                    cout << r1 * r2 << endl;
                }
                else if (c == '/')
                {
                    try
                    {
                        cout << r1 / r2 << endl;
                    }
                    catch (domain_error&)
                    {
                        cout << "Division by zero" << endl;
                    }

                }
        }
        else
        {
            //trying reloaded operators +=, -+, *=, /=
            /*
            input.ignore(1);
            input >> r2;
            if (c == '+')
            {
                cout << r1 += r2;
            }
            else if (c == '-')
            {
                cout << r1 -= r2;
            }
            else if (c == '*')
            {
                cout << r1 *= r2;
            }
            else if (c == '/')
            {
                try
                {
                    cout << r1 /= r2;
                }
                catch (domain_error&)
                {
                    cout << "Division by zero" << endl;
                }

            }*/
        }


    }
    catch (invalid_argument& ex)
    {
        cout << "Invalid argument: " << ex.what() << endl;
    }

    return 0;
}
