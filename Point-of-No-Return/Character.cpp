#include "Character.h"

#include <vector>

#include "Mapchip.h"

void Character::HpChanged(const HP& hp)
{
	std::vector<IHpObserver*>::iterator it;
	for (it = HpObservers.begin(); it != HpObservers.end(); it++)
	{
		(*it)->OnHpChanged(hp);
	}
}

void Character::AddHpChangeObserver(IHpObserver* pIHpObserver)
{
	HpObservers.push_back(pIHpObserver);
}

void Character::MpChanged(const MP& mp)
{
	std::vector<IMpObserver*>::iterator it;
	for (it = MpObservers.begin(); it != MpObservers.end(); it++)
	{
		(*it)->OnMpChanged(mp);
	}
}

void Character::AddMpChangeObserver(IMpObserver* pMpObserver)
{
	MpObservers.push_back(pMpObserver);
}

void Character::IpChanged(const IP& ip)
{
	std::vector<IIpObserver*>::iterator it;
	for (it = IpObservers.begin(); it != IpObservers.end(); it++)
	{
		(*it)->OnIpChanged(ip);
	}
}

void Character::AddIpChangeObserver(IIpObserver* pIIpObserver)
{
	IpObservers.push_back(pIIpObserver);
}

void Character::GoldChanged(const Gold& gold)
{
	std::vector<IGoldObserver*>::iterator it;
	for (it = GoldObservers.begin(); it != GoldObservers.end(); it++)
	{
		(*it)->OnGoldChanged(gold);
	}
}

void Character::AddGoldChangeObserver(IGoldObserver* pIGoldObserver)
{
	GoldObservers.push_back(pIGoldObserver);
}
