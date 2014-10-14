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
    if((int)(topPointHeight/m_jugeHeight) > currentNumTrunk) return true;
    return false;
}
