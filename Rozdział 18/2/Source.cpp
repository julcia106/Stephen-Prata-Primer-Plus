#include "pch.h"
#include "Cpmv.h"

int main () {

	Cpmv one (" Julia ", " Rutkowska ");
	Cpmv two (" lubi ", " konie ");
	one.Display ();
	two.Display ();
	std::cout << "\n";

	Cpmv three;
	three = one;
	three.Display ();
	std::cout << "\n";

	Cpmv four;
	four= one+ two;
	four.Display ();
	std::cout << "\n";

	Cpmv five(one + two);
	five.Display ();
	std::cout << "\n";

	Cpmv six = one + one;
	six.Display ();
	std::cout << "\n";

	std::cout << "Gotowe.\n";
	return 0;
}