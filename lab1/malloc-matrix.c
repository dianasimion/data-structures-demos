#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "utils.h"

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int **mat = malloc(n * sizeof(*mat));
	DIE(mat == NULL, "malloc mat failed\n");

	for (int i = 0; i < n; i++) {
		mat[i] = malloc(m * sizeof(*mat[i]));
		DIE(!mat, "malloc mat[i] failed\n");
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mat[i][j] = i + j;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", mat[i][j]);
		}

		printf("\n");
	}

	// free memory - start from the deepest level and go the "start pointer"
	// that contains references to the others
	for (int i = 0; i < n; i++) {
		free(mat[i]);
	}
	free(mat);

	return 0;
}