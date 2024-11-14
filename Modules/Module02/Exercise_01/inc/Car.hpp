#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <array>
#include <memory>

using namespace std;

#include "Part.hpp"
#include "Engine.hpp"
#include "Brake.hpp"
#include "Transmission.hpp"
#include "Wheel.hpp"

class Car {
	private:
		unique_ptr<Engine> engine_;
		array<Wheel, 4> wheels_;
		array<Brake, 4> brakes_;
		unique_ptr<Transmission> transmission_;
	
	public:
		Car();
		~Car() = default; // Destrutor padrão, pois usamos smart pointers

		void printParts() const;

};