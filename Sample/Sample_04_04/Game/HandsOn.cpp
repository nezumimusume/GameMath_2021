#include "stdafx.h"

/// <summary>
/// ポリゴンの法線を計算する
/// </summary>
/// <param name="p0">０番目の頂点座標</param>
/// <param name="p1">１番目の頂点座標</param>
/// <param name="p2">２番目の頂点座標</param>
/// <returns></returns>
Vector3 CalcNormal(Vector3 p0, Vector3 p1, Vector3 p2)
{
	Vector3 normal;
	// step-1 0番目の頂点から１番目の頂点に向かって伸びるベクトルv1を計算する。

	// step-2 0番目の頂点から２番目の頂点に向かって伸びるベクトルv2を計算する。

	// step-3 v1とv2に垂直なベクトルを求める。

	// step-4 外積で求めたベクトルは単位ベクトルではないので、正規化する。


	return normal;
}