#include "uploadtrainingdatadialog.h"
#include "ui_uploadtrainingdatadialog.h"

//Incomplete

uploadTrainingDataDialog::uploadTrainingDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::uploadTrainingDataDialog)
{
    ui->setupUi(this);
}

uploadTrainingDataDialog::~uploadTrainingDataDialog()
{
    delete ui;
}
