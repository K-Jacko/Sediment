#pragma once
#include "interface/IFactory.h"
#include "object/SCF.h"
#include <fstream>
#include <filesystem>
#include <iostream>

class SCFFactory : public IFactory
{
    // Create SCF Objects
    // Log them
    // To ensure the application always has a valid config file we can have a standard backup SCF that sits on a server
    // Validate input data before creating JSON config objects
    // Inject dependencies or default values into config objects
    // Track creation statistics or metrics for analytics/debugging
    // Apply versioning logic to config object creation based on schema versions
    // Support loading partial configs and merging them with defaults
    // Emit events or notify observers when new config objects are created
    // Handle localization or environment-specific adjustments to config
    // Register or deregister different types of config creators dynamically
    // Provide cloning functionality for existing config objects
    // Serialize created objects to disk or a remote endpoint
    // Support rollback or undo if config creation fails midway
    // Allow mocking or stubbing of config objects for testing purposes
public:
    SCFFactory() = default;
    ~SCFFactory() override {};
    nlohmann::json loadJSONFromFile(const std::string& path);
    bool loadJSONFromRemote();
    std::unique_ptr<SCF> createSCF(const std::string& path);

private:
};
