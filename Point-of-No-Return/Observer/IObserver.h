#ifndef IOBSERVER_H
#define IOBSERVER_H

#include "../Object.h"

class IHpObserver
{
public:
	virtual ~IHpObserver() {};
	virtual void Update(const HP& hp) = 0;
};

class IMpObserver
{
public:
	virtual ~IMpObserver() {};
	virtual void Update(const MP& mp) = 0;
};

class IIpObserver
{
public:
	virtual ~IIpObserver() {};
	virtual void Update(const IP& ip) = 0;
};

class IGoldObserver
{
public:
	virtual ~IGoldObserver() {};
	virtual void Update(const Gold& gold) = 0;
};

#endif
