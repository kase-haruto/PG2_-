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
	colliders_.push_back(ptr);
}

// 判定実行処理
bool CollisionManager::CollisionJudge(Collider* obj_a, Collider* obj_b) {
	float distance = sqrtf(powf(obj_a->GetPos().x - obj_b->GetPos().x, 2) + powf(obj_a->GetPos().y - obj_b->GetPos().y, 2));

	return distance < obj_a->GetRadius() + obj_b->GetRadius();
}

void CollisionManager::CollisionUpdate() {
    for (auto itA = colliders_.begin(); itA != colliders_.end(); ++itA) {
        Collider* objA = *itA;

        for (auto itB = std::next(itA); itB != colliders_.end(); ++itB) {
            Collider* objB = *itB;

            // 型を比較
            if (objA->GetObjectType() != objB->GetObjectType()) {
                if (objA->GetIsCollisionEnabled() == objB->GetIsCollisionEnabled()) {
                    // 型がPlayerの場合
                    if (objA->GetObjectType() == CollisionType::PLAYER) {
                        if (objB->GetObjectType() == CollisionType::ENEMY) {
                            if (CollisionJudge(objA, objB)) {
                                objA->OnCollision();
                                // ここで objB に対する処理を行わないように修正
                            }
                        }
                        // 追加: 型がBulletの場合
                        else if (objB->GetObjectType() == CollisionType::BULLET) {
                            // 何も処理しない
                        }
                    }
                    // 型がEnemyの場合
                    else if (objA->GetObjectType() == CollisionType::ENEMY) {
                        // 追加: 型がBulletの場合
                        if (objB->GetObjectType() == CollisionType::BULLET) {
                            if (CollisionJudge(objA, objB)) {
                                objA->OnCollision();  // ここで objA（敵）に対する処理を行う
                                objB->OnCollision();  // ここで objB（弾）に対する処理を行う
                            }
                        } else if (objB->GetObjectType() == CollisionType::PLAYER) {
                            if (CollisionJudge(objA, objB)) {
                                objB->OnCollision();
                                // ここで objA に対する処理を行わないように修正
                            }
                        }
                    }
                    // 追加: 型がBulletの場合
                    else if (objA->GetObjectType() == CollisionType::BULLET) {
                        // 追加: 型がEnemyまたはPlayerの場合、何も処理しない
                        if (objB->GetObjectType() == CollisionType::ENEMY || objB->GetObjectType() == CollisionType::PLAYER) {
                            // 何も処理しない
                        }
                    }
                }
            }
        }
    }
}
