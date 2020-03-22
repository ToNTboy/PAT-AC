#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <set>

using namespace std;

#define LOCAL

#define MAXN 81

int n, m, id, q;
char c[MAXN];
map<string, set<int> > title, author, kword, pub, puby;

int main()
{
#ifdef LOCAL
    FILE *in = freopen("input.dat", "r", stdin);
#endif // LOCAL

    scanf("%d\n", &n);
    for (int i=0; i<n; i++)
    {
        scanf("%d\n", &id);

        cin.getline(c, MAXN);
        string t(c);

        title[t].insert(id);

        cin.getline(c, MAXN);
        string a(c);
        author[a].insert(id);

        do
        {
            scanf("%s", c);
            string kw(c);
            kword[kw].insert(id);
            scanf("%c", c);
        }
        while (c[0]!='\n');

        cin.getline(c, MAXN);
        string p(c);
        pub[p].insert(id);

        cin.getline(c, MAXN);
        string py(c);
        puby[py].insert(id);
    }

    scanf("%d\n", &m);
    for (int i=0; i<m; i++)
    {
        scanf("%d: ", &q);
        cin.getline(c, MAXN);
        string qk(c);
        printf("%d: %s\n", q, c);

        bool has = false;
        set<int>::iterator it, itend;
        switch(q)
        {
        case 1:
            if (title.count(qk))
            {
                has = true;
                it = title[qk].begin();
                itend = title[qk].end();
            }
            break;
        case 2:
            if (author.count(qk))
            {
                has = true;
                it = author[qk].begin();
                itend = author[qk].end();
            }
            break;
        case 3:
            if (kword.count(qk))
            {
                has = true;
                it = kword[qk].begin();
                itend = kword[qk].end();
            }
            break;
        case 4:
            if (pub.count(qk))
            {
                has = true;
                it = pub[qk].begin();
                itend = pub[qk].end();
            }
            break;
        case 5:
            if (puby.count(qk))
            {
                has = true;
                it = puby[qk].begin();
                itend = puby[qk].end();
            }
            break;
        }

        if (has)
        {
            for (; it != itend; it++)
            {
                printf("%07d\n", *it);
            }
        }
        else
        {
            printf("Not Found\n");
        }
    }

#ifdef LOCAL
    fclose(in);
#endif // LOCAL
    return 0;
}
