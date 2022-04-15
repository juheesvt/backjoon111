#include <stdio.h>

int main() {

	int a = 0;
	int sum = 0;
	scanf("%d", &a);

	while (a > 0) {

		if (a % 5 == 0) {
			sum += a / 5;
			break;
		}

		a -= 3;
		sum += 1;
		
		if ( a < 0 )
			sum = -1;

	}

	printf("%d", sum);

	return 0;
}