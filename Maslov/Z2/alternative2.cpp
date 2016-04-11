#include "alternative2.h"

double Alternative2::getProbability() const
{
    return probability;
}

void Alternative2::setProbability(double value)
{
    probability = value;
}

bool Alternative2::isProbabilityValid() const
{
    return (this->getProbability() <= 1 && this->getProbability()>=0);
}

double Alternative2::getValuation() const
{
    return valuation;
}

void Alternative2::setValuation(double value)
{
    valuation = value;
}

QString Alternative2::getDecision() const
{
    return decision;
}

void Alternative2::setDecision(const QString &value)
{
    decision = value;
}

Alternative2::Alternative2(QString _substance, double _probability, double _valuation, QObject *parent)
{
    this->decision = _substance;
    this->probability = _probability;
    this->valuation = _valuation;
}
