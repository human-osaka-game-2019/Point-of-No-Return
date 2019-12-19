#ifndef CHARCTER_H_
#define CHARCTER_H_

#include "Object.h"
#include "Gravity.h"
#include "../Point-of-No-Return/Observer/IObserver.h"
#include <vector>

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

	void HpChanged(const HP& hp);

	void AddHpChangeObserver(IHpObserver* pIHpObserver);

	void MpChanged(const MP& mp);

	void AddMpChangeObserver(IMpObserver* pIMpObserver);

	void IpChanged(const IP& ip);

	void AddIpChangeObserver(IIpObserver* pIIpObserver);

	void GoldChanged(const Gold& gold);

	void AddGoldChangeObserver(IGoldObserver* pIGoldObserver);

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
	};

protected:

	// ObserverList
	std::vector<IHpObserver*> HpObservers;
	std::vector<IMpObserver*> MpObservers;
	std::vector<IIpObserver*> IpObservers;
	std::vector<IGoldObserver*> GoldObservers;

	Status status =
	{
		HP(0,0),
		MP(0,0),
		IP(0,0),
		Attack(0,0),
		Defense(0,0),
		Speed(0,0),
		MagicAttack(0,0)
	};

	Parameter parameter =
	{
		Luck(0,0),
		Love(0,0),
		Time(0,0),
		Gold(0,0),
		Age(0,0)
	};

	//! 前の座標を保存する
	Position previousPosition =
	{
		CoordinateX(0),
		CoordinateY(0)
	};

	Position offset =
	{
		CoordinateX(0),
		CoordinateY(0)
	};

	Position previousOffset =
	{
		CoordinateX(0),
		CoordinateY(0)
	};

	
	Gravity gravity{ &position };

private:

	//! キャラクターの名前
	Name name = Name("None");
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
