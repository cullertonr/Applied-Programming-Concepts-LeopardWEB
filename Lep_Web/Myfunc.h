#pragma once
#include <iostream>
#include "sqlite3.h"
#include <string>
#include <stdio.h>

using namespace std;

static int callback(void* data, int argc, char** argv, char** azcolname);