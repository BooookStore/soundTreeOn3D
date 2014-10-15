/************************************************
Trunkを使用して枝を作成、管理するクラス。
************************************************/

#pragma once

#include "ofMain.h"
#include "myTrunk.h"
#include "JugeTopHeight.h"

class myBranch : public of3dPrimitive
{

    //コンストラクタ
public:
    myBranch();
    myBranch(ofPoint basePoint);

public:     //操作関数
    virtual void init(ofPoint basePoint);
    virtual void update();

public:     //情報取得関数
    ofPoint getTopPoint() const;
    int getNumTrunk() const;

private:    //初期化のヘルパー関数
    void setTopPoint(ofPoint basePoint);   //トップ頂点の位置を初期設定。
    void conectTopWithRoot(myTrunk rootTrunk);  //根本とトップをつなげる。

private:	//更新のヘルパー関数
	void updateTopPointHeight(float height);	//topの高さを更新。
	void updateTrunkWidth(float width);			//trunksの幅を更新。

private:	//新規作成のヘルパー関数
    void createMyTrunk(const ofPoint position); //myTrunkオブジェクトを新規作成。
    void connectMyTrunk();

private:

    ofPoint m_basePoint;    //根本を表す頂点

    static ofIndexType m_currentIndexNumber;    //現在のインデックスを保持。

    ofMesh m_mesh;

    ofPoint m_topVertex;
    ofIndexType m_topID;

    std::vector<myTrunk> m_trunks;

    JugeTopHeight m_jugger;

};
