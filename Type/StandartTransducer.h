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
		Slanted = 0,	// ��������� �����������
		Direct = 1,		// ������ �����������
		Duals = 2		// ������ ���������-�����������
	};

	// TODO: ������������ float � ���������(float to int)
	// ��������� ����������� ���������� ����������������
	struct StandartTransducer
	{
		TransducerType type;		// ���
		std::string name;			// ��������
		int16_t	dimensionsX;		// �����
		int16_t	dimensionsY;		// ������
		int16_t	dimensionsZ;		// ������
		int16_t	dimension_port;		// ���������� �� �����
		int16_t	dimensionPiezo;		// ������ �������������
		int16_t	dimensionsWorkX;	// ����� ������� �����������
		int16_t	dimensionsWorkY;	// ������ ������� �����������
		int16_t	mass;				// �����
		//char	connectorType[32];	// ��� ����������
		std::string connectorType;	// ��� ����������
		int16_t	capacity;			// ������� �������������
		int16_t	capacityError;		// ����������� �������
		int16_t	electricalDamper;	// ?
		bool	matchingInductance;	// ����������� ������������� ?
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

	// ��������� ���������� �������� ��������������� (������ Transducer parameters introduced by User)
	//struct MeasuredTransducer
	//{
	//	StandartTransducer* st;		// ����������� ��������������
	//	int		serialNumber;		// �������� �����
	//	float	nominalAngle;		// ����������� ���� �����
	//	float	nominalFrequency;	// ����������� �������
	//	float	length;				// �����
	//	float	width;				// ������
	//	float	height;				// ������
	//	float	port;				// ���������� �� �����
	//	//null_ampl null_level;	// ������� �������
	//};

}
