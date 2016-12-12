#include <iostream>

int ** mem(size_t N, size_t M) {
	int **A = (int **)malloc(N * sizeof(int *));
	for (int i = 0; i < N; i++) {
		A[i] = (int *)malloc(M * sizeof(int));
	}
	return A;
}

void enter(int **A, size_t N, size_t M) {
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
		{
			std::cin >> A[i][j];
		}
}

int ** s(int **A, int **B, size_t N, size_t M) {
	int **C = mem(N, M);
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	return C;
}

void print(int **A, size_t N, size_t M)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
		{
			std::cout << A[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	size_t h, w;
	std::cin >> h >> w;
	int **A = mem(h, w);
	enter(A, h, w);
	int **B = mem(h, w);
	enter(B, h, w);
	int **C = s(A, B, h, w);
	print(C, h, w);
	return 0;
}