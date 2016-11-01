#include "StandartTransducerManager.h"

namespace PassportTable
{
	StandartTransducerManager::~StandartTransducerManager()
	{
		
		for (stMap::iterator it = m_data.begin(); it != m_data.end(); ++it)
		{
			delete it->second;
		}
		m_data.clear();
	}

	// ��������� ��������������� �� ���������
	PassportTable::StandartTransducer* StandartTransducerManager::Get(std::string preview)
	{
		for (stMap::iterator findIt = m_data.begin(); findIt != m_data.end(); ++findIt)
		{
			if (findIt->first == preview)
			{
				return findIt->second;
			}
		}
		return nullptr;
	}

	// TODO: ���������
	std::string StandartTransducerManager::Insert(StandartTransducer * st)
	{
		unsigned int frequency = 0;
		std::string preview = st->name;
		for (stMap::iterator it = m_data.begin(); it != m_data.end(); ++it)
		{
			if (it->first.find(preview) != std::string::npos)
			{
				frequency++;
			}
		}
		if (frequency > 0)
		{
			//preview += " (" + std::string(frequency) + ")";
			std::cout << std::to_string(frequency) << std::endl;
		}
		
		m_data.insert(std::pair<std::string, StandartTransducer*>(preview, st));

		return preview;
	}

	// ���������� ������ ����
	void StandartTransducerManager::Insert(std::string preview, StandartTransducer* st)
	{
		m_data.insert(std::pair<std::string, StandartTransducer*>(preview, st));
	}

	// �������� �� �����
	bool StandartTransducerManager::Remove(std::string preview)
	{
		for (stMap::iterator iter = m_data.begin(); iter != m_data.end(); ++iter)
		{
			if (iter->first == preview)
			{
				delete iter->second;
				m_data.erase(preview);
				return true;
			}
		}
		std::cerr << "specified element was not found" << std::endl;
		return false;
	}

	// �������� �� ���������
	bool StandartTransducerManager::Remove(StandartTransducer* st)
	{
		for (stMap::iterator iter = m_data.begin(); iter != m_data.end(); ++iter)
		{
			if (iter->second == st)
			{
				delete iter->second;
				m_data.erase(iter);
				return true;
			}
		}
		std::cerr << "specified element was not found" << std::endl;
		return false;
	}

	bool StandartTransducerManager::UpdatePreview(std::string oldPreview, std::string newPeview)
	{
		const stMap::iterator it = m_data.find(oldPreview);
		if (it != m_data.end())
		{
			// Swap value from oldKey to newKey, note that a default constructed value 
			// is created by operator[] if 'm' does not contain newKey.
			std::swap(m_data[newPeview], it->second);
			// Erase old key-value from map
			m_data.erase(it);
		}

		return false;
	}
	
	// �������� �� �����
	// TODO: �������� ��������
	void StandartTransducerManager::Load(std::string path)
	{
		std::ifstream ifs("alice.json");
		Json::Reader reader;
		Json::Value obj;
		reader.parse(ifs, obj); // reader can also read strings
		std::cout << "Book: " << obj["book"].asString() << std::endl;
		std::cout << "Year: " << obj["year"].asUInt() << std::endl;
		const Json::Value& characters = obj["characters"]; // array of characters
		for (int i = 0; i < characters.size(); i++)
		{
			std::cout << "    name: " << characters[i]["name"].asString();
			std::cout << " chapter: " << characters[i]["chapter"].asUInt();
			std::cout << std::endl;
		}

		TransducerType tt = TransducerType::Direct;

		StandartTransducer* st = new StandartTransducer(/*TODO: �������� ���������� ������*/);
		this->Insert(st);
	}

	// ���������� �������� � ����
	void StandartTransducerManager::Save(std::string path)
	{
		Json::Value root;

		// TODO: ������� ������ �� ����� � ���������� �������
		for (stMap::iterator iter = m_data.begin(); iter != m_data.end(); ++iter)
		{
			std::string preview = iter->first;
			StandartTransducer* st = iter->second;

			root[preview]["name"] = st->name;
			root[preview]["lemght"] = st->dimensionsX;
		}

		std::cout << root << "\n";

		return;
	}

	// ��������� ��� ���� ����������������
	void StandartTransducerManager::FullInfo()
	{
		for (stMap::iterator it = m_data.begin(), stop = m_data.end(); it != stop; ++it)
		{
			TransducerInfo(it->second);
		}
	}

	// ���������� �� ����������� ���������������
	void StandartTransducerManager::TransducerInfo(StandartTransducer* st)
	{
		std::cout << "������ �� ��� X: " << st->dimensionsX << std::endl;
		std::cout << "������ �� ��� Y: " << st->dimensionsY << std::endl;
		std::cout << "������ �� ��� Z: " << st->dimensionsZ << std::endl;
		std::cout << "������ �� �����: " << st->dimension_port << std::endl;
		std::cout << "�������: " << st->capacity << std::endl;
	}
}