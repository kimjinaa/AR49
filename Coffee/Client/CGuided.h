#pragma once
#include "CProjectile.h"

class CMonster;

class CGuided :
    public CProjectile
{
    GENERATED_OBJECT(CProjectile);
private:
    CMonster*   m_Target;

    float       m_fMass;
    Vec2        m_vAccel;
    Vec2        m_vVelocity;
    Vec2        m_vForce;

    Vec2        m_vDir;

    float       m_fRotateSpeed;


public:
    void SetDir(Vec2 _vDir) 
    {
        m_vDir = _vDir; 
        m_vDir.Normalize();
    }

private:
    virtual void FindTarget();

public:
    virtual void begin() override;
    virtual void tick(float _DT) override;

    virtual void BeginOverlap(CCollider* _OwnCol, CObj* _OtherObj, CCollider* _OtherCol) override;


private:
    void Update_1();
    void Update_2();
    void Update_3();

public:
    CLONE(CGuided);
    CGuided();
    CGuided(const CGuided& _Origin);
    ~CGuided();
};

