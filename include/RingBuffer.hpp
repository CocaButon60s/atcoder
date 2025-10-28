#pragma once

#include "MyDef.hpp"

/**
 * @brief 環状バッファ（リングバッファ）を管理する構造体
 *
 * @details
 * RingBuffer構造体は、固定長の整数型ベクターを環状バッファとして扱い、
 * 読み取りポインタの移動や、区間和の高速な計算をサポートします。
 * 内部で累積和（prefix sum）を保持することで、任意区間の合計値を効率的に取得できます。
 * 主に循環的なデータ処理や、スライディングウィンドウの計算などに利用されます。
 */
struct RingBuffer
{
    vcl mBuf;
    ll mSize;
    vcl mCuSum;
    ll mRp;

    /**
     * @brief RingBufferのコンストラクタ
     *
     * @param buf バッファとして使用する整数型のベクター
     * @param rp 読み取りポインタの初期値（デフォルトは0）
     *
     * @details
     * 指定されたベクターをバッファとして利用し、累積和（mCuSum）を初期化します。
     * mCuSumは、各インデックスまでの累積和を保持するため、区間和の計算が高速に行えます。
     */
    RingBuffer(vcl &buf, ll rp = 0) : mBuf(buf),
                                      mSize(buf.size()),
                                      mCuSum(vcl(buf.size() + 1, 0)),
                                      mRp(rp)
    {
        for (auto i = 0; i < mSize; i++)
            mCuSum[i + 1] = mBuf[i] + mCuSum[i];
    }

    /**
     * @brief 読み取りポインタを指定したステップ数だけ進めます。
     *
     * @param step ポインタを進めるステップ数（デフォルトは1）。
     * @details ポインタはバッファサイズでラップアラウンドされます。
     */
    void increment(ll step = 1)
    {
        mRp = (mRp + step) % mSize;
    }

    /**
     * @brief 指定した範囲の要素の合計値を取得します。
     *
     * @param left_idx 範囲の開始インデックス（0始まり、閉区間）。
     * @param right_idx 範囲の終了インデックス（0始まり、閉区間）。
     * @return ll 指定範囲の合計値。
     *
     * @details
     * リングバッファ内のleft_idxからright_idxまでの要素の合計値を返します。
     * left_idx > right_idxの場合は、バッファの末尾から先頭にかけて合計します。
     */
    ll getSum(ll left_idx, ll right_idx)
    {
        auto left = (mRp + left_idx) % mSize;
        auto right = (mRp + right_idx) % mSize;
        if (left <= right)
            return mCuSum[right + 1] - mCuSum[left];
        else
            return mCuSum[right + 1] + (mCuSum[mSize] - mCuSum[left]);
    }
};
