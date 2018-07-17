#ifndef D2_H
#define D2_H

#include <QtCharts/QChartGlobal>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGraphicsGridLayout>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtCharts/QLineSeries>
#include <QtWidgets/QLabel>
#include <QtCore/QDebug>
#include <QtCharts/QLegend>
#include <QtWidgets/QFormLayout>
#include <QtCharts/QLegendMarker>
#include <QtCharts/QXYLegendMarker>
#include <QtCore/QtMath>

QT_CHARTS_USE_NAMESPACE

class D2: public QWidget
{
    Q_OBJECT
public:
    explicit D2(QWidget *parent = 0);

public slots:
    void addSeries();
    void removeSeries();
    void connectMarkers();
    void disconnectMarkers();

    void handleMarkerClicked();

private:
    QChart *m_chart;
    QList<QLineSeries*> m_series;

    QChartView *m_chartView;
    QGridLayout *m_main_Layout;
    QGridLayout *m_font_Layout;
};

#endif // D2_H
