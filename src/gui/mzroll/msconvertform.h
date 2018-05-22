#ifndef MSCONVERTFORM_H
#define MSCONVERTFORM_H

#include "ui_msconvertform.h"
#include "stable.h"
#include "database.h"
#include "mainwindow.h"
#include <QGridLayout>
#include <QFileDialog>
#include <QPushButton>
#include <QtWidgets>

class MainWindow;

/**
* @brief This class id responsible for creating the POlly interface and calling pollyCLI library..
*/

class MsConvertForm : public QDialog, public Ui_MsConvertForm
{
	Q_OBJECT

        public:
                /**
                * @brief credentials required to connect to polly..
                */
                QStringList credentials;
                /**
                * @brief constructor with mainwindow pointer..
                * @param mw [pointer to mainwindow, used to create GUI for elmaven-polly-interface]
                */
                MsConvertForm(MainWindow* mw, MsConvertForm* ms);
                /**
                 * @brief destructor of this class.. 
                 */
                ~MsConvertForm();
                /**
                 * @brief json object which contains the mapping of project names with their IDs
                 */
                QVariantMap projectnames_id;
                /**
                 * @brief json object which contains the mapping of project names with thier uploaded files
                 * @details this is a QVariantMap object that will look like this -
                 * project id -[<file1>,<file2>]
                 * this object is used to populate the compound database,setting combo boxes under polly-elmave-interface GUI.
                 */
                QVariantMap userProjectFilesMap;
                /**
                 * @brief project ID as stored on Polly
                */
                QString ProjectId; 
                
        public Q_SLOTS:
                // void selectMsconvertInputPath();
                void startMsconvert();
                void selectMsconvertInputFolder(QString key);
                // void on_open_msconvert_button_clicked();
                void call_msconvert_form();
                /**
                 * @brief This function cancels the polly-elmaven-interface GUI
                 */
		void cancel();

                inline void selectMsconvertInputPath() { selectMsconvertInputFolder("msconvertFolderPath"); }
                void itHasFinished(int exitCode, QProcess::ExitStatus exitStatus);

        private:
                /**
                 * @brief pointer to mainwindow
                */
                MainWindow *mainwindow;
                MsConvertForm *msConvertForm;
};

#endif
