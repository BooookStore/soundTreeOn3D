#include "JugeTopHeight.h"

JugeTopHeight::JugeTopHeight():m_jugeHeight(4)
{
}

JugeTopHeight::JugeTopHeight(float height)
{
    m_jugeHeight = height;
}

void JugeTopHeight::updateHeight(){
    m_jugeHeight -= m_decrease;
}

void JugeTopHeight::setDecreaseJugeHeight(float amount){
    if(amount < 0) ofLog(OF_LOG_WARNING) << "[JugeTopHeight] amount is under 0.";
    m_decrease = amount;
}

bool JugeTopHeight::getJuge(ofPoint top,ofPoint down) const
{
    float distance =top.distance(down);
    if(distance >= m_jugeHeight)
    {
        return true;
    }
    return false;
}
