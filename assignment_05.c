#include <stdio.h>
#include <math.h>

#define MAX 10

int rows, cols;

void input_matrix(int mat[MAX][MAX], char name[]);
void print_matrix(int mat[MAX][MAX]);
void add_matrices(int a[MAX][MAX], int b[MAX][MAX]);
void saddle_point(int mat[MAX][MAX]);
float determinant(float mat[MAX][MAX], int n);
void inverse_matrix(int mat[MAX][MAX]);
void magic_square(int mat[MAX][MAX]);

int main(void)
{
    int a[MAX][MAX], b[MAX][MAX];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    input_matrix(a, "Matrix A");
    input_matrix(b, "Matrix B");

    int choice;
    do
    {
        printf("\nMatrix Operations Menu\n");
        printf("1. Addition\n");
        printf("2. Saddle Point\n");
        printf("3. Inverse\n");
        printf("4. Magic Square Check\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                add_matrices(a, b);
                break;
            case 2:
                saddle_point(a);
                break;
            case 3:
                inverse_matrix(a);
                break;
            case 4:
                magic_square(a);
                break;
            case 0:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    while (choice != 0);

    return 0;
}

void input_matrix(int mat[MAX][MAX], char name[])
{
    printf("Enter elements of %s (%dx%d):\n", name, rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void print_matrix(int mat[MAX][MAX])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%6d", mat[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(int a[MAX][MAX], int b[MAX][MAX])
{
    if (rows != cols)
    {
        printf("Matrices must have same dimensions for addition.\n");
        return;
    }

    int result[MAX][MAX];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("\nResultant Matrix (A + B):\n");
    print_matrix(result);
}

void saddle_point(int mat[MAX][MAX])
{
    int found = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            int min = mat[i][0];
            for (int k = 0; k < cols; k++)
            {
                if (mat[i][k] < min)
                {
                    min = mat[i][k];
                }
            }

            if (mat[i][j] == min)
            {
                int max = mat[0][j];
                for (int k = 0; k < rows; k++)
                {
                    if (mat[k][j] > max)
                    {
                        max = mat[k][j];
                    }
                }

                if (mat[i][j] == max)
                {
                    printf("\nSaddle point found at [%d][%d] = %d\n", i, j, mat[i][j]);
                    found = 1;
                }
            }
        }
    }

    if (!found)
    {
        printf("\nNo saddle point found.\n");
    }
}

float determinant(float mat[MAX][MAX], int n)
{
    if (n == 1)
    {
        return mat[0][0];
    }

    float det = 0;
    float submat[MAX][MAX];

    for (int x = 0; x < n; x++)
    {
        int subi = 0;
        for (int i = 1; i < n; i++)
        {
            int subj = 0;
            for (int j = 0; j < n; j++)
            {
                if (j == x)
                {
                    continue;
                }
                submat[subi][subj] = mat[i][j];
                subj++;
            }
            subi++;
        }
        det += (x % 2 == 0 ? 1 : -1) * mat[0][x] * determinant(submat, n - 1);
    }

    return det;
}

void inverse_matrix(int mat[MAX][MAX])
{
    if (rows != cols)
    {
        printf("Matrix must be square for inverse.\n");
        return;
    }

    int n = rows;
    float fmat[MAX][MAX], aug[MAX][2 * MAX];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fmat[i][j] = mat[i][j];
        }
    }

    float det = determinant(fmat, n);
    if (det == 0)
    {
        printf("Matrix is singular. Inverse does not exist.\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            aug[i][j] = fmat[i][j];
            aug[i][j + n] = (i == j) ? 1.0 : 0.0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        float pivot = aug[i][i];
        for (int j = 0; j < 2 * n; j++)
        {
            aug[i][j] /= pivot;
        }

        for (int k = 0; k < n; k++)
        {
            if (k != i)
            {
                float factor = aug[k][i];
                for (int j = 0; j < 2 * n; j++)
                {
                    aug[k][j] -= factor * aug[i][j];
                }
            }
        }
    }

    printf("\nInverse Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%8.3f", aug[i][j + n]);
        }
        printf("\n");
    }
}

void magic_square(int mat[MAX][MAX])
{
    if (rows != cols)
    {
        printf("Matrix must be square to check magic square.\n");
        return;
    }

    int n = rows;
    int target = 0;

    for (int j = 0; j < n; j++)
    {
        target += mat[0][j];
    }

    int is_magic = 1;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += mat[i][j];
        }
        if (sum != target)
        {
            is_magic = 0;
        }
    }

    for (int j = 0; j < n; j++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += mat[i][j];
        }
        if (sum != target)
        {
            is_magic = 0;
        }
    }

    int diag1 = 0;
    for (int i = 0; i < n; i++)
    {
        diag1 += mat[i][i];
    }
    if (diag1 != target)
    {
        is_magic = 0;
    }

    int diag2 = 0;
    for (int i = 0; i < n; i++)
    {
        diag2 += mat[i][n - 1 - i];
    }
    if (diag2 != target)
    {
        is_magic = 0;
    }

    if (is_magic)
    {
        printf("\nThe matrix IS a Magic Square. Sum = %d\n", target);
    }
    else
    {
        printf("\nThe matrix is NOT a Magic Square.\n");
    }
}
