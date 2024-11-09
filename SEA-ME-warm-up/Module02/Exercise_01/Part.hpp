#pragma Part

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <array>
#include <memory>

using namespace std;

class Part{
	public:
		Part();
		~Part();
		virtual void print() = 0;
};