#include <stdio.h>
#include "list"
#include "array"

void SetList(std::list<const char*>& yamanoteLine,const char* setStation,const char* nextStation) {
	for (std::list<const char*>::iterator it = yamanoteLine.begin(); it != yamanoteLine.end(); it++) {
		if (*it == nextStation) {
			it = yamanoteLine.insert(it, setStation);
			it++;
		}
	}
}

void Draw(std::list<const char*> yamanoteLine) {
	int index = 1;
	for (const char* station : yamanoteLine) {
		printf("JY%2d:", index);
		printf("%s\n", station);
		index++;
	}
	printf("\n");
}

int main(){

	//昭和3年の路線図
	std::list<const char*> yamanoteLine{
		 "Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno","Uguisudani", "Nippori", "Tabata", "Komagome",
		 "Sugamo","Otsuka", "Ikebukuro", "Mejiro", "Takadanobaba", "Shin-Okubo","Shinjuku", "Yoyogi", "Harajuku","Shibuya",
		 "Ebisu","Meguro", "Gotanda", "Osaki", "Shinagawa", "Tamachi","Hamamatsucho", "Shimbashi", "Yurakucho"
	};
	printf("1970年の路線図\n");
	Draw(yamanoteLine);
	//昭和47年の路線図
	SetList(yamanoteLine, "Nishi-Nippori", "Tabata");
	printf("2019年の路線図\n");
	Draw(yamanoteLine);
	//昭和47年の路線図
	SetList(yamanoteLine, "Takanawa Gateway", "Tamachi");
	printf("2022年の路線図\n");
	Draw(yamanoteLine);

	return 0;
}
