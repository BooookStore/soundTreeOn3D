#include "JugeTopHeight.h"

JugeTopHeight::JugeTopHeight():m_jugeHeight(4)
{
}

JugeTopHeight::JugeTopHeight(float height)
{
    m_jugeHeight = height;
}

void JugeTopHeight::setJugeHeight(float value)
{
    m_jugeHeight = value;
}

bool JugeTopHeight::getJuge(float value1,float value2) const
{
    float topPointHeight = value1;
    float currentNumTrunk = value2;

    //(topPointHeight/m_jugeHeight)   :   設定された高さから、必要なtrunkの数量を求める。
    //currentNumTrunk - 1             :   最初のピラミッド状態を、trunkの数0とするために、-1を行う。この-1により、指定の高さ分に初めて到達したところで、trueが返される。
    if((int)(topPointHeight/m_jugeHeight) > currentNumTrunk - 1) return true;
    return false;
}
