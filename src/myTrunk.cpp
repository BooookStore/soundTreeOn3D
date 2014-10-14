#include "myTrunk.h"

myTrunk::myTrunk()
{
    //initialize
}

myTrunk::myTrunk(ofPoint newCenterPoint)
{
    //中心を決定。
    setCenterPointVertex(newCenterPoint);
}

//-----------------------------------------------------------
//情報設定、取得関数
myTrunk::myPoint myTrunk::getCenterPoint() const
{
    return m_centerPoint;
}

myTrunk::myPoint myTrunk::getExternalPoint(int i) const
{
    if (i >= 4)
    {
        cerr << "Error : myTrunk : over access." << endl;
        exit(-1);
    }
    return m_externalPoint[i];
}

float myTrunk::getWidth() const
{
    return m_currentWidth;
}

//-----------------------------------------------------------
//情報を初期設定する関数。

void myTrunk::setCenterPointVertex(ofPoint newCenterPoint)
{
    m_centerPoint.vertex = newCenterPoint;
}


void myTrunk::setExternalPointVertex(float width)
{
    m_currentWidth = width;
    setExternalPointVertex();
}

void myTrunk::setExternalPointID(ofIndexType &currentIDNumber)
{
    if (currentIDNumber < 0)
    {
        cout << "[Error]" << "currentIDNumber must be upper 0." << endl;
        exit(-1);
    }

    for (int i = 0; i < 4; ++i)
    {
        m_externalPoint[i].id = currentIDNumber;
        currentIDNumber++;
    }
}

//-----------------------------------------------------------
void myTrunk::resetSize(float width)
{
    m_currentWidth = width; //ExternalPointの示す幅を指定。
    setExternalPointVertex(width);
}

void myTrunk::increaseSize(float amount)
{
    m_currentWidth += amount;   //ExternalPointの幅を、引数分増加。
    setExternalPointVertex(m_currentWidth);
}

//-----------------------------------------------------------
//作成した情報をメッシュへ出力する。
void myTrunk::writeMesh(ofMesh &mesh)
{
    for (int i = 0; i < 4; ++i)
    {
        mesh.addVertex(m_externalPoint[i].vertex);
    }
}

void myTrunk::reflectMesh(ofMesh &mesh)
{
    ofPoint *mesh_vertices = mesh.getVerticesPointer();

    for (int i = 0; i < 4; ++i)
    {
        mesh_vertices[m_externalPoint[i].id] = m_externalPoint[i].vertex;
    }
}

//-----------------------------------------------------------
bool myTrunk::isCorrect()
{
    if (m_currentWidth < 0)
    {
        ofLog(OF_LOG_WARNING, "trunk width is under the 0.");
        return false;
    }
    return true;
}

void myTrunk::setExternalPointVertex()
{
    isCorrect();    //メンバ変数の値を監視。

    //trunkのデータを作成。
    for (int i = 0; i < 4; ++i)
    {
        //x座標
        if (i == 0 || i == 3) m_externalPoint[i].vertex.x = m_centerPoint.vertex.x - m_currentWidth;
        else m_externalPoint[i].vertex.x = m_centerPoint.vertex.x + m_currentWidth;

        //z座標
        if (i == 2 || i == 3) m_externalPoint[i].vertex.z = m_centerPoint.vertex.z - m_currentWidth;
        else m_externalPoint[i].vertex.z = m_centerPoint.vertex.z + m_currentWidth;

        //y座標（高さ）
        m_externalPoint[i].vertex.y = m_centerPoint.vertex.y;
    }
}
