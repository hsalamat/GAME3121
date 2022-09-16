//The strongly - typed enumerations have to follow stronger rules :

//The enumerators can only be accessed in the scope of the enumeration.
//The enumerators don't implicitly convert to int.
//The enumerators aren't imported in the enclosing scope.
//The type of the enumerators is by default int.Therefore, you can forward the enumeration.

//old enum syntax: enum Color
//strongly typed enumeration: enum class|struct Color

#include <iostream>

enum OldEnum {
	one = 1,
	ten = 10,
	hundred = 100,
	thousand = 1000
};

enum struct NewEnum {
	one = 1,
	ten = 10,
	hundred = 100,
	thousand = 1000
};

int main() {

	std::cout << std::endl;

	std::cout << "C++11= " << 2 * thousand + 0 * hundred + 1 * ten + 1 * one << std::endl;
	std::cout << "C++11= " << 2 * static_cast<int>(NewEnum::thousand) +
		0 * static_cast<int>(NewEnum::hundred) +
		1 * static_cast<int>(NewEnum::ten) +
		1 * static_cast<int>(NewEnum::one) << std::endl;

}