#pragma once

#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE   // TLE対策
#define _GLIBCXX_DEBUG // 配列(a[100]等)の参照エラー出力
#endif

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;

template <typename T>
using vc = vector<T>;

using vcl = vc<ll>;
using vvl = vc<vcl>;
using vvvl = vc<vvl>;
using vcs = vc<string>;
using vvs = vc<vcs>;
using vcp = vc<pll>;

using pq = priority_queue<ll, vcl>;
using pq_g = priority_queue<ll, vcl, greater<ll>>;

const ll INF = 2e18;
const auto PI = acos(-1);

#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define drep(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define nfor(i, s, n) for (ll i = s; i < n; i++)
#define dfor(i, s, n) for (ll i = (s) - 1; i >= n; i--)

template <typename T>
istream &operator>>(istream &i, vc<T> &v)
{
    rep(j, size(v)) i >> v[j];
    return i;
}
template <typename T>
bool chmin(T &a, T b)
{
    if (a == b)
        return false;
    a = min(a, b);
    return a == b;
}
template <typename T>
bool chmax(T &a, T b)
{
    if (a == b)
        return false;
    a = max(a, b);
    return a == b;
}

#define nall(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

#define pub push_back
#define eb emplace_back
#define em emplace
#define pob pop_back

#define print(x) cout << x << endl
#define YES print("Yes")
#define NO print("No")
#define YN(cond) (cond) ? YES : NO

#define next_p(v) next_permutation(nall(a))
