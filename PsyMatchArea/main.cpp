#include <QApplication>
#include <QFontDatabase>
#include <QMessageBox>
#include <QThread>
#include <QTime>

#include "cf_mainform.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QFontDatabase fontDatabase;
    if (!fontDatabase.families().contains("FangSong")) {
        int loaded = QFontDatabase::addApplicationFont(qApp->applicationDirPath() + "/fonts/simfang.ttf");
        if (loaded < 0) QMessageBox::warning(0, "PsyMatchArea", "Can't load FangSong font!");
    }

    QApplication::setStyle("plastique");

    QTime currTime = QTime::currentTime();
    qsrand(currTime.msec() + currTime.second() + currTime.minute() + currTime.hour());

    CMainForm *mainForm = new CMainForm;

    if (mainForm->isSettingsFullScreen())
        mainForm->showFullScreen();
    else
        mainForm->show();

    return app.exec();
}
