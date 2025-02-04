#include <stdio.h>
#include "Cat.h"
#include "Dog.h"


int main(){
	Animal* animal[2];

	for (int i = 0; i < 2; i++) {
		if (i < 1) {
			animal[i] = new Cat;
		}
		else {
			animal[i] = new Dog;
		}
	}

	for (int i = 0; i < 2; i++) {
		animal[i]->Cry();
	}

	for (int i = 0; i < 2; i++) {
		delete animal[i];
	}

	return 0;
}
