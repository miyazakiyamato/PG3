#pragma once
#include "IShape.h"

class Rectangle : public IShape {
public:
	Rectangle(float size);

	void Size() override;
	void Draw() override;
};

