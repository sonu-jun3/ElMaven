#include "msconvertform.h"
#include <string>
#include <QVariant>
// #include <QFileDialog>

MsConvertForm::MsConvertForm(MainWindow* mw, MsConvertForm* ms) :
        QDialog(mw),
        mainwindow(mw)
{
        setupUi(this);
        setModal(true);
        msConvertForm = ms;
        mainwindow = mw;
        // connect(computeButton_upload, SIGNAL(clicked(bool)), SLOT(uploadDataToPolly()));
        // connect(cancelButton_upload, SIGNAL(clicked(bool)), SLOT(cancel()));
        // connect(pushButton_load, SIGNAL(clicked(bool)), SLOT(loadDataFromPolly()));
        // connect(cancelButton_load, SIGNAL(clicked(bool)), SLOT(cancel()));

        connect(selectDriveFolderPath, SIGNAL(clicked()), SLOT(selectMsconvertInputPath()));
        connect(openMsconvert, SIGNAL(clicked()), SLOT(startMsconvert()));
}

MsConvertForm::~MsConvertForm()
{
    qDebug()<<"exiting MsConvertForm now....";
}


void MsConvertForm::call_msconvert_form(){
    // _loginform =new LoginForm(this);
    // _loginform->setModal(true);
    // _loginform->show();
}
// void MsConvertForm::on_open_msconvert_button_clicked(){
//     qDebug()<<"open msconvert docker GUI here..";
// }

void MsConvertForm::cancel() {
    close();   
}

void MsConvertForm::selectMsconvertInputFolder(QString key) {
    QString oFolder = ".";
    // if(msConvertForm->contains(key)) oFolder =  msConvertForm->value(key).toString();
    QString newFolder = QFileDialog::getExistingDirectory(this,tr("Open Directory"),"/home",
                                                QFileDialog::ShowDirsOnly
                                                | QFileDialog::DontResolveSymlinks);
    if (! newFolder.isEmpty()) {
        msconvertFolderPath->setText(newFolder);
    }
}

void MsConvertForm::itHasFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    
    if(exitStatus == QProcess::NormalExit) {
        //Let's make progress bar to show 100%
        qDebug() << "IN exitStatus == QProcess::NormalExit " << '\n' ;
        qDebug() << exitStatus << '\n' ;
        // msconvertProgressBar->setMaximum(1);
        // msconvertProgressBar->setMinimum(0);
        // msconvertProgressBar->setValue(1);
        // msconvertStatus->setText("Complete.");
    }
    else {
        // msconvertStatus->setText("Error in process");
        qDebug() << "IN exitStatus != QProcess::NormalExit " << '\n' ;
    }
}

// void msconvertsForm::msconvertProcessreadyReadStandardOutput()
// {
//     qDebug() << "In on_process_readyReadStandardOutput" << '\n';
//     // qDebug() << qobject_cast<QProcess *>(sender())->readAllStandardOutput();
//     msconvertOutputLogs->setText(qobject_cast<QProcess *>(sender())->readAllStandardOutput());
// }

void MsConvertForm::startMsconvert() {
    qDebug() << "IN startMsconvert " << '\n' ;
    qDebug() << msconvertFolderPath->text() << '\n' ;
    // qDebug() << msconvert_output_file_type->currentText() << '\n' ; 
    // qDebug() << msconvert_file_path->text().isEmpty() << '\n';

    if( (msconvertFolderPath->text().isEmpty()) ) {
        qDebug() << "File path required." << '\n';
        return;
    }
    else {
        qDebug() << "File path has value" << '\n';
    }

    QProcess *process1 = new QProcess();
    // QProcess *process2 = new QProcess();
    // QProcess *process3 = new QProcess();
    // QProcess *process4 = new QProcess();
    // connect(process4, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(itHasFinished(int, QProcess::ExitStatus)));
    // connect(process, SIGNAL(readyReadStandardOutput()), this, SLOT(msconvertProcessreadyReadStandardOutput()));
    // msconvertProgressBar->setMaximum(0);
    // msconvertProgressBar->setMinimum(0);
    // msconvertStatus->setText("Running...");
    // process4->start("export DISPLAY=:0 && ip=$(ifconfig en0 | grep inet | awk '$1==\"inet\" {print $2}') && xhost $ip && docker run --rm --name elmsmac -v /tmp/.X11-unix:/tmp/.X11-unix:rw -v \" + msconvertFolderPath->text() + \":/data:rw -e DISPLAY=$ip:0 kushalgupta/msconvertgui:0.1");
    
    QString binFolder = qApp->applicationDirPath() + QDir::separator() + ".." + QDir::separator() + ".." \
            + QDir::separator() + ".." + QDir::separator();
    qDebug() << "Path " << binFolder << '\n';
    QString runMsconvertScript = binFolder + "run_msconvert.sh";

    // QProcess *pr = new QProcess;
    process1->setProgram("bash");
    QStringList arguments;
    arguments << runMsconvertScript;
    arguments << msconvertFolderPath->text();
    process1->setArguments(arguments);
    // pr->setProcessChannelMode(QProcess::SeparateChannels);
    // pr->startDetached(runMsconvertScript);

    // QStringList arguments;
    // arguments << runMsconvertScript;
    // arguments << settings->value("bucket_name").toString();
    // arguments << settings->value("access_key").toString();
    // arguments << settings->value("secret_key").toString();
//  arguments <<  myAppender.getMessageQList();
    // arguments << "0";
    process1->start();

    // process1->start("bash", runMsconvertScript);
    // process1->waitForFinished();
    // QString strOut1 = process1->readAllStandardOutput();
    qDebug() << "process1 Output" << '\n';
    qDebug() << process1->errorString() << '\n';
    // usleep(3000);   
    QString output1(process1->readAllStandardOutput());  

    qDebug()<<output1;


    // process4->start("export DISPLAY=:0");
    // process4->waitForFinished(-1);
    // // QString strOut4 = process4->readAllStandardOutput();
    // // qDebug() << "process4 Output"<< strOut4 << '\n';
    // qDebug() << "process4 Output"<< '\n';
    // usleep(2000);   
    // QString output4(process4->readAllStandardOutput());   
    // qDebug()<<output4;

    // QString program = "docker";
    // QStringList arguments;
    // arguments <<"run"<< "--rm"<< "--name" << "elmsmac" << "-v" << "/tmp/.X11-unix:/tmp/.X11-unix:rw" "-v" << msconvertFolderPath->text()+ ':/data:rw' <<  "-e" << "DISPLAY=$ip:0" << "kushalgupta/msconvertgui:0.1";

    // QProcess *myProcess = new QProcess();
    // myProcess->start(program, arguments, QIODevice::ReadWrite);
    // myProcess->waitForFinished();
    // QString strOut5 = myProcess->readAllStandardOutput();
    // qDebug() << "myProcess Output"<< strOut4 << '\n';




    // process1->start("ip=$(ifconfig en0 | grep inet | awk '$1==\"inet\" {print $2}')");
    // process1->waitForFinished();
    // // QString strOut1 = process1->readAllStandardOutput();
    // qDebug() << "process1 Output" << '\n';
    // usleep(4000);   
    // QString output1(process1->readAllStandardOutput());   
    // qDebug()<<output1;

    // process2->start("xhost $ip");
    // process2->waitForFinished();
    // // QString strOut2 = process2->readAllStandardOutput();
    // qDebug() << "process2 Output"<< '\n';
    // usleep(4000);   
    // QString output2(process2->readAllStandardOutput());   
    // qDebug()<<output2;

    // process3->start("docker run --rm --name elmsmac -v /tmp/.X11-unix:/tmp/.X11-unix:rw -v " + msconvertFolderPath->text() + ":/data:rw -e DISPLAY=$ip:0 kushalgupta/msconvertgui:0.1");
    // // process3->start("docker run --rm -v /tmp/.X11-unix:/tmp/.X11-unix:rw -v " + msconvertFolderPath->text() + ":/data:rw kushalgupta/msconvertgui:0.1");
    // process3->waitForFinished();
    // // QString strOut3 = process3->readAllStandardOutput();
    // qDebug() << "process3 Output"<< '\n';
    // usleep(4000);   
    // QString output3(process3->readAllStandardOutput());   
    // qDebug()<<output3;
}

// docker run --rm --name msmac -v /tmp/.X11-unix:/tmp/.X11-unix:rw -v /Users/abhishek/Desktop/kushal:/data:rw -e DISPLAY=$ip:0 kushalgupta/msconvertgui:0.1

