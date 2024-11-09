#pragma Transmission

#include "Part.hpp"

using namespace std;

class Transmission : public Part{
	public:
		Transmission();
		~Transmission();

		void print() override;
};