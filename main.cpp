#include <stdio.h>
#include "Circle.h"
#include "Rectangle.h"

int main(){
	IShape* ishape[2];

	for (int i = 0; i < 2; i++) {
		if (i < 1) {
			ishape[i] = new Circle(1.0f);
		}
		else {
			ishape[i] = new Rectangle(2.0f);
		}
	}

	for (int i = 0; i < 2; i++) {
		ishape[i]->Size();
	}
	for (int i = 0; i < 2; i++) {
		ishape[i]->Draw();
	}

	for (int i = 0; i < 2; i++) {
		delete ishape[i];
	}

	return 0;
}
