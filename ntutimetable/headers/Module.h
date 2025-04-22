#ifndef MODULE_H
#define MODULE_H

#include <string>

class Module {
private:
    std::string moduleName;
    std::string moduleCode;

public:
    Module(std::string name, std::string code) : moduleName(name), moduleCode(code) {}

    std::string getModuleName() const { return moduleName; }
    std::string getModuleCode() const { return moduleCode; }
};

#endif