#ifndef IOBSERVER_H
#define IOBSERVER_H

#include "../Object.h"

class IHpObserver
{
public:
	virtual ~IHpObserver() {};
	virtual void OnHpChanged(const HP& hp) = 0;
};

class IMpObserver
{
public:
	virtual ~IMpObserver() {};
	virtual void OnMpChanged(const MP& mp) = 0;
};

class IIpObserver
{
public:
	virtual ~IIpObserver() {};
	virtual void OnIpChanged(const IP& ip) = 0;
};

class IGoldObserver
{
public:
	virtual ~IGoldObserver() {};
	virtual void OnGoldChanged(const Gold& gold) = 0;
};

#endif
