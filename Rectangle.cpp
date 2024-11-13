#include "Rectangle.h"

Rectangle::Rectangle(float size){
	size_ = size;
}

void Rectangle::Size(){
	printf("‹éŒ`‚Ì–ÊÏ‚Í%f\n", size_ * size_);
}

void Rectangle::Draw(){
	printf("‹éŒ`‚Ì•`‰æ\n");
}
