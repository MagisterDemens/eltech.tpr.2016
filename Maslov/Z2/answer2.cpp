#include "answer2.h"

Answer2::Answer2(double _usefuleness, QString _decision, QObject *parent)
{
    this->usefulness = _usefuleness;
    this->decision = _decision;
}

double Answer2::getUsefulness() const
{
    return usefulness;
}

void Answer2::setUsefulness(double value)
{
    usefulness = value;
}

QString Answer2::getDecision() const
{
    return decision;
}

void Answer2::setDecision(const QString &value)
{
    decision = value;
}
