#include "Circle.h"

Circle::Circle(float size){
	size_ = size;
}

void Circle::Size(){
	printf("â~ÇÃñ êœÇÕ%f\n", size_ * size_ * 3.14f);
}

void Circle::Draw(){
	printf("â~ÇÃï`âÊ\n");
}
