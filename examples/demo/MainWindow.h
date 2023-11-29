#pragma once

#include <QMainWindow>

namespace Demo {
class DebugDemo;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);

  private:
    Demo::DebugDemo *_output;
};
