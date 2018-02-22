#ifndef TABLEDOCKWIDGETBACKEND_H
#define TABLEDOCKWIDGETBACKEND_H
#include "stable.h"
#include "classifier.h"
#include "PeakGroup.h"

using namespace std;

class TableDockWidgetBackend{
    Q_OBJECT
public:
    TableDockWidgetBackend();
    TableDockWidgetBackend(const TableDockWidgetBackend& tableDockWidgetBackend);
    TableDockWidgetBackend& operator = (const TableDockWidgetBackend& tableDockWidgetBackend);
    ~TableDockWidgetBackend();

    void saveModel(Classifier* clsf, QString fileName,const QList<PeakGroup>&allgroups );
    QString groupsStatus(const QList<PeakGroup>&allgroups);
};


#endif