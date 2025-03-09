#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

int main()
{
    int numOfMatrix = 0;
    printf("행렬의 크기 n 값을 입력하세요 : ");
    scanf("%d", &numOfMatrix);
    printf("%d x %d 행렬", numOfMatrix, numOfMatrix);

    srand(time(NULL));                                            // rand의 seed값 변경
    int* mat = (int*)malloc(sizeof(int)*numOfMatrix*numOfMatrix); // n*n 배열 생성
    int sumLength = numOfMatrix*2 + 2;
    int* sum = (int*)malloc(sizeof(int)*sumLength);         // 행,열,대각선 합 저장용
    for (int i = 0; i < sumLength; ++i)
        sum[i] = 0;
    
    for (int i = 0; i < numOfMatrix*numOfMatrix; ++i)   // 랜덤값 넣기
        mat[i] = rand() % 10;

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
    for (int i = numOfMatrix*numOfMatrix - 1; i >= 0;)
    {
        sum[sumLength - 2] += mat[i];
        i -= numOfMatrix+1;
    }
    for (int i = numOfMatrix - 1; i <= numOfMatrix*(numOfMatrix-1); i += (numOfMatrix-1))
    {
        sum[sumLength - 1] += mat[i];
    }

    // 최대값 찾기
    int maxNumOfLine = 0;
    int lineNum = 0;
    char c;
    for(int i = sumLength - 1; i >= 0; --i)
    {
        if (maxNumOfLine < sum[i]) {
            if (i >= 0 && i < numOfMatrix)
                c = 'r';
            else if (i >= numOfMatrix && i < numOfMatrix*2)
                c = 'c';
            else if (i == sumLength - 2)
                c = 'd';
            else if (i == sumLength - 1)
                c = 'u';
            
            maxNumOfLine = sum[i];
            lineNum = i + 1;
        }
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
        printf("\n");
    }

    printf("최대값은 ");
    switch(c)
    {
        case 'r': 
            printf("%d행", lineNum);
            break;
        case 'c':
            printf("%d열", lineNum);
            break;
        case 'u':
            printf("우상좌하 대각선");
            break;
        case 'd':
            printf("좌상우하 대각선");
            break;
        default:
            break;
    }
    printf("의 합 %d\n", maxNumOfLine);
}