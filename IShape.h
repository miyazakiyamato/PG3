#pragma once
#include "stdio.h"

class IShape{
public:

	virtual ~IShape() {};

	virtual void Size() = 0;
	virtual void Draw() = 0;

protected:
	float size_ = 0;
};

