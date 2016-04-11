#include "alternative1.h"

double Alternative1::getProbability() const
{
    return probability;
}

void Alternative1::setProbability(double value)
{
    probability = value;
}

bool Alternative1::isProbabilityValid() const
{
    return (this->getProbability() <= 1 && this->getProbability()>=0);
}

double Alternative1::getValuation() const
{
    return valuation;
}

void Alternative1::setValuation(double value)
{
    valuation = value;
}

QString Alternative1::getDecision() const
{
    return decision;
}

void Alternative1::setDecision(const QString &value)
{
    decision = value;
}

Alternative1::Alternative1(QString _substance, double _probability, double _valuation, QObject *parent)
{
    this->decision = _substance;
    this->probability = _probability;
    this->valuation = _valuation;
}
