#ifndef COMPANY_H
#define COMPANY_H

#include <string>

class Company {
private:
    std::string name;
    std::string position;

public:
    Company(const std::string& name, const std::string& position);
    std::string getName() const;
    std::string getPosition() const;
};

#endif // COMPANY_H
