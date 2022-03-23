
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"
#include <iostream>
namespace sdds {
	const int MAX_SIZE = 1000;
	class LblShape : public Shape {
	private:
		char* m_label{};
	protected:
		char* label()const;
	public:
		LblShape();
		LblShape(const char* label = nullptr);
		~LblShape();
		void getSpecs(std::istream& istr);

	};

}
#endif // !SDDS_LBLSHAPE_H