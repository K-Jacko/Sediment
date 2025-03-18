#include "singleton/DataManager.h"

const web::json::value& DataManager::getData()
{
	if (!_volKCF.isEmpty()) return _volKCF.getJson();
	if (!_localKCF.isEmpty()) return _localKCF.getJson();
	return _backupKCF.getJson();
}
