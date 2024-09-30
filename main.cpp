#include <stdio.h>
#include <cctype>

template <typename T1, typename T2>

T1 min(T1 a, T2 b) {
	return static_cast<T1>(a < b ? a : b);
}

template <>
char min<char>(char a, char b) {
    if (isdigit(a) && isdigit(b)) {
        return a < b ? a : b;
    }
    else {
        printf("%s\n", "”šˆÈŠO‚Í‘ã“üo—ˆ‚Ü‚¹‚ñ");
        return '\0';
    }
}

int main(){
	
	printf("%d\n", min<int>(11, 12));
	printf("%f\n", min<float>(11.4f, 51.4f));
    printf("%lf\n", min<double>(31.44, 51.44));
    printf("%c\n", min<char>('3', '5'));
    printf("%c\n", min<char>('a', '5'));

	return 0;
}