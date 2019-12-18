﻿#ifndef CHARCTER_H_
#define CHARCTER_H_

#include "Object.h"
#include "Gravity.h"

/**
 * @brief 方向
 */
enum class Direction
{
	//! 上
	Up,
	//! 下
	Down,
	//! 右
	Right,
	//! 左
	Left
};

/**
 * @brief キャラクタークラス
 */
class Character : public Object
{
public:
	/**
	 * @brief コンストラクタ
	 * @param name キャラクターの名前
	 */
	explicit Character(const std::string& name) :name(name) {}

	/**
	 * @brief	座標を修正する
	 * @param	direction　　　座標修正する方向
	 * @param	blockPosition　当たっているブロックの座標
	 * @details	HitCheckの中で呼び出す
	 */
	virtual void CorrectCoordinate(Direction direction, const Position& blockPosition) {}


	/**
	 * @brief	previousPositionを取得する
	 */
	inline const Position& GetPreviousPosition() const
	{
		return previousPosition;
	}

	/**
	 * @brief	offsetを取得する
	 */
	inline const Position& GetOffset() const
	{
		return offset;
	}

	/**
	 * @brief	previousOffsetを取得する
	 */
	inline const Position& GetPreviousOffset() const
	{
		return previousOffset;
	}

	/**
	 * @brief	Vectorを取得する
	 */
	inline const Vec2 GetVector() const
	{
		Position startPosition =
		{
			CoordinateX(previousPosition.x.value + previousOffset.x.value),
			CoordinateY(previousPosition.y.value + previousOffset.y.value)
		};

		Position endPosition =
		{
			CoordinateX(position.x.value + offset.x.value),
			CoordinateY(position.y.value + offset.y.value)
		};

		Vec2 vector =
		{
			startPosition,
			endPosition
		};

		return vector;
	}

protected:

	//! 前の座標を保存する
	Position previousPosition =
	{
		CoordinateX(0.f),
		CoordinateY(0.f)
	};

	Position offset = 
	{
		CoordinateX(0.f),
		CoordinateY(0.f)
	};

	Position previousOffset =
	{
		CoordinateX(0.f),
		CoordinateY(0.f)
	};

	Gravity gravity{ &position };

private:

	//! キャラクターの名前
	Name name = Name("None");
};


/**
 * @brief UIクラス
 */
class UI : public Object
{

};

/**
 * @brief NPCクラス
 */
class NPC : public Character
{

};

/**
 * @brief 敵クラス
 */
class Enemy : public Character
{

};

#endif // !CHARCTER_H_
