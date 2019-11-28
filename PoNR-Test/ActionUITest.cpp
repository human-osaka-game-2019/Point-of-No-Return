#include "pch.h"

#include "../Point-of-No-Return/UI/ActionUI/ActionUI.h"

using namespace ActionUI;

float ゲージを減らす関数(const Status& status, Size size)
{
	float drow_size = (size.width.value / 100.0f) * static_cast<float>(status.hp.value);

	float update_tu =  drow_size / size.width.value;

	return update_tu;
}

TEST(ActionUITest,Test_1) {
	
	Status status =
	{
		HP(100),
		MP(20),
		IP(100),
		Attack(2),
		Defense(10),
		Speed(20),
		MagicAttack(70)

	};

	Size size =
	{
		Width(512.0f),
		Height(128.0f)

	};

	float a = ゲージを減らす関数(status, size);

	float b = ((512.0f / 100.0f) * 100.0f) / 512.0f;

	EXPECT_EQ(a ,b);
}


TEST(ActionUITest, Test_2) {

	Status status =
	{
		HP(70),
		MP(20),
		IP(100),
		Attack(2),
		Defense(10),
		Speed(20),
		MagicAttack(70)

	};

	Size size =
	{
		Width(512.0f),
		Height(128.0f)

	};

	float a = ゲージを減らす関数(status, size);

	float b = ((512.0f / 100.0f) * 70.0f) / 512.0f;

	EXPECT_EQ(a, b);
}









