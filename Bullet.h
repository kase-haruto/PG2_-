#pragma once
#include "Actor.h"
class Bullet final:
    public  Actor{


private:
    bool isShoot_;

private:
    void Move();
    bool CheckOutScreen();
    void OutOfScreen();

public:
    Bullet();

    void OnCollision()override;

    void Init(Vec2f pos);
    void Init()override;
    void Update();
    void Draw();

    float GetSpeed()const;
    void SetSpeed(const float speed);

    bool GetIsShoot()const;
    void SetIsShoot(const bool isShoot);
};

