#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_graph(0),
    ui(new Ui::MainWindow)
{
    srand(QDateTime::currentDateTime().toTime_t());
    ui->setupUi(this);
    _ptrWindowProSink= std::make_shared<mainWindowProSink>(mainWindowProSink(this));
    _ptrWindowSetSink=std::make_shared<mainWindowSetSink>(mainWindowSetSink(this));
    msgLabel = new QLabel;

    ui->CustomPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                                                    QCP::iSelectLegend | QCP::iSelectPlottables);
    ui->CustomPlot->xAxis->setRange(-8, 8);
    ui->CustomPlot->yAxis->setRange(-5, 5);
    ui->CustomPlot->axisRect()->setupFullAxesBox();

    ui->CustomPlot->plotLayout()->insertRow(0);
    QCPTextElement *title = new QCPTextElement(ui->CustomPlot, "Function Graphs", QFont("sans", 10, QFont::Bold));
    ui->CustomPlot->plotLayout()->addElement(0, 0, title);

    ui->CustomPlot->xAxis->setLabel("x Axis");
    ui->CustomPlot->yAxis->setLabel("y Axis");

    ui->CustomPlot->legend->setVisible(false);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->CustomPlot->legend->setFont(legendFont);
    ui->CustomPlot->legend->setSelectedFont(legendFont);
    ui->CustomPlot->legend->setSelectableParts(QCPLegend::spItems); // legend box shall not be selectable, only legend items
    ui->CustomPlot->rescaleAxes();

    // connect slot that ties some axis selections together (especially opposite axes):
    connect(ui->CustomPlot, SIGNAL(selectionChangedByUser()), this, SLOT(selectionChanged()));
    // connect slots that takes care that when an axis is selected, only that direction can be dragged and zoomed:
    connect(ui->CustomPlot, SIGNAL(mousePress(QMouseEvent*)), this, SLOT(mousePress()));
    connect(ui->CustomPlot, SIGNAL(mouseWheel(QWheelEvent*)), this, SLOT(mouseWheel()));

    // make bottom and left axes transfer their ranges to top and right axes:
    connect(ui->CustomPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->CustomPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->CustomPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->CustomPlot->yAxis2, SLOT(setRange(QCPRange)));

    // connect some interaction slots:
    connect(ui->CustomPlot, SIGNAL(axisDoubleClick(QCPAxis*,QCPAxis::SelectablePart,QMouseEvent*)), this, SLOT(axisLabelDoubleClick(QCPAxis*,QCPAxis::SelectablePart)));
    connect(ui->CustomPlot, SIGNAL(legendDoubleClick(QCPLegend*,QCPAbstractLegendItem*,QMouseEvent*)), this, SLOT(legendDoubleClick(QCPLegend*,QCPAbstractLegendItem*)));
    connect(title, SIGNAL(doubleClicked(QMouseEvent*)), this, SLOT(titleDoubleClick(QMouseEvent*)));

    // connect slot that shows a message in the status bar when a graph is clicked:
    connect(ui->CustomPlot, SIGNAL(plottableClick(QCPAbstractPlottable*,int,QMouseEvent*)), this, SLOT(graphClicked(QCPAbstractPlottable*,int)));

    // setup policy and connect slot for context menu popup:
    ui->CustomPlot->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->CustomPlot, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenuRequest(QPoint)));

    QFont font("Microsoft YaHei", 14, 65);
    ui->Differential->setFont(font);
    ui->Integral->setFont(font);

    ui->m_graphName->placeholderText();
    ui->m_graphName->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    m_penTool = new PenTool("Fuction pen", this);
    m_brushTool = new BrushTool("Function brush", this);
    connect(ui->m_graphName, &QLineEdit::textChanged, this, &MainWindow::updateGraphSettings);
    connect(ui->m_pen, &QPushButton::clicked, m_penTool, &PenTool::show);
    connect(m_penTool, &PenTool::changed, this, &MainWindow::updateGraphSettings);
    connect(ui->m_brush, &QPushButton::clicked, m_brushTool, &BrushTool::show);
    connect(m_brushTool, &BrushTool::changed, this, &MainWindow::updateGraphSettings);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateGraphSettings()
{
        if (!m_graph)
                return;

        ui->m_pen->setText(PenTool::name(m_graph->pen()));
        ui->m_brush->setText(BrushTool::name(m_graph->brush()));

        m_graph->setPen(m_penTool->pen());
        m_graph->setBrush(m_brushTool->brush());
        m_graph->setName(ui->m_graphName->text());

        ui->CustomPlot->replot();
}

void MainWindow::titleDoubleClick(QMouseEvent* event)
{
    Q_UNUSED(event)
    if (QCPTextElement *title = qobject_cast<QCPTextElement*>(sender()))
    {
        // Set the plot title by double clicking on it
        bool ok;
        QString newTitle = QInputDialog::getText(this, "Graphs", "New plot title:", QLineEdit::Normal, title->text(), &ok);
        if (ok)
        {
            title->setText(newTitle);
            ui->CustomPlot->replot();
        }
    }
}

void MainWindow::axisLabelDoubleClick(QCPAxis *axis, QCPAxis::SelectablePart part)
{
    // Set an axis label by double clicking on it
    if (part == QCPAxis::spAxisLabel) // only react when the actual axis label is clicked, not tick label or axis backbone
    {
        bool ok;
        QString newLabel = QInputDialog::getText(this, "Graphs", "New axis label:", QLineEdit::Normal, axis->label(), &ok);
        if (ok)
        {
            axis->setLabel(newLabel);
            ui->CustomPlot->replot();
        }
    }
}

void MainWindow::legendDoubleClick(QCPLegend *legend, QCPAbstractLegendItem *item)
{
    // Rename a graph by double clicking on its legend item
    Q_UNUSED(legend)
    if (item) // only react if item was clicked (user could have clicked on border padding of legend where there is no item, then item is 0)
    {
        QCPPlottableLegendItem *plItem = qobject_cast<QCPPlottableLegendItem*>(item);
        bool ok;
        QString newName = QInputDialog::getText(this, "Graphs", "New graph name:", QLineEdit::Normal, plItem->plottable()->name(), &ok);
        if (ok)
        {
            plItem->plottable()->setName(newName);
            ui->CustomPlot->replot();
        }
    }
}

void MainWindow::selectionChanged()
{
    // make top and bottom axes be selected synchronously, and handle axis and tick labels as one selectable object:
    if (ui->CustomPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis) || ui->CustomPlot->xAxis->selectedParts().testFlag(QCPAxis::spTickLabels) ||
            ui->CustomPlot->xAxis2->selectedParts().testFlag(QCPAxis::spAxis) || ui->CustomPlot->xAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
    {
        ui->CustomPlot->xAxis2->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
        ui->CustomPlot->xAxis->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
    }
    // make left and right axes be selected synchronously, and handle axis and tick labels as one selectable object:
    if (ui->CustomPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis) || ui->CustomPlot->yAxis->selectedParts().testFlag(QCPAxis::spTickLabels) ||
            ui->CustomPlot->yAxis2->selectedParts().testFlag(QCPAxis::spAxis) || ui->CustomPlot->yAxis2->selectedParts().testFlag(QCPAxis::spTickLabels))
    {
        ui->CustomPlot->yAxis2->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
        ui->CustomPlot->yAxis->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
    }

    // synchronize selection of graphs with selection of corresponding legend items:
    for (int i=0; i<ui->CustomPlot->graphCount(); ++i)
    {
        QCPGraph *graph = ui->CustomPlot->graph(i);
        QCPPlottableLegendItem *item = ui->CustomPlot->legend->itemWithPlottable(graph);
        if (item->selected() || graph->selected())
        {
            item->setSelected(true);
            graph->setSelection(QCPDataSelection(graph->data()->dataRange()));
        }
    }
}

void MainWindow::mousePress()
{
    // if an axis is selected, only allow the direction of that axis to be dragged
    // if no axis is selected, both directions may be dragged

    if (ui->CustomPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
        ui->CustomPlot->axisRect()->setRangeDrag(ui->CustomPlot->xAxis->orientation());
    else if (ui->CustomPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
        ui->CustomPlot->axisRect()->setRangeDrag(ui->CustomPlot->yAxis->orientation());
    else
        ui->CustomPlot->axisRect()->setRangeDrag(Qt::Horizontal|Qt::Vertical);
}

void MainWindow::mouseWheel()
{
    // if an axis is selected, only allow the direction of that axis to be zoomed
    // if no axis is selected, both directions may be zoomed

    if (ui->CustomPlot->xAxis->selectedParts().testFlag(QCPAxis::spAxis))
        ui->CustomPlot->axisRect()->setRangeZoom(ui->CustomPlot->xAxis->orientation());
    else if (ui->CustomPlot->yAxis->selectedParts().testFlag(QCPAxis::spAxis))
        ui->CustomPlot->axisRect()->setRangeZoom(ui->CustomPlot->yAxis->orientation());
    else
        ui->CustomPlot->axisRect()->setRangeZoom(Qt::Horizontal|Qt::Vertical);
}

void MainWindow::addRandomGraph()
{
    int n = 50; // number of points in graph
    double xScale = (rand()/(double)RAND_MAX + 0.5)*2;
    double yScale = (rand()/(double)RAND_MAX + 0.5)*2;
    double xOffset = (rand()/(double)RAND_MAX - 0.5)*4;
    double yOffset = (rand()/(double)RAND_MAX - 0.5)*10;
    double r1 = (rand()/(double)RAND_MAX - 0.5)*2;
    double r2 = (rand()/(double)RAND_MAX - 0.5)*2;
    double r3 = (rand()/(double)RAND_MAX - 0.5)*2;
    double r4 = (rand()/(double)RAND_MAX - 0.5)*2;
    QVector<double> x(n), y(n);
    for (int i=0; i<n; i++)
    {
        x[i] = (i/(double)n-0.5)*10.0*xScale + xOffset;
        y[i] = (qSin(x[i]*r1*5)*qSin(qCos(x[i]*r2)*r4*3)+r3*qCos(qSin(x[i])*r4*2))*yScale + yOffset;
    }

    ui->CustomPlot->addGraph();
    ui->CustomPlot->graph()->setName(QString("New graph %1").arg(ui->CustomPlot->graphCount()-1));
    ui->CustomPlot->graph()->setData(x, y);
    ui->CustomPlot->graph()->setLineStyle((QCPGraph::LineStyle)(rand()%5+1));
    if (rand()%100 > 50)
        ui->CustomPlot->graph()->setScatterStyle(QCPScatterStyle((QCPScatterStyle::ScatterShape)(rand()%14+1)));
    QPen graphPen;
    graphPen.setColor(QColor(rand()%245+10, rand()%245+10, rand()%245+10));
    graphPen.setWidthF(rand()/(double)RAND_MAX*2+1);
    ui->CustomPlot->graph()->setPen(graphPen);

    if (ui->CustomPlot->graphCount() > 0)
                ui->CustomPlot->legend->setVisible(true);

    ui->CustomPlot->replot();
}

void MainWindow::plotGraph()
{
        ui->CustomPlot->addGraph();
        ui->CustomPlot->graph()->setName(ui->Function->text());
        ui->CustomPlot->xAxis2->setVisible(true);
        ui->CustomPlot->xAxis2->setTickLabels(false);
        ui->CustomPlot->yAxis2->setVisible(true);
        ui->CustomPlot->yAxis2->setTickLabels(false);

        // make left and bottom axes always transfer their ranges to right and top axes:
        // pass data points to graphs:
        ui->CustomPlot->graph()->setData(*x, *y);
        // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
        ui->CustomPlot->graph()->rescaleAxes();

        ui->CustomPlot->graph()->setPen(QPen(QColor(0, 94, 161, 255)));
        ui->CustomPlot->graph()->setBrush(QBrush(QColor(156, 212, 255, 40)));
        if (ui->CustomPlot->graphCount() > 0)
                    ui->CustomPlot->legend->setVisible(true);

        ui->Function->clear();

        ui->CustomPlot->replot();
}

void MainWindow::setIntegral(std::shared_ptr<double> IntegralAns)
{
        this->IntegralAns = IntegralAns;
}

void MainWindow::setDifferential(std::shared_ptr<double> DifferentialAns)
{
        this->DifferentialAns = DifferentialAns;
}

void MainWindow::showDifferential()
{
        ui->Differential->setText(QString::number(*DifferentialAns));
}

void MainWindow::showIntegral()
{
        ui->Integral->setText(QString::number(*IntegralAns));
}

void MainWindow::showPaintFailed()
{
        QString failure = "Wrong input.";
        msgLabel->setText(failure);
        ui->statusBar->addWidget(msgLabel);
}

void MainWindow::showPaintSucceed()
{
        QString success = "Plot graph succeeded.";
        msgLabel->setText(success);
        ui->statusBar->addWidget(msgLabel);
}

void MainWindow::removeSelectedGraph()
{
    if (ui->CustomPlot->selectedGraphs().size() > 0)
    {

        ui->CustomPlot->graph()->setPen(QPen(QColor(0, 94, 161, 255)));
        ui->CustomPlot->graph()->setBrush(QBrush(QColor(156, 212, 255, 40)));
        m_graph = 0;

        ui->CustomPlot->removeGraph(ui->CustomPlot->selectedGraphs().first());

        ui->m_graphName->clear();
        if (ui->CustomPlot->graphCount() <= 0)
                    ui->CustomPlot->legend->setVisible(false);

        ui->CustomPlot->replot();
    }
}

void MainWindow::removeAllGraphs()
{
    ui->CustomPlot->graph()->setPen(QPen(QColor(0, 94, 161, 255)));
    ui->CustomPlot->graph()->setBrush(QBrush(QColor(156, 212, 255, 40)));
    m_graph = 0;

    ui->CustomPlot->clearGraphs();

    ui->m_graphName->clear();
    if (ui->CustomPlot->graphCount() <= 0)
                ui->CustomPlot->legend->setVisible(false);

    ui->CustomPlot->replot();
}

void MainWindow::contextMenuRequest(QPoint pos)
{
    QMenu *menu = new QMenu(this);
    menu->setAttribute(Qt::WA_DeleteOnClose);

    if (ui->CustomPlot->legend->selectTest(pos, false) >= 0) // context menu on legend requested
    {
        menu->addAction("Move to top left", this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop|Qt::AlignLeft));
        menu->addAction("Move to top center", this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop|Qt::AlignHCenter));
        menu->addAction("Move to top right", this, SLOT(moveLegend()))->setData((int)(Qt::AlignTop|Qt::AlignRight));
        menu->addAction("Move to bottom right", this, SLOT(moveLegend()))->setData((int)(Qt::AlignBottom|Qt::AlignRight));
        menu->addAction("Move to bottom left", this, SLOT(moveLegend()))->setData((int)(Qt::AlignBottom|Qt::AlignLeft));
    } else    // general context menu on graphs requested
    {
        menu->addAction("Add random graph", this, SLOT(addRandomGraph()));
        if (ui->CustomPlot->selectedGraphs().size() > 0)
            menu->addAction("Remove selected graph", this, SLOT(removeSelectedGraph()));
        if (ui->CustomPlot->graphCount() > 0)
            menu->addAction("Remove all graphs", this, SLOT(removeAllGraphs()));
    }

    menu->popup(ui->CustomPlot->mapToGlobal(pos));
}

void MainWindow::moveLegend()
{
    if (QAction* contextAction = qobject_cast<QAction*>(sender())) // make sure this slot is really called by a context menu action, so it carries the data we need
    {
        bool ok;
        int dataInt = contextAction->data().toInt(&ok);
        if (ok)
        {
            ui->CustomPlot->axisRect()->insetLayout()->setInsetAlignment(0, (Qt::Alignment)dataInt);
            ui->CustomPlot->replot();
        }
    }
}

void MainWindow::graphClicked(QCPAbstractPlottable *plottable, int dataIndex)
{
    m_graph = static_cast<QCPGraph *>(plottable);

    ui->m_graphName->blockSignals(true);
    ui->m_graphName->setText(m_graph->name());
    ui->m_graphName->blockSignals(false);


    m_penTool->setPen(m_graph->pen());
    ui->m_pen->setText(PenTool::name(m_graph->pen()));


    m_brushTool->setBrush(m_graph->brush());
    ui->m_brush->setText(BrushTool::name(m_graph->brush()));

    double dataValue = plottable->interface1D()->dataMainValue(dataIndex);
    QString message = QString("Clicked on graph '%1' at data point #%2 with value %3.").arg(plottable->name()).arg(dataIndex).arg(dataValue);
    ui->statusBar->showMessage(message, 2500);
}

void MainWindow::set_paint_command(std::shared_ptr<ICommandBase> ptrCommand)
{
        PaintCommand = ptrCommand;
}

void MainWindow::set_differential_command(std::shared_ptr<ICommandBase> ptrCommand)
{
        DifferentialCommand = ptrCommand;
}

void MainWindow::set_integral_command(std::shared_ptr<ICommandBase> ptrCommand)
{
        IntegralCommand = ptrCommand;
}

std::shared_ptr<IPropertyNotification> MainWindow::getPtrWindowProSink()
{
    return std::static_pointer_cast<IPropertyNotification>(_ptrWindowProSink);
}

std::shared_ptr<ICommandNotification> MainWindow::getPtrWindowSetSink()
{
    return std::static_pointer_cast<ICommandNotification>(_ptrWindowSetSink);
}

void MainWindow::on_AddGraphButton_clicked()
{

        bool ok(false);
        QString qstr = ui->Function->text();
        QString qlower = ui->LowerBound->text();
        QString qupper = ui->UpperBound->text();
        std::string str = qstr.toStdString();

        double lower = qlower.isEmpty()? -10: qlower.toDouble(&ok);
        double upper = qupper.isEmpty()?  10: qupper.toDouble(&ok);

        PaintCommand->SetParameter(str, lower, upper);
        PaintCommand->Exec();

        DifferentialCommand->SetParameter(str, lower);
        DifferentialCommand->Exec();

        IntegralCommand->SetParameter(str, lower, upper);
        IntegralCommand->Exec();
}

void MainWindow::on_RemoveGraphButton_clicked()
{
        removeSelectedGraph();
}

void MainWindow::on_ClearAllButton_clicked()
{
        removeAllGraphs();
}

void MainWindow::set_x(std::shared_ptr<QVector<double> > x)
{
        this->x = x;
}

void MainWindow::set_y(std::shared_ptr<QVector<double> > y)
{
        this->y = y;
}
