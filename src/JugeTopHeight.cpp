#include "JugeTopHeight.h"

JugeTopHeight::JugeTopHeight():m_jugeHeight(4),m_jugeMin(1)
{
}

JugeTopHeight::JugeTopHeight(float height):m_jugeMin(1)
{
    m_jugeHeight = height;
}

void JugeTopHeight::updateHeight(){
    if(m_jugeHeight < m_jugeMin) {
        m_jugeHeight = m_jugeMin;
        return;
    }
    m_jugeHeight -= m_decrease;
}

void JugeTopHeight::getInfomation() const
{
    ofLog(OF_LOG_NOTICE) << "juge height : " << m_jugeHeight << endl;
    ofLog(OF_LOG_NOTICE) << "juge decrease : " << m_decrease << endl;
    ofLog(OF_LOG_NOTICE) << "juge min : " << m_jugeMin << endl;
}

void JugeTopHeight::setDecrease(float amount){
    if(amount < 0) ofLog(OF_LOG_WARNING) << "[JugeTopHeight] Juge Height is under 0.";
    m_decrease = amount;
}

void JugeTopHeight::setJugeMin(float value){
    if(value < 0 ) ofLog(OF_LOG_WARNING, "[JugeTopHeight] Juge Height value is probabry under 0 .");
    m_jugeMin = value;
}

bool JugeTopHeight::getJuge(ofPoint top,ofPoint down)
{
    bool result;
    
    //２点間の距離を計算
    float distance =top.distance(down);
    
    if(distance >= m_jugeHeight)    //距離がm_jugeHeight以上の場合はtrueを返す。
    {
        result = true;
        if(m_jugeHeight != m_jugeMin) updateHeight(); //m_jugeHeightの減少を行うかどうか。
    }else{                          //距離がm_jugeHeight以下ならば何もしない。
        result = false;
    }
    
    return result;
}
