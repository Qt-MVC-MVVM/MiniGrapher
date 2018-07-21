#include "pentool.h"
#include <QtWidgets/QPushButton>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QColorDialog>

PenTool::PenTool(QString title, QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(title);
    setWindowFlags(Qt::Tool);

    m_colorButton = new QPushButton();

    m_widthSpinBox = new QDoubleSpinBox();

    m_styleCombo = new QComboBox();
    m_styleCombo->addItem("NoPen");
    m_styleCombo->addItem("SolidLine");
    m_styleCombo->addItem("DashLine");
    m_styleCombo->addItem("DotLine");
    m_styleCombo->addItem("DashDotLine");
    m_styleCombo->addItem("DashDotDotLine");

    QFormLayout *layout = new QFormLayout();
    layout->addRow("Color", m_colorButton);
    layout->addRow("Width", m_widthSpinBox);
    layout->addRow("Style", m_styleCombo);

    setLayout(layout);

    // Use old style connect on some signals because the signal is overloaded
    connect(m_colorButton, &QPushButton::clicked, this, &PenTool::showColorDialog);
    connect(m_widthSpinBox,
            static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),
            this, &PenTool::updateWidth);
    connect(m_styleCombo,
            static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &PenTool::updateStyle);
}

void PenTool::setPen(const QPen &pen)
{
    m_pen = pen;
    m_colorButton->setText(m_pen.color().name());
    m_widthSpinBox->setValue(m_pen.widthF());
    m_styleCombo->setCurrentIndex(m_pen.style()); // index matches the enum
}

QPen PenTool::pen() const
{
    return m_pen;
}

QString PenTool::name()
{
    return name(m_pen);
}

QString PenTool::name(const QPen &pen)
{
    return pen.color().name() + ":" + QString::number(pen.widthF());
}

void PenTool::showColorDialog()
{
    QColorDialog dialog(m_pen.color());
    dialog.show();
    dialog.exec();
    m_pen.setColor(dialog.selectedColor());
    m_colorButton->setText(m_pen.color().name());
    emit changed();
}

void PenTool::updateWidth(double width)
{
    if (!qFuzzyCompare((qreal) width, m_pen.widthF())) {
        m_pen.setWidthF(width);
        emit changed();
    }
}

void PenTool::updateStyle(int style)
{
    if (m_pen.style() != style) {
        m_pen.setStyle((Qt::PenStyle) style);
        emit changed();
    }
}

#include "moc_pentool.cpp"
