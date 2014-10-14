/**********************************************************
木の枝を構成する、頂点と、その周りを囲む、実際に猫写されるエッジを表すクラス。
このクラスは、与えられた操作から、中心の頂点とその周りを囲む頂点郡を調整する。
***********************************************************/
#pragma once

#include "ofMain.h"

class myTrunk
{
    //使用する頂点情報構造体を宣言。
protected:
    struct myPoint
    {
        ofPoint vertex;
        ofIndexType id;
    };

    //デフォルトコンストラクタ
public:
    myTrunk();
    myTrunk(ofPoint newCenterPoint);

    //情報設定、取得関数
public:
    myPoint getCenterPoint() const;
    myPoint getExternalPoint(int i) const;
    float getWidth() const;

    //インプット。
    //情報を初期設定する関数。
public:
    //初期状態の作成。
    void setCenterPointVertex(ofPoint newCenterPoint);
    void setExternalPointVertex(float width);
    void setExternalPointID(ofIndexType &currentIDNumber);

public:
    //設定された変数を、変更。
    void resetSize(float width);
    void increaseSize(float amount);

    //アウトプット。
    //作成した情報をメッシュへ出力する。
public:
    void writeMesh(ofMesh &mesh);
    void reflectMesh(ofMesh &mesh);

private:
    bool isCorrect();   //メンバ変数のチェック関数
    void setExternalPointVertex();  //現在のメンバ変数の値をm_externalPointへ反映させる。

    //頂点情報変数
private:

    float m_currentWidth; //現在の外側の頂点と中心の頂点の距離。

    myPoint m_centerPoint;      //中心
    myPoint m_externalPoint[4]; //外側、実際に描写される頂点
};
