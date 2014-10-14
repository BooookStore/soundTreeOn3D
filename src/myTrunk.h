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
    void setExternalPointVertex(float width = 0.0);
    void setExternalPointID(ofIndexType &currentIDNumber);

public:
    //設定された変数を、変更。
    void resetExternalPointVertex(float width);

    //アウトプット。
    //作成した情報をメッシュへ出力する。
public:
    void writeMesh(ofMesh &mesh);

    //更新関数
public:
    void reflectMesh(ofMesh &mesh);    //幅を更新。引数分、幅を広げる。

private:
    bool isCorrect();

    //頂点情報変数
private:

    float m_currentWidth; //現在の外側の頂点と中心の頂点の距離。

    myPoint m_centerPoint;      //中心
    myPoint m_externalPoint[4]; //外側、実際に描写される頂点
};
