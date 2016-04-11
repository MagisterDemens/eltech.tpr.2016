#include "answer1.h"

Answer1::Answer1(double _usefuleness, QString _decision, QObject *parent)
{
    this->usefulness = _usefuleness;
    this->decision = _decision;
}

double Answer1::getUsefulness() const
{
    return usefulness;
}

void Answer1::setUsefulness(double value)
{
    usefulness = value;
}

QString Answer1::getDecision() const
{
    return decision;
}

void Answer1::setDecision(const QString &value)
{
    decision = value;
}
