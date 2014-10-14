#include "myBranch.h"

ofIndexType myBranch::m_currentIndexNumber = 0;

//-----------------------------------------------------------------
myBranch::myBranch()
{
    m_jugger = new JugeTopHeight(15.0);
}

myBranch::myBranch(ofPoint basePoint)
{
    init(basePoint);
    m_jugger = new JugeTopHeight(15.0);
}

//-----------------------------------------------------------------
void myBranch::init(ofPoint basePoint)
{
    //トップの頂点位置を設定
    setTopPoint(basePoint);

    //根本の位置を保存。
    m_basePoint = basePoint;

    //最初のベースとなるtrunkオブジェクトを作成。
    myTrunk baseTrunk(m_basePoint); //中心の頂点位置を決定。
    baseTrunk.setExternalPointVertex(0.0); //外側の頂点位置を決定。
    baseTrunk.setExternalPointID(m_currentIndexNumber); //外側の頂点のIDを発行。
    baseTrunk.writeMesh(m_mesh);

    //ベクターに保存
    m_trunks.push_back(baseTrunk);

    //topと根本をつなげる。
    conectTopWithRoot(m_trunks[0]);
}

void myBranch::update()
{
    updateTopPointHeight(ofGetElapsedTimef() * 0.04);
    updateTrunkWidth(ofGetElapsedTimef() * 0.01);

    //新規でTrunkを生成するかをJugeCreateTimingクラスから判断。
    if(m_jugger->getJuge(m_topVertex,m_trunks[m_trunks.size() - 1].getCenterPoint().vertex))
    {
        createMyTrunk(m_topVertex);
        connectMyTrunk();
    }
    getMesh() = m_mesh;
}
//-----------------------------------------------------------------
ofPoint myBranch::getTopPoint() const
{
    return m_topVertex;
}

int myBranch::getNumTrunk() const
{
    return m_trunks.size();
}

//-----------------------------------------------------------------
void myBranch::setTopPoint(ofPoint basePoint)
{
    //トップの頂点位置を設定
    m_topVertex = basePoint;    //位置情報を初期設定。
    m_topID = m_currentIndexNumber;  //idを初期設定。
    m_currentIndexNumber++;
    m_mesh.addVertex(m_topVertex);
}

void myBranch::conectTopWithRoot(myTrunk rootTrunk)
{
    //根本の頂点IDを取得。
    ofIndexType root0, root1, root2, root3;
    root0 = rootTrunk.getExternalPoint(0).id;
    root1 = rootTrunk.getExternalPoint(1).id;
    root2 = rootTrunk.getExternalPoint(2).id;
    root3 = rootTrunk.getExternalPoint(3).id;

    ofIndexType topID = m_topID;

    //インデックスを追加し、コネクト。
    m_mesh.addTriangle(topID, root0, root1);
    m_mesh.addTriangle(topID, root1, root2);
    m_mesh.addTriangle(topID, root2, root3);
    m_mesh.addTriangle(topID, root3, root0);
}

//-----------------------------------------------------------------
void myBranch::updateTopPointHeight(float height)
{
    ofVec3f *vertexPtr = m_mesh.getVerticesPointer();   //根本の位置の高さから、引数分の値高くする。
    m_topVertex.y += height;
    vertexPtr[m_topID].y = m_topVertex.y;
}

void myBranch::updateTrunkWidth(float width)
{
    for (int i = 0; i < m_trunks.size(); ++i)
    {
        m_trunks[i].increaseSize(width);
        m_trunks[i].reflectMesh(m_mesh);
    }
}

//-----------------------------------------------------------------
//myTrunkオブジェクトを新規作成し、メッシュへ転送、ベクタへ登録を行う。
void myBranch::createMyTrunk(const ofPoint position)
{
    myTrunk temp(position);
    temp.setExternalPointVertex(0.0);
    temp.setExternalPointID(m_currentIndexNumber);
    temp.writeMesh(m_mesh);
    m_trunks.push_back(temp);
}

//createMyTrunk実行後に実行されることを条件に作成。
//新しいmyTrunkオブジェクトを接続する。
void myBranch::connectMyTrunk()
{
    //現在のTopとつながっているIndexをクリア。
    int numIndex = m_mesh.getNumIndices();
    int clearAmount = 12;

    for(int i = 1 ; i <= clearAmount ; i++)
    {
        int removePosition = numIndex - i;
        m_mesh.removeIndex(removePosition);
    }

    //新規作成したmyTrunkオブジェクトを下の階層と結合
    for(int i = 0 ; i <3 ; i++)
    {
        int n0 = m_trunks[m_trunks.size() - 1].getExternalPoint(i).id;
        int x0 = m_trunks[m_trunks.size() - 2].getExternalPoint(i).id;
        int x1 = m_trunks[m_trunks.size() - 2].getExternalPoint(i+1).id;
        m_mesh.addTriangle(n0,x0,x1);

        int n1 = m_trunks[m_trunks.size() -1].getExternalPoint(i+1).id;
        m_mesh.addTriangle(n0,n1,x1);
    }
    int n3 = m_trunks[m_trunks.size() - 1].getExternalPoint(3).id;
    int x3 = m_trunks[m_trunks.size() - 2].getExternalPoint(3).id;
    int x0 = m_trunks[m_trunks.size() - 2].getExternalPoint(0).id;
    m_mesh.addTriangle(n3,x3,x0);

    int n0 = m_trunks[m_trunks.size() - 1].getExternalPoint(0).id;
    m_mesh.addTriangle(n3,n0,x0);

    //TopPointと接続
    for(int i = 0 ; i < 3 ; i++)
    {
        int n0 = m_trunks[m_trunks.size() - 1].getExternalPoint(i).id;
        int n1 = m_trunks[m_trunks.size() - 1].getExternalPoint(i+1).id;
        m_mesh.addTriangle(n0,n1,m_topID);
    }
    int tempn3 = m_trunks[m_trunks.size() - 1].getExternalPoint(3).id;
    int tempn0 = m_trunks[m_trunks.size() - 1].getExternalPoint(0).id;
    m_mesh.addTriangle(tempn3,tempn0,m_topID);
}
