#pragma once

#ifdef AICORE_EXPORTS
#define AICORE_API __declspec(dllexport) 
#else
#define AICORE_API __declspec(dllimport) 
#endif

#include <iostream>
#include <cassert>

const int CellsX = 7;
const int CellsY = 6;

const int RedWin = 10000000;
const int BlackWin = -10000000;

const int Red = 1;
const int Black = -1;

