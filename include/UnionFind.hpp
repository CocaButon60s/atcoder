#pragma once
#include "MyDef.hpp"

/**
 * @brief Union-Find（素集合データ構造）を実装した構造体
 *
 * @details
 * Union-Find（またはDisjoint Set Union, DSU）は、要素の集合を管理し、
 * それぞれの要素がどのグループ（連結成分）に属しているかを高速に判定・統合できるデータ構造です。
 * 主にグラフの連結判定やクラスター分割などに利用されます。
 *
 * 本構造体は以下の機能を提供します：
 * - 各要素の初期化
 * - 要素が属する集合の代表元（ルート）の取得（経路圧縮付き）
 * - 2つの要素が同じ集合に属するかの判定
 * - 2つの集合の統合（サイズが大きい方に小さい方を併合）
 * - 要素が属する集合のサイズ取得
 *
 * 計算量は、各操作がほぼ定数時間（アッカーマン関数の逆数オーダー）で実行可能です。
 */
struct UnionFind
{
    vector<int> par;
    vector<int> siz;

    /**
     * @brief Union-Find（素集合データ構造）のコンストラクタ
     *
     * @param n 要素数
     *
     * 各要素を初期化し、親配列(par)は全て-1、サイズ配列(siz)は全て1に設定します。
     */
    UnionFind(int n) : par(n, -1), siz(n, 1) {}

    /**
     * @brief 要素xの属する集合の代表元（ルート）を返す
     *
     * @param x 調べたい要素のインデックス
     * @return int xが属する集合の代表元（ルート）のインデックス
     *
     * @details
     * 再帰的に親をたどり、根まで到達したらそのインデックスを返します。
     * 経路圧縮を行い、探索した経路上の各要素の親を直接根に設定します。
     */
    int root(int x)
    {
        if (par[x] == -1)
            return x;
        else
            return par[x] = root(par[x]);
    }

    /**
     * @brief 2つの要素が同じグループに属しているかを判定する
     *
     * @param x 判定する要素1のインデックス
     * @param y 判定する要素2のインデックス
     * @return 同じグループに属していればtrue、そうでなければfalse
     */
    bool issame(int x, int y)
    {
        return root(x) == root(y);
    }

    /**
     * @brief 2つの要素を同じグループに統合します。
     *
     * @param x 統合したい1つ目の要素のインデックス
     * @param y 統合したい2つ目の要素のインデックス
     * @return bool 統合が行われた場合はtrue、すでに同じグループだった場合はfalseを返します。
     *
     * @details
     * 2つの要素がすでに同じグループに属している場合は何もせずfalseを返します。
     * 異なるグループの場合は、サイズが大きい方のグループに小さい方を統合し、trueを返します。
     */
    bool unite(int x, int y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (siz[x] < siz[y])
            swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    /**
     * @brief 要素xが属する連結成分のサイズを返す
     *
     * @param x サイズを知りたい要素のインデックス
     * @return int 連結成分のサイズ
     */
    int size(int x)
    {
        return siz[root(x)];
    }
};
