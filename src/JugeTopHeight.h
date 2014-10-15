#include "ofMain.h"

class JugeTopHeight
{
public:
    JugeTopHeight();
    JugeTopHeight(float height);

public:
    void updateHeight();

public:
    void getInfomation()const;
    void setDecrease(float amount);
    void setJugeMin(float value);

public:
    virtual bool getJuge(ofPoint top,ofPoint down);

private:
    float m_jugeHeight;
    float m_jugeMin;
    float m_decrease;
};
