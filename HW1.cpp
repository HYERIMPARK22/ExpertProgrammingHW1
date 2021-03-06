//#define _CRT_SECURE_NO_WARNINGS
#include "HW1.h"
#include "pch.h"
#include <stdio.h>
#include <assert.h>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void fileOpen1(FILE *f1);
void printLine();
void printAry();
void calRecallPrecision(int ary1[][3], int ary2[][3], int size);
void printRecallPrecision();

int nAry1[VIDEOCNT][3], nAry2[VIDEOCNT][3];
string sName1[VIDEOCNT],sName2[VIDEOCNT];
char tmp[30];
double recallPrecisionOfA[VIDEOCNT][2], recallPrecisionOfB[VIDEOCNT][2];

FILE *f1;
int i, j, k;

int main()
{
	fileOpen1(f1);
	printAry();
	calRecallPrecision(nAry1,nAry2,VIDEOCNT);
	printRecallPrecision();

}

void fileOpen1(FILE *f1)
{
	fopen_s(&f1,"c:\\data\\HW1-1.txt", "r");
	assert(f1 != NULL);

	for (i = 0; i < VIDEOCNT; i++)
	{
		fscanf(f1, "%s %d %d %d", tmp, &nAry1[i][0], &nAry1[i][1], &nAry1[i][2]);
		sName1[i] = tmp;
		fscanf(f1, "%s %d %d %d", tmp, &nAry2[i][0], &nAry2[i][1], &nAry2[i][2]);
		sName2[i] = tmp;
	}

	fclose(f1);
}

void printLine()
{
	cout << "========================================\n";
}
void printAry()
{
	printLine();
	cout << "<영상의 데이터를 배열에 읽은 후 출력>\n ";
	for (i = 0; i < VIDEOCNT; i++)
	{
		cout << sName1[i] << ", ";
		for (j = 0; j < 3; j++)
			cout << nAry1[i][j] << ", ";
		cout << "\b\b   \n";
	}

	for (i = 0; i < VIDEOCNT; i++)
	{
		cout << sName2[i] << ", ";
		for (j = 0; j < 3; j++)
			cout << nAry2[i][j] << ", ";
		cout << "\b\b   \n";
	}
	printLine();
}

void calRecallPrecision(int ary1[][3], int ary2[][3], int size)
{
	int sum = 0;
	int nFeatureOriginal, nFeatureReceived, nFeatureCommon;
	
	for (i = 0; i < size; i++)
	{
		nFeatureOriginal = ary1[i][0];
		nFeatureReceived = ary1[i][1];
		nFeatureCommon = ary1[i][2];
		recallPrecisionOfA[i][0] = nFeatureCommon / nFeatureOriginal;
		recallPrecisionOfA[i][1] = nFeatureCommon / nFeatureReceived;
	}

	for (i = 0; i < size; i++)
	{
		nFeatureOriginal = ary2[i][0];
		nFeatureReceived = ary2[i][1];
		nFeatureCommon = ary2[i][2];
		recallPrecisionOfB[i][0] = nFeatureCommon / nFeatureOriginal;
		recallPrecisionOfB[i][1] = nFeatureCommon / nFeatureReceived;
	}

}

void printRecallPrecision()
{
	printLine();
	cout << "방법 A와 B의 recall 값과 precision 값 출력\n";
	printLine();
	cout << "<방법 A>\n";
	for (i = 0; i < 15; i++)
	{
		cout << sName1[i] << "영상의 recall 값 : " << recallPrecisionOfA[i][0] << " precision 값 : " << recallPrecisionOfA[i][1] << "\n";
	}

	cout << "<방법 B>\n";
	for (i = 0; i < 15; i++)
	{
		cout << sName2[i] << "영상의 recall 값 : " << recallPrecisionOfB[i][0] << " precision 값 : " << recallPrecisionOfB[i][1] << "\n";
	}

}


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
