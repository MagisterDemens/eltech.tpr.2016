#ifndef ALTERNATIVE2_H
#define ALTERNATIVE2_H

#include <QObject>

class Alternative2 : public QObject
{
    Q_OBJECT
    QString decision;
    double probability;
    double valuation;
public:
    Alternative2(QString _decision, double _probability, double _valuation, QObject *parent = 0);

    double getProbability() const;
    void setProbability(double value);
    bool isProbabilityValid() const;

    double getValuation() const;
    void setValuation(double value);

    QString getDecision() const;
    void setDecision(const QString &value);

signals:

public slots:
};

#endif // ALTERNATIVE_H
