#ifndef DOC_LONGTERM_H
#define DOC_LONGTERM_H
#include"doc.h"

class doc_longterm: public doc
{
	Q_OBJECT
public:
    doc_longterm();
   
    int id;
    QString tel;
    QString res;
    QVector<QString>task;

    QList<QString>choice;
    void mouseDoubleClickEvent(QMouseEvent*);

};

#endif // DOC_LONGTERM_H
