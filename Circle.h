#pragma once
#include "IShape.h"

class Circle : public IShape{
public:
	Circle(float size);

	void Size() override;
	void Draw() override;
};

