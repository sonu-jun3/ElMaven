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

void TableDockWidgetBackend::saveModel(Classifier* clsf, QString fileName,const QList<PeakGroup>&allgroups ){

    if(!clsf || fileName.isEmpty())
        return;

    if(!fileName.endsWith(".model",Qt::CaseInsensitive))
        fileName = fileName + ".model";
    clsf->saveModel(fileName.toStdString());
    
    vector<PeakGroup*>groups;
    for(int i=0 ; i < allgroups.size() ; ++i)
        if(allgroups[i].label == 'g' || allgroups[i].label == 'b' ){
            PeakGroup *peakGroup=(PeakGroup*)&allgroups[i];
            groups.push_back(peakGroup);
        }
            

    clsf->saveFeatures(groups,fileName.toStdString() + ".csv");


}

QString TableDockWidgetBackend::groupsStatus(const QList<PeakGroup>&allgroups){

    int totalCount=0;
    int goodCount=0;
    int badCount=0;
    for(int i=0; i < allgroups.size(); i++ ) {
        if (allgroups[i].label == 'g' )
            goodCount++;
        if ( allgroups[i].label == 'b' )
            badCount++;

        totalCount++;
    }
    QString status = tr("Group Validation Status: Good=%2 Bad=%3 Total=%1").arg(
            QString::number(totalCount),
            QString::number(goodCount),
            QString::number(badCount));
    return status;
}