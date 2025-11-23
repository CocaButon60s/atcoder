#pragma once
#include "MyDef.hpp"

struct Edge
/**
 * @brief グラフの辺を表す構造体
 *
 * @param to 辺の終点の頂点番号
 * @param w 辺の重み（デフォルトは0）
 */
{
    int to;
    ll w;
    Edge(const int to, const ll w = 1) : to(to), w(w) {}
};

using Graph = vc<vc<Edge>>;
