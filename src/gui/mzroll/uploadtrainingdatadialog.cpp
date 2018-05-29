#include "uploadtrainingdatadialog.h"
#include "ui_uploadtrainingdatadialog.h"

//Incomplete

uploadTrainingDataDialog::uploadTrainingDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::uploadTrainingDataDialog)
{
    ui->setupUi(this);

    ui->progressBar->setValue(0);
}

uploadTrainingDataDialog::~uploadTrainingDataDialog()
{
    delete ui;
}
