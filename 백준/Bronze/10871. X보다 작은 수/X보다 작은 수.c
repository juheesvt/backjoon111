#include <stdio.h>

int main() {

	
	int a, b =0;	
	scanf("%d %d", &a, &b);

	int list[10000];

	for (int i = 0; i < a; i++) {
		scanf("%d", &list[i]);
	
	}
	


	for (int j = 0; j < a; j++) {
		if (list[j] < b)
			printf("%d ", list[j]);
	}



	return 0;
}