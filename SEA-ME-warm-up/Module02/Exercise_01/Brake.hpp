#pragma Brake

#include "Part.hpp"

using namespace std;

class Brake : public Part{
	public:
		Brake();
		~Brake();

		void print() override;
};