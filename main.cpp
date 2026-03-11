#include "mainwindow.h"
#include <QApplication>

/**
 * @brief The main entry point of the Notepad application.
 *
 * This function initializes the Qt application, creates the MainWindow,
 * and starts the event loop. It sets up the GUI and waits for user
 * interactions until the application is closed.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line argument strings.
 * @return int Exit status of the application.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);   ///< Initializes the Qt application framework
    MainWindow w;                 ///< Creates the main window instance
    w.show();                     ///< Displays the main window on screen
    return a.exec();              ///< Enters the Qt event loop
}
