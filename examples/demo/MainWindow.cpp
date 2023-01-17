#include "MainWindow.hpp"

#include <demo/DebugDemo>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    _output = new DebugDemo();
    _output->output();
}
