#pragma once
#include <interface/IManager.h>
#include <cpprest/json.h>
#include <object/SCF.h>

class DataManager : public IManager
{
public:
	DataManager();
	~DataManager() override;
	static DataManager& Instance();
	void Initialize() override;
	void loadFromFile(const std::string& filePath);
	void loadFromHTTP(const std::string& url);
	const web::json::value& getData();
private:
	SCF _local_SCF;
	SCF _volatile_SCF;
	SCF _persistent_SCF;
};