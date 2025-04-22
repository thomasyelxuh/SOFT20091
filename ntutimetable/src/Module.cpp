#include "Module.h"

// Constructor
Module::Module(std::string name, std::string code) 
    : moduleName(name), moduleCode(code) {}

// Getters
std::string Module::getModuleName() const { return moduleName; }
std::string Module::getModuleCode() const { return moduleCode; }