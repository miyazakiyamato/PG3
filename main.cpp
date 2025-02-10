#include <stdio.h>

template <typename Type1,typename Type2>

class Math {
public:
	Type1 num1;
	Type2 num2;

	Math(Type1 num1, Type2 num2) :num1(num1), num2(num2) {}

	Type1 Min() {
		return static_cast<Type1>(num1 < num2 ? num1 : num2);
	}
};


int main(){
	Math<int,int> b1(10, 20);
	Math<int, float> b2(10, 20.0f);
	Math<int, double> b3(10, 20.0);
	Math<float, float> b4(10.0f, 20.0f);
	Math<float, double> b5(10.0f, 20.0);
	Math<double, double> b6(10.0, 20.0);

	printf("%d\n", b1.Min());
	printf("%d\n", b2.Min());
	printf("%d\n", b3.Min());
	printf("%f\n", b4.Min());
	printf("%f\n", b5.Min());
	printf("%lf\n", b6.Min());
	
	return 0;
}