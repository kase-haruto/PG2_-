#pragma once
#include<Novice.h>
class InputManager {

private:
	// キー入力結果を受け取る箱
	static char keys[256];
	static char preKeys[256];

public:
	InputManager();
	~InputManager();

	void Init();
	void Update();
	static bool PressKeys(int HitKey);
	static bool TriggerKeys(int hitKey);
};

