#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

/*
 자료구조및알고리즘 중간대체과제
 이름: 임수빈
 학번: 201814224
 프로그램 작성일: 2021-05-02
 */

void StackInit(Stack * pstack)
{
    pstack->topIndex = -1;
}

int SIsEmpty(Stack * pstack)
{
    if(pstack->topIndex == -1)
        return TRUE;
    else
        return FALSE;
}

void SPush(Stack * pstack, Data data)
{
    pstack->topIndex += 1;
    pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack * pstack)
{
    int rIdx;

    if(SIsEmpty(pstack))
    {
        printf("Stack Memory Error!");
        exit(-1);
    }

    rIdx = pstack->topIndex;
    pstack->topIndex -= 1;

    return pstack->stackArr[rIdx];
}

Data SPeek(Stack * pstack)
{
    if(SIsEmpty(pstack))
    {
        printf("Stack Memory Error!");
        exit(-1);
    }

    return pstack->stackArr[pstack->topIndex];
}
