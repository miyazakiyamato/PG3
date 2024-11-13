#include "Rectangle.h"

Rectangle::Rectangle(float size){
	size_ = size;
}

void Rectangle::Size(){
	printf("矩形のサイズは%f\n", size_);
}

void Rectangle::Draw(){
	printf("矩形の描画\n");
}
