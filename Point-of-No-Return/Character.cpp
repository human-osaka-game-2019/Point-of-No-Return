#include "Character.h"

#include <vector>

#include "Mapchip.h"

void Character::HpChangeNotify(const HP& hp)
{
	std::list<IHpObserver*>::iterator it;
	for (it = pHpList.begin(); it != pHpList.end(); it++)
	{
		(*it)->Update(hp);
	}
}

void Character::AddHpChangeObserver(IHpObserver* pIHpObserver)
{
	pHpList.push_back(pIHpObserver);
}

void Character::MpChangeNotify(const MP& mp)
{
	std::list<IMpObserver*>::iterator it;
	for (it = pMpList.begin(); it != pMpList.end(); it++)
	{
		(*it)->Update(mp);
	}
}

void Character::AddMpChangeObserver(IMpObserver* pMpObserver)
{
	pMpList.push_back(pMpObserver);
}

void Character::IpChangeNotify(const IP& ip)
{
	std::list<IIpObserver*>::iterator it;
	for (it = pIpList.begin(); it != pIpList.end(); it++)
	{
		(*it)->Update(ip);
	}
}

void Character::AddIpChangeObserver(IIpObserver* pIIpObserver)
{
	pIpList.push_back(pIIpObserver);
}

void Character::GoldChangeNotify(const Gold& gold)
{
	std::list<IGoldObserver*>::iterator it;
	for (it = pGoldList.begin(); it != pGoldList.end(); it++)
	{
		(*it)->Update(gold);
	}
}

void Character::AddIpChangeObserver(IGoldObserver* pIGoldObserver)
{
	pGoldList.push_back(pIGoldObserver);
}
