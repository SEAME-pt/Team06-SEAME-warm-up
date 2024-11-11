#pragma once

#include "Part.hpp"

using namespace std;

class Wheel : public Part{
	public:
		Wheel();
		~Wheel();

		void print() const override;
};