#include "Character.h"

#include <vector>

#include "Mapchip.h"

void Character::HpChangeNotify(const HP& hp)
{
	std::vector<IHpObserver*>::iterator it;
	for (it = HpObservers.begin(); it != HpObservers.end(); it++)
	{
		(*it)->Update(hp);
	}
}

void Character::AddHpChangeObserver(IHpObserver* pIHpObserver)
{
	HpObservers.push_back(pIHpObserver);
}

void Character::MpChangeNotify(const MP& mp)
{
	std::vector<IMpObserver*>::iterator it;
	for (it = MpObservers.begin(); it != MpObservers.end(); it++)
	{
		(*it)->Update(mp);
	}
}

void Character::AddMpChangeObserver(IMpObserver* pMpObserver)
{
	MpObservers.push_back(pMpObserver);
}

void Character::IpChangeNotify(const IP& ip)
{
	std::vector<IIpObserver*>::iterator it;
	for (it = IpObservers.begin(); it != IpObservers.end(); it++)
	{
		(*it)->Update(ip);
	}
}

void Character::AddIpChangeObserver(IIpObserver* pIIpObserver)
{
	IpObservers.push_back(pIIpObserver);
}

void Character::GoldChangeNotify(const Gold& gold)
{
	std::vector<IGoldObserver*>::iterator it;
	for (it = GoldObservers.begin(); it != GoldObservers.end(); it++)
	{
		(*it)->Update(gold);
	}
}

void Character::AddGoldChangeObserver(IGoldObserver* pIGoldObserver)
{
	GoldObservers.push_back(pIGoldObserver);
}
