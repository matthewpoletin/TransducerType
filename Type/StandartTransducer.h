#pragma once

#include <stdint.h>
//#include "ApiPicoScope.h"	// for enps5000arange

#include <string>

//typedef enum enPS5000ARange
//{
//	PS5000A_10MV,
//	PS5000A_20MV,
//	PS5000A_50MV,
//	PS5000A_100MV,
//	PS5000A_200MV,
//	PS5000A_500MV,
//	PS5000A_1V,
//	PS5000A_2V,
//	PS5000A_5V,
//	PS5000A_10V,
//	PS5000A_20V,
//	PS5000A_50V,
//	PS5000A_MAX_RANGES
//} PS5000A_RANGE;


namespace PassportTable
{
	enum TransducerType
	{
		Slanted = 0,	// Наклонный совмещённый
		Direct = 1,		// Прямой совмещённый
		Duals = 2		// Прямой раздельно-совмещённый
	};

	// TODO: Использовать float в значениях(float to int)
	// Структура стандартных параметров преобразователей
	struct StandartTransducer
	{
		TransducerType type;		// тип
		std::string name;			// название
		int16_t	dimensionsX;		// длина
		int16_t	dimensionsY;		// ширина
		int16_t	dimensionsZ;		// высота
		int16_t	dimension_port;		// расстояние до порта
		int16_t	dimensionPiezo;		// размер пьезоэлемента
		int16_t	dimensionsWorkX;	// длина рабочей поверхности
		int16_t	dimensionsWorkY;	// ширина рабочей поверхности
		int16_t	mass;				// масса
		//char	connectorType[32];	// тип коннектора
		std::string connectorType;	// тип коннектора
		int16_t	capacity;			// емкость пьезоэлемента
		int16_t	capacityError;		// погрешность емкости
		int16_t	electricalDamper;	// ?
		bool	matchingInductance;	// согласующая индуктивность ?
		//float	impulse_amplitude;	// 
		//enPS5000ARange amplitude_range; // Add library

		StandartTransducer()
		{
			type = TransducerType::Slanted;
			dimensionsX = 0;
			dimensionsY = 0;
			dimensionsZ = 0;
			dimension_port = 0;

		}

		StandartTransducer(TransducerType type, std::string name, int16_t sizeX, int16_t sizeY, int16_t sizeZ, int16_t sizePort) :
			type(type),
			name(name),
			dimensionsX(sizeX),
			dimensionsY(sizeY),
			dimensionsZ(sizeZ),
			dimension_port(sizePort)
		{}

		~StandartTransducer() {}
	};

	//int copyTransducer(StandartTransducer* receiver, StandartTransducer* source);

	// Структура измеренных значений преобразователя (вместо Transducer parameters introduced by User)
	//struct MeasuredTransducer
	//{
	//	StandartTransducer* st;		// стандартные характеристики
	//	int		serialNumber;		// серийный номер
	//	float	nominalAngle;		// номинальный угол ввода
	//	float	nominalFrequency;	// номинальная частота
	//	float	length;				// длина
	//	float	width;				// ширина
	//	float	height;				// высота
	//	float	port;				// расстояние до порта
	//	//null_ampl null_level;	// нулевой уровень
	//};

}
