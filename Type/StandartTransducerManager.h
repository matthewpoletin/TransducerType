#pragma once

#include <iostream>
#include <fstream>

#include <map>
#include <string>

#include "StandartTransducer.h"

#include "jsoncpp/json/json.h"

namespace PassportTable
{
	typedef std::map<std::string, StandartTransducer*> stMap;

	class StandartTransducerManager
	{
	public:
		StandartTransducerManager() {}
		~StandartTransducerManager();

	private:
		stMap m_data;

	public:
		StandartTransducer* Get(std::string preview);
		std::string Insert(StandartTransducer* st);
		void Insert(std::string preview, StandartTransducer* st);
		bool Remove(std::string preview);
		bool Remove(StandartTransducer* st);
		bool UpdatePreview(std::string oldPreview, std::string newPeview);

	public:
		void Load(std::string path);
		void Save(std::string path);

	public:
		void FullInfo();
		void TransducerInfo(StandartTransducer* st);

	};

}
