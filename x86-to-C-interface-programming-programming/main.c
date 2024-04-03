#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void initialize_vector(float* vec, int n) {
	int i;
	for (i = 0; i < n; i++) {
		vec[i] = (float)rand() / (float)(RAND_MAX / 100);
	}
}

float dot_product_c(float* a, float* b, int n) {
	float sum = 0.0;
	int i;
	for (i = 0; i < n; i++) {
		sum += a[i] * b[i];
	}
	return sum;
}

void sanity_check(float sdot, float sdot_c) {
	if (sdot == sdot_c) {
		printf("Correct!\n");
	}
	else {
		printf("Incorrect!\n");
	}
}

extern float dot_product_asm(float* a, float* b, int n);
// extern void asmhello();
int main() {
	clock_t start_asm, end_asm, start_c, end_c;
	double time_taken_asm, total_time_asm = 0, average_time_asm, time_taken_c, average_time_c, total_time_c = 0;
	int n, input_size;
	int cnt;

	printf("Size (20, 24, 30): ");
	scanf_s("%d", &input_size);
	n = 1 << input_size;

	for (cnt = 0; cnt < 30; cnt++) {

		float* a = (float*)malloc(n * sizeof(float));
		float* b = (float*)malloc(n * sizeof(float));
		initialize_vector(a, n);
		initialize_vector(b, n);

		float sdot = 0.0;
		float sdot_c = 0.0;

		start_asm = clock();
		sdot = dot_product_asm(a, b, n);
		end_asm = clock();
		time_taken_asm = ((double)(end_asm - start_asm)) / CLOCKS_PER_SEC;

		start_c = clock();
		sdot_c = dot_product_c(a, b, n);
		end_c = clock();
		time_taken_c = ((double)(end_c - start_c)) / CLOCKS_PER_SEC;

		printf("[%d]\nAssembly Dot product:\n %f\n", cnt + 1, sdot);
		printf("C Dot product:\n %f\n\n", sdot_c);
		sanity_check(sdot, sdot_c);

		printf("Time taken for Assembly kernel: %f seconds.\n\n", time_taken_asm);
		printf("Time taken for C kernel: %f seconds.\n\n", time_taken_c);
		total_time_asm += time_taken_asm;
		total_time_c += time_taken_c;

		free(a);
		free(b);

	}
	average_time_asm = total_time_asm / 30;
	average_time_c = total_time_c / 30;
	printf("|---------------------------------------------------------------------|");
	printf("\nAverage time for assembly kernel: %f seconds.\n", average_time_asm);
	printf("\nAverage time for C kernel: %f seconds.\n", average_time_c);

	return 0;
}