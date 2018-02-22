#ifndef TABLEDOCKWIDGETBACKEND_H
#define TABLEDOCKWIDGETBACKEND_H
#include "stable.h"
#include "classifier.h"
#include "PeakGroup.h"

using namespace std;

class TableDockWidgetBackend{
public:
    TableDockWidgetBackend();
    TableDockWidgetBackend(const TableDockWidgetBackend& tableDockWidgetBackend);
    TableDockWidgetBackend& operator = (const TableDockWidgetBackend& tableDockWidgetBackend);
    ~TableDockWidgetBackend();

    void saveModel(Classifier* clsf, QString fileName,QList<PeakGroup>&allgroups );
};


#endif