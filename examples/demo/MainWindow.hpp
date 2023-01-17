#pragma once

#include <QMainWindow>

class DebugDemo;

class MainWindow : public QMainWindow
{
    Q_OBJECT
  public:
    MainWindow(QWidget *parent = nullptr);

  private:
    DebugDemo *_output;
};
