#include "Character.h"

void Hero::Initialize() {
	vec = { 500.f, 500.f };
	size = { 100.f,100.f };
	uv = { 0.0f,0.0f };
	texture_size = { 1.0f, 1.0f };
	texture_name = {"Player"};
	degree = 0;
	zoom = 1.0;
	is_reverse = false;
}

void Hero::Update() {
	if (dx.GetKeyState(DIK_D) == dx.ON) {
		vec.x.value += 1.0f;
	}
	if (dx.GetKeyState(DIK_A) == dx.ON) {
		vec.x.value -= 1.0f;
	}
}
