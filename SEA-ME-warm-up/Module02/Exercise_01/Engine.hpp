#pragma once

#include "Part.hpp"

using namespace std;

class Engine : public Part{
	public:
		Engine();
		~Engine();

		void print() const override;
};