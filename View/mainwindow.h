#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include "../Common/etlbase.h"
#include "sinks/mainwindowprosink.h"
#include "sinks/mainwindowsetsink.h"
#include "qcustomplot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  void set_submit_command(std::shared_ptr<ICommandBase> ptrCommand);
  std::shared_ptr<IPropertyNotification> getPtrWindowProSink(void);
  std::shared_ptr<ICommandNotification> getPtrWindowSetSink(void);
  void on_submitButton_clicked();

private slots:
  void titleDoubleClick(QMouseEvent *event);
  void axisLabelDoubleClick(QCPAxis* axis, QCPAxis::SelectablePart part);
  void legendDoubleClick(QCPLegend* legend, QCPAbstractLegendItem* item);
  void selectionChanged();
  void mousePress();
  void mouseWheel();
  void addRandomGraph();
  void removeSelectedGraph();
  void removeAllGraphs();
  void contextMenuRequest(QPoint pos);
  void moveLegend();
  void graphClicked(QCPAbstractPlottable *plottable, int dataIndex);

private:
  Ui::MainWindow *ui;
  std::shared_ptr<mainWindowProSink> _ptrWindowProSink;
  std::shared_ptr<mainWindowSetSink> _ptrWindowSetSink;
  std::shared_ptr<ICommandBase> submitCommand;

};

#endif // MAINWINDOW_H
