#include "tabledockwidgetbackend.h"

TableDockWidgetBackend::TableDockWidgetBackend(){

}

TableDockWidgetBackend::TableDockWidgetBackend(const TableDockWidgetBackend& tableDockWidgetBackend){

}
TableDockWidgetBackend& TableDockWidgetBackend::operator = (const TableDockWidgetBackend& tableDockWidgetBackend){

    return *this;
}
TableDockWidgetBackend::~TableDockWidgetBackend(){

}

void TableDockWidgetBackend::saveModel(Classifier* clsf, QString fileName,QList<PeakGroup>&allgroups ){

    if(!clsf || fileName.isEmpty())
        return;

    if(!fileName.endsWith(".model",Qt::CaseInsensitive))
        fileName = fileName + ".model";
    clsf->saveModel(fileName.toStdString());
    
    vector<PeakGroup*>groups;
    for(int i=0 ; i < allgroups.size() ; ++i)
        if(allgroups[i].label == 'g' || allgroups[i].label == 'b' )
            groups.push_back(&allgroups[i]);

    clsf->saveFeatures(groups,fileName.toStdString() + ".csv");


}