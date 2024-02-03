#include "CollisionManager.h"
#include <cmath>

// シングルトンインスタンスの初期化
CollisionManager* CollisionManager::instance = nullptr;

// グローバルな実体の定義
CollisionManager* CollisionManagerInstance = nullptr;


// インスタンスを取得する関数の実装
CollisionManager* CollisionManager::GetInstance() {
    if (!instance) {
        instance = new CollisionManager();
    }
    return instance;
}

void CollisionManager::CollisionSubscrive(Collider* ptr) {
    // ポインタが有効か確認
    if (ptr != nullptr) {
        int objectID = ptr->GetObjectType();

        // オブジェクトがリストに存在するか確認
        if (objectMap.find(objectID) == objectMap.end()) {
            // 存在しなければリストに追加
            objectMap[objectID] = ptr;
        }
    }
}

// 判定実行処理
bool CollisionManager::CollisionJudge(Collider* a, Collider* b) {
    float distance = sqrtf(powf(a->GetPos().x - b->GetPos().x, 2) + powf(a->GetPos().y - b->GetPos().y, 2));

    return distance < a->GetRadius() + b->GetRadius();
}

void CollisionManager::CollisionUpdate() {
    for (auto it = objectMap.begin(); it != objectMap.end(); ++it) {
        Collider* objectA = it->second;

        // プレイヤーかエネミーでないなら次へ
        if (objectA->GetObjectType() != Collider::BULLET && objectA->GetObjectType() != Collider::ENEMY)
            continue;

        // イテレータ jt の初期化
        auto jt = it;
        ++jt;

        while (jt != objectMap.end()) {
            Collider* objectB = jt->second;

            if (objectB == nullptr) {
                // 未設定なら対象を削除
                jt = objectMap.erase(jt);
                continue;
            }

            if (objectB->GetObjectType() == Collider::NONE) {
                // 未設定なら対象を削除
                jt = objectMap.erase(jt);
                continue;
            }

            if (objectA->GetObjectType() == Collider::ENEMY && objectB->GetObjectType() == Collider::BULLET) {
                if (CollisionJudge(objectA, objectB)) {
                    // 判定があればアクションを実行
                    objectA->OnCollision();
                    objectB->OnCollision();
                }
            }

            ++jt;
        }
    }
}
