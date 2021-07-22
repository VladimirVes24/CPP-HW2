
#include <iostream>

/*
* Задание:
*
* 1) Создать и инициализировать переменные пройденных типов данных (short int, int, long long, char, bool, float, double).
*
* 2) Создать перечисление (enum) с возможными вариантами символов для игры в крестики-нолики.
*
* 3) Создать массив, способный содержать значения такого перечисления и инициализировать его.
*
* 4) * Создать структуру (struct) данных «Поле для игры в крестики-нолики» и снабдить его всеми
* необходимыми свойствами (подумайте что может понадобиться).
*
* 5) ** Создать структуру (struct) объединяющую: union (int, float, char) и 3-и битовых поля (флага)
* указывающими какого типа значение в данный момент содержится в объединении (isInt, isFloat, isChar).
* Продемонстрировать пример использования в коде этой структуры.
*/



//Задание №1
void Task1()
{
	short int firstVar = 32'767;
	int16_t sameFirstVar = 32'767;

	int secondVar = 2'147'483'647;
	int32_t sameSecondVar = 2'147'483'647;

	long long int thirdVar = 9'223'372'036'854'775'807;
	int64_t sameThirdVar = 9'223'372'036'854'775'807;

	char forthVar = 'A';

	bool fifthVar = false;

	float sixthVar = 143.15f;

	double seventhVar = 1567.5646846;
	
}

//Задание №2
enum Cell
{
	O,
	X,
	NONE
};

//Задание №3,4

struct ticTacToeGame {

	Cell ticTacToeGameField[3][3] = { { NONE, NONE, NONE },{ NONE, NONE, NONE },{ NONE, NONE, NONE } };
	std::string playerNames[2] = { "ALEX","JOHN" };
	int whichPlayerTurn = 0, turnCount = 1;
	bool gameComplete = false, threeMarkRow = false;
	int firstPlayerMark = O, secondPlayerMark = X;
	int Winner;

};


//Задание №5

union myVariantType
{
	int32_t integer;
	float decimal;
	char character;
};

struct MyVariant
{
	myVariantType type;
	uint16_t isInt : 1;
	uint16_t isFloat : 1;
	uint16_t isChar : 1;
};

void PrintVariantType() 
{
	MyVariant newVariant;
	newVariant.type.decimal = 3.23f;
	newVariant.isFloat = 1;
	if (newVariant.isInt == 1) std::cout << "Variant type is Integer!";
	else if (newVariant.isFloat == 1) std::cout << "Variant type is Float!";
	else if (newVariant.isChar == 1) std::cout << "Variant type is Char!";
	else std::cout << "Variant type is not defined.";
}

int main()
{
	PrintVariantType();
	return 0;
}