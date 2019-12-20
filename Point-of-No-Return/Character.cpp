#include "Character.h"

#include <vector>

#include "Mapchip.h"

void Character::HpChanged(const HP& hp)
{
	std::vector<IHpObserver*>::iterator it;
	for (it = hpObservers.begin(); it != hpObservers.end(); it++)
	{
		(*it)->OnHpChanged(hp);
	}
}

void Character::AddHpChangeObserver(IHpObserver* HpObserver)
{
	hpObservers.push_back(HpObserver);
}

void Character::MpChanged(const MP& mp)
{
	std::vector<IMpObserver*>::iterator it;
	for (it = mpObservers.begin(); it != mpObservers.end(); it++)
	{
		(*it)->OnMpChanged(mp);
	}
}

void Character::AddMpChangeObserver(IMpObserver* MpObserver)
{
	mpObservers.push_back(MpObserver);
}

void Character::IpChanged(const IP& ip)
{
	std::vector<IIpObserver*>::iterator it;
	for (it = ipObservers.begin(); it != ipObservers.end(); it++)
	{
		(*it)->OnIpChanged(ip);
	}
}

void Character::AddIpChangeObserver(IIpObserver* IpObserver)
{
	ipObservers.push_back(IpObserver);
}

void Character::GoldChanged(const Gold& gold)
{
	std::vector<IGoldObserver*>::iterator it;
	for (it = goldObservers.begin(); it != goldObservers.end(); it++)
	{
		(*it)->OnGoldChanged(gold);
	}
}

void Character::AddGoldChangeObserver(IGoldObserver* GoldObserver)
{
	goldObservers.push_back(GoldObserver);
}
