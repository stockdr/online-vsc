#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

int main()
{
    int numOfMatrix = 0;
    printf("행렬의 크기 n 값을 입력하세요 : ");
    scanf("%d", &numOfMatrix);
    printf("%d x %d 행렬\n", numOfMatrix, numOfMatrix);

    srand(time(NULL));                                            // rand의 seed값 변경
    int* mat = (int*)malloc(sizeof(int)*numOfMatrix*numOfMatrix); // n*n 배열 생성
    int* sum = (int*)malloc(sizeof(int)*numOfMatrix*2+2);         // 행,열,대각선 합 저장용

    for (int i = 0; i < numOfMatrix*numOfMatrix; ++i) {
        mat[i] = rand() % 1000;

        if (i % numOfMatrix == 0) {
            printf("\n");
            printf("%7d ", mat[i]);
        }
        else
            printf("%7d ", mat[i]);
    }

    // sum에 값 넣기
    int rowSum = 0, colSum = 0;
    for (int i = 0; i < numOfMatrix; ++i)
    {
        for (int j = 0; j < numOfMatrix; ++j)
        {
            rowSum += mat[numOfMatrix * i + j];
            colSum += mat[i + numOfMatrix * j];
        }
        sum[i] = rowSum;
        sum[numOfMatrix + i] = colSum;
        rowSum = 0;
        colSum = 0;
    }
    for (int i = numOfMatrix*numOfMatrix - 1; i >= 0; i -= numOfMatrix + 1)
    {
        sum[numOfMatrix*2] += mat[i];
    }
    for (int i = numOfMatrix - 1; i < numOfMatrix*(numOfMatrix-1); i *= (numOfMatrix-1))
    {
        
    }

    // 행렬 크기 10보다 작으면 행렬값 출력
    if (numOfMatrix < 10) {
        for (int i = 0; i < numOfMatrix*numOfMatrix; ++i) {
            if (i % numOfMatrix == 0) {
                printf("\n");
                printf("%7d ", mat[i]);
            }
            else
                printf("%7d ", mat[i]);
        }
    }
    
    
}
