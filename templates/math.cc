//
//  MIT License
//
//  Copyright (c) [2020] [Ritesh Singla]
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to
//  deal in the Software without restriction, including without limitation the
//  rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
//  sell copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
//  IN THE SOFTWARE.
//

// Returns a^b %p
int PowMod(int64 a, int64 b, int64 p = 1000000007) {
  int64 ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % p;
    }
    a = (a * a) % p;
    b = b >> 1;
  }
  return (int)ans;
}

// (a^p-1 % p) = (1 % p) if a and p are co-prime.
// Thus, a^p-2 is the multiplicative inverse.
int MultiplicativeInverse(int64 a, int64 p = 1000000007) {
  return PowMod(a, p - 2, p);
}

int Multiply(int64 a, int64 b, int64 p = 1000000007) {
  return (int)((a * b) % p);
}

int Divide(int64 n, int64 d, int64 p = 1000000007) {
  return (int)((n * MultiplicativeInverse(d)) % p);
}

int Add(int64 a, int64 b, int64 p = 1000000007) {
  int64 c = a + b;
  if (c >= p) {
    c -= p;
  }
  if (c < 0 || c >= p) {
    c = (a + b) % p;
  }
  return (int)c;
}

int Subtract(int64 a, int64 b, int64 p = 1000000007) {
  int64 c = a - b;
  if (c < 0) {
    c += p;
  }
  if (c < 0 || c >= p) {
    c = ((a % p) + p - (b % p)) % p;
  }
  return (int)c;
}

const int MAXN = 1000000;
vector<int> fact, factinv;

void SetupFactorials(int n) {
  fact.resize(n + 1);
  factinv.resize(n + 1);
  fact[0] = fact[1] = 1;
  factinv[0] = factinv[1] = 1;
  for (int i = 2; i <= n; i++) {
    fact[i] = Multiply(fact[i - 1], i);
    factinv[i] = MultiplicativeInverse(fact[i]);
  }
}

int Combinatrics(int64 a, int64 b) {
  if (b > a) {
    return 0;
  }
  return Multiply(fact[a], Multiply(factinv[a - b], factinv[b]));
}
