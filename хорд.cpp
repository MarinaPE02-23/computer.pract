//Метод хорд (секущих)
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double func(double x)
{
  return x*exp(x)-x-1.0;
}

double find(double x0, double x1, double eps)
{
    int iter=0;
	double x_next = 0;
    double tmp;
 
    do
    {
        tmp = x_next;
        x_next = x1 - func(x1) * (x0 - x1) / (func(x0) - func(x1));
        x0 = x1;
        x1 = tmp;
        iter++;
    } while (fabs(x_next - x1) > eps && iter<20000);
     cout <<"\nNumber of iterations is " << iter  << ". " << endl;
    return x_next;
}


int main() 
{
  double x0,x1,x,eps;
  cout << "a = ";
  cin >> x0;
  cout << "b = ";
  cin >> x1;
  cout << "eps = ";
  cin >> eps;
  x=find(x0,x1,eps);
  cout <<"Root x = "<< fixed << setprecision(16) << x;
  cout <<"\nFunction value f(x)="<< func(x);
  cin.get(); 
  return 0;
}

