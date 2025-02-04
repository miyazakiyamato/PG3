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

	//º˜a3”N‚Ì˜Hü}
	std::list<const char*> yamanoteLine{
		 "Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno","Uguisudani", "Nippori", "Tabata", "Komagome",
		 "Sugamo","Otsuka", "Ikebukuro", "Mejiro", "Takadanobaba", "Shin-Okubo","Shinjuku", "Yoyogi", "Harajuku","Shibuya",
		 "Ebisu","Meguro", "Gotanda", "Osaki", "Shinagawa", "Tamachi","Hamamatsucho", "Shimbashi", "Yurakucho"
	};
	printf("1970”N‚Ì˜Hü}\n");
	Draw(yamanoteLine);
	//º˜a47”N‚Ì˜Hü}
	SetList(yamanoteLine, "Nishi-Nippori", "Tabata");
	printf("2019”N‚Ì˜Hü}\n");
	Draw(yamanoteLine);
	//º˜a47”N‚Ì˜Hü}
	SetList(yamanoteLine, "Takanawa Gateway", "Tamachi");
	printf("2022”N‚Ì˜Hü}\n");
	Draw(yamanoteLine);

	return 0;
}
