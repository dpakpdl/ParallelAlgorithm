#include <iostream>
using namespace std;
#include <cmath>

void eratosthenes(bool prime[], int limit);

int main()
{
  const int limit=100;
  bool prime[limit];
  eratosthenes(prime, limit);
  for (int i=0; i<limit; i++)
    if (prime[i])
      cout << i << ' ';
  cout << endl;
  return 0;
}

void eratosthenes(bool prime[], int limit)
{
  int i, x, m, sqrtn;
  sqrtn = sqrt(float(limit));
  for (i=2; i<limit; i++)
    prime[i] = true;
  prime[0] = prime[1] = false;
  x=2;
  while (x <= sqrtn) {
    m = 2 * x;
    while (m < limit) {
      prime[m] = false;
      m = m + x;
    }
    for (int i=0; i<limit; i++)
      if (prime[i])
	if (i==53)
	  cout << i << endl;
	else
	  cout << i << ' ';
    cout << endl << endl;
    do
      ++x;
    while (x < limit && !prime[x]);
  }
}