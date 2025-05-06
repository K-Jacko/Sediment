#include "factory/SCFFactory.h"

nlohmann::json SCFFactory::loadJSONFromFile(const std::string& path)
{
    if (path.empty())
    {
        std::cout << "File Path is empty" << std::endl;
    }

    if (!std::filesystem::exists(path))
    {
        std::cout << "File does not exist at path:" << path << std::endl;
        return nullptr;
    }

    std::ifstream file(path);
    if (!file)
    {
        std::cout << "File is empty: " << path << std::endl;
        return nullptr;
    }

    try
    {
        nlohmann::json jsonData;
        std::stringstream buffer;
        buffer << file.rdbuf();
        jsonData = nlohmann::json::parse(buffer.str());
        return jsonData;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error parsing JSON" << e.what() << std::endl;
    }
    std::cout << "Loading SCF from local path" << std::endl;
}

bool SCFFactory::loadJSONFromRemote()
{
    //TODO: This will ping my api and get back a remotely stored SCF. Make sure the PayloadData includes an APPID
}

SCF* SCFFactory::createSCF(const std::string& path)
{
    // Check if path is url or folder path
    // if path, loadJSONFromFile else loadFromRemote
    nlohmann::json scfJson = loadJSONFromFile(path);
    if (scfJson != nullptr)
    {
        auto scf = new SCF();
        scf->fromJson(scfJson);
        if (scf->isValid())
        {
            return scf;
        }
        return nullptr;
    }

};

