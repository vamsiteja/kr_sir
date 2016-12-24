
#include <iostream>
using namespace std;
struct s2
{
    int f;
    char g;
};
union u3
{
    int x;
    float y;
    int tag;
};
union u2
{
    struct s2 q;
    union u3 h;
    int tag;
};
union u1
{
    int x;
    char y;
};
struct s1
{
    int a;
    union u1 b;
    union u2 *c;
    union u1 *d;
    float e;
    int tag;
};
int main()
{
    s1 s;
    s.c=new u2;
    cin >> (s.c->q).f;
    cout << (s.c->q).f;
    return 0;
}
