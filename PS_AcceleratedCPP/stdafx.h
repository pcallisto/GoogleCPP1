// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <complex.h>
#include <cmath>

#include <algorithm>
#include <array>
#include <chrono>
#include <complex>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <random>
#include <set>
#include <string>

#include <tuple>
#include <vector>

#include "UsrLib.h"

using namespace std;

int accelCppNumerics();
int ObjectOrientedProgramming();

int algorithms();
int containers();
int streams();

int ControlFlow();
void for_loop();
void switching();

int FunctionsAndVariables();
void functions_and_vars();
void stack_and_heap();
void functions();
void lambdas();
void enums();

int MemoryManagment(int, char *);
int inc(int&);

void increm(int& x) { x++; }
inline int add(int a, int b) { return a + b; }
auto add2(int a, int b) -> int { return a + b; }
int meaningOfLife();
void move_rvalue();

int Templates();
void consuming_templates();
void template_functions();
void template_specialization();
void variadic();
void metaprogramming();

