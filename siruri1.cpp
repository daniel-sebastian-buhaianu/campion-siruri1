#include <fstream>
#include <algorithm>
using namespace std;
int cb(int x, int v[], int n);
int main()
{
    ifstream f("siruri1.in");
    int n;
    f >> n;
    int x[n+1], s[n+1];
    for (int i = 1; i <= n; i++)
    {
        f >> x[i];
        s[i] = x[i];
    }
    f.close();
    sort(s + 1, s + n + 1);
    int y[n+1];
    for (int i = 1; i <= n; i++)
    {
        int poz = cb(x[i], s, n);
        y[i] = poz;
    }
    ofstream g("siruri1.out");
    for (int i = 1; i <= n; i++)
        g << y[i] << ' ';
    g.close();
    return 0;
}
int cb(int x, int v[], int n)
{
    int st = 0, dr = n+1;
    while (dr-st > 1)
    {
        int mij = st + (dr-st)/2;
        if (v[mij] < x) st = mij;
        else dr = mij;
    }
    return dr;
}
