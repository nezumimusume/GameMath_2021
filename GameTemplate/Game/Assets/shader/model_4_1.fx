/*!
 * @brief	シンプルなモデルシェーダー。
 */
#include "ModelVSCommon.h"

struct DirectionLight{
    float3 dir;
    float4 color;
};
cbuffer cbLig : register(b1)
{
    DirectionLight light[4];
};
///////////////////////////////////////
// 定数
///////////////////////////////////////

////////////////////////////////////////////////
// 構造体
////////////////////////////////////////////////

// ピクセルシェーダーへの入力
struct SPSIn
{
	float4 pos : SV_POSITION; //座標。
	float3 normal : NORMAL; //法線。
	float2 uv : TEXCOORD0; //UV座標。
};

////////////////////////////////////////////////
// グローバル変数。
////////////////////////////////////////////////
sampler g_sampler : register(s0);
///////////////////////////////////////
// シェーダーリソース
///////////////////////////////////////
Texture2D<float4> albedoTexture : register(t0);     // アルベド



////////////////////////////////////////////////
// 関数定義。
////////////////////////////////////////////////

SPSIn VSMain(SVSIn vsIn)
{
	SPSIn psIn;
    
	psIn.pos = mul(mWorld, vsIn.pos); // モデルの頂点をワールド座標系に変換

	psIn.pos = mul(mView, psIn.pos); // ワールド座標系からカメラ座標系に変換
	psIn.pos = mul(mProj, psIn.pos); // カメラ座標系からスクリーン座標系に変換
	psIn.normal = normalize(mul(mWorld, vsIn.normal));

	psIn.uv = vsIn.uv;
    return psIn;
}

/// <summary>
/// ピクセルシェーダーのエントリー関数。
/// </summary>
float4 PSMain( SPSIn In) : SV_Target0
{
    
	//G-Bufferの内容を使ってライティング
    //アルベドカラーをサンプリング。
    float4 albedoColor = albedoTexture.Sample(g_sampler, In.uv);
    float3 normal = In.normal ;
    
    // step-1 4本のディレクションライトを使ってライトを計算する。

    float4 finalColor;
    finalColor.xyz = albedoColor.xyz * lig;
    finalColor.w = 1.0f;
    return finalColor;
}
