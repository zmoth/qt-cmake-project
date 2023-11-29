#include "MainWindow.h"

#include <demo/DebugDemo>

using Demo::DebugDemo;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    _output = new DebugDemo();
    _output->output();
}
