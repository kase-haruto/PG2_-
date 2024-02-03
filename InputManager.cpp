#include "InputManager.h"

char InputManager::keys[256] = { 0 };
char InputManager::preKeys[256] = { 0 };

InputManager::InputManager() {}

void InputManager::Update() {
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

}

bool InputManager::PressKeys(int keyCode) {
	return keys[keyCode];
}

bool InputManager::TriggerKeys(int keyCode) {
		return keys[keyCode] && !preKeys[keyCode];
}