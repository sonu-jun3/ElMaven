#ifndef UPLOADTRAININGDATADIALOG_H
#define UPLOADTRAININGDATADIALOG_H

#include <QDialog>

//Incomplete

namespace Ui {
class uploadTrainingDataDialog;
}

class uploadTrainingDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit uploadTrainingDataDialog(QWidget *parent = 0);
    ~uploadTrainingDataDialog();

private:
    Ui::uploadTrainingDataDialog *ui;
};

#endif // UPLOADTRAININGDATADIALOG_H
