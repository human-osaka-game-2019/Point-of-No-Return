#include"../ActionUI/ActionUI.h"

namespace ActionUI
{
	float StatusUI::ゲージを減らす関数(const Status& status,Size size)
	{
		float drow_size = (size.width.value / 100) * status.hp.value;
		
		float update_tu = size.width.value / drow_size;

		return update_tu;
	}
}
