#pragma once
#include "Collider.h"
#include <list>


class CollisionManager {
private:
    std::list<Collider*> colliders_; // オブジェクトリスト

    // シングルトンインスタンス
    static CollisionManager* instance;

    // プライベートコンストラクタ
    CollisionManager() {}

public:
    // デストラクタ
    ~CollisionManager() {}

    // インスタンスを取得する関数
    static CollisionManager* GetInstance();
    // 登録関数
    void CollisionSubscrive(Collider* ptr);

    // 当たり判定処理更新
    void CollisionUpdate();

    // 判定実行処理
    using CollisionType = Collider::CollisionType;
    bool CollisionJudge(Collider* a, Collider* b);
};
// シングルトンインスタンスの宣言
extern CollisionManager* CollisionManagerInstance;