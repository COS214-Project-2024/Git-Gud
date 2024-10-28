#ifndef SATISFACTIONLEVEL_H
#define SATISFACTIONLEVEL_H

class SatisfactionLevel
{
private:
protected:
    /// @brief Percentage of tax that citizen pays
    float taxReturn;
public:
    /// @brief Returns the tax return of the satisfaction level
    /// @return float
    float getTaxReturn(){return taxReturn;};
};


#endif // SATISFACTIONLEVEL_H