#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

/**
 * @class MainWindow
 * @brief A simple Notepad-like text editor built using Qt.
 *
 * This class provides functionality for creating, opening, saving,
 * editing, and deleting text files. It also supports basic text
 * editing operations like undo, redo, cut, copy, and paste.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit); ///< Set QTextEdit as the central widget
}

/**
 * @brief Destructor for MainWindow.
 * Cleans up the UI resources.
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Creates a new file.
 *
 * Clears the text editor and resets the file path.
 */
void MainWindow::on_actionNew_triggered()
{
    file_path = " ";
    ui->textEdit->setText("");
}

/**
 * @brief Saves the current text to the existing file.
 *
 * If the file cannot be opened, a warning message is shown.
 */
void MainWindow::on_actionSave_triggered()
{
    QFile file(file_path);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "..", "File not open");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

/**
 * @brief Saves the current text to a new file.
 *
 * Opens a "Save As" dialog to choose the file name and location.
 */
void MainWindow::on_actionSaveAs_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this, "Open the file");
    QFile file(file_name);
    file_path = file_name;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "..", "File not open");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

/**
 * @brief Undo the last text editing action.
 */
void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

/**
 * @brief Cut the selected text.
 */
void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

/**
 * @brief Copy the selected text.
 */
void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

/**
 * @brief Paste text from the clipboard.
 */
void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

/**
 * @brief Redo the last undone action.
 */
void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

/**
 * @brief Opens an existing text file.
 *
 * Displays a file dialog, loads the file content into the editor,
 * and updates the file path.
 */
void MainWindow::on_actionOpen_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(file_name);
    file_path = file_name;
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "..", "File not open");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

/**
 * @brief Displays information about the Notepad application.
 *
 * Shows author, launch date, version, and technology used.
 */
void MainWindow::on_actionNotepad_triggered()
{
    QString about_text;
    about_text = "Author : Mrunmai\n";
    about_text += "Launch Date: 20 Feb 2026\n";
    about_text += "Version: 0.1\n";
    about_text += "Technology: QT Framework, C++ Language\n";
    QMessageBox::about(this, "Notepad Information", about_text);
}
