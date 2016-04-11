#ifndef ANSWER2_H
#define ANSWER2_H

#include <QObject>

class Answer2 : public QObject
{
    Q_OBJECT
    double usefulness;
    QString decision;
public:
    Answer2(double _usefuleness, QString _decision, QObject *parent = 0);

    double getUsefulness() const;
    void setUsefulness(double value);

    QString getDecision() const;
    void setDecision(const QString &value);

signals:

public slots:
};

#endif // ANSWER_H
