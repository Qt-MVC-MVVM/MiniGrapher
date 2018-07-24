#include <QTest>
#include "../ViewModel/commands/calculuscommand.h"
#include "../ViewModel/commands/PaintCommand.h"
#include "../ViewModel/viewmodel.h"
#include "../Model/model.h"

#define Error0 1e-3
class MiniGrapherTest : public QObject
{
    Q_OBJECT

public:
    MiniGrapherTest();

    void set_paint_command(std::shared_ptr<ICommandBase> ptrCommand);
    void set_differential_command(std::shared_ptr<ICommandBase> ptrCommand);
    void set_integral_command(std::shared_ptr<ICommandBase> ptrCommand);
    void set_x(std::shared_ptr<QVector<double>> x);
    void set_y(std::shared_ptr<QVector<double>> y);
    void setIntegral(std::shared_ptr<double> IntegralAns);
    void setDifferential(std::shared_ptr<double> DifferentialAns);

private Q_SLOTS:
    void LinearTest();
    void QuadraticTest();
    void CubicTest();
    void SineTest();
    void CosineTest();
    void TangentTest();
    void lgTest();
    void lnTest();
    void AbsTest();
    void SqrtTest();
    void CompoundFuncTest();

private:
    std::shared_ptr<ICommandBase> PaintCommand;
    std::shared_ptr<ICommandBase> DifferentialCommand;
    std::shared_ptr<ICommandBase> IntegralCommand;
    std::shared_ptr<QVector<double>> x,y;
    std::shared_ptr<double> IntegralAns,DifferentialAns;
    std::shared_ptr<Model> model;
    std::shared_ptr<ViewModel> viewmodel;
};

MiniGrapherTest::MiniGrapherTest()
{
    model = std::make_shared<Model>();
    viewmodel = std::make_shared<ViewModel>();
    viewmodel->setModel(model);

    PaintCommand = viewmodel->getPaintCmd();
    DifferentialCommand = viewmodel->getDifferentialCmd();
    IntegralCommand = viewmodel->getIntegralCmd();
    x = viewmodel->getX();
    y = viewmodel->getY();
    IntegralAns = viewmodel->getIntegral();
    DifferentialAns = viewmodel->getDifferential();
}

void MiniGrapherTest::LinearTest()
{
    std::string str = "x";
    double lowerbound = 0;
    double upperbound = 10;
    const double ExpectedIntegral = 50;
    const double ExpectedDifferential = 1;
    // Testing for Coordinates
    PaintCommand->SetParameter(str, lowerbound, upperbound);
    PaintCommand->Exec();
    QCOMPARE((*x).size(), (*y).size());
    for(int i = 0; i < (*x).size()-1; ++i)
    {
        QVERIFY(fabs((*y)[i] - (*x)[i]) < Error0);
    }
    // Testing for Integral
    IntegralCommand->SetParameter(str, lowerbound, upperbound);
    IntegralCommand->Exec();
    QVERIFY(fabs(*IntegralAns-ExpectedIntegral) < Error0);
    // Testing for Differential
    DifferentialCommand->SetParameter(str, lowerbound);
    DifferentialCommand->Exec();
    QVERIFY(fabs(*DifferentialAns-ExpectedDifferential) < Error0);
}

void MiniGrapherTest::QuadraticTest()
{
    std::string str = "x^2";
    double lowerbound = -10;
    double upperbound = 10;
    const double ExpectedIntegral = 666.667;
    const double ExpectedDifferential = -20;
    // Testing for Coordinates
    PaintCommand->SetParameter(str, lowerbound, upperbound);
    PaintCommand->Exec();
    QCOMPARE((*x).size(), (*y).size());
    for(int i = 0; i < (*x).size()-1; ++i)
    {
        QVERIFY(fabs((*x)[i]*(*x)[i] - (*y)[i]) < Error0);
    }
    // Testing for Integral
    IntegralCommand->SetParameter(str, lowerbound, upperbound);
    IntegralCommand->Exec();
    QVERIFY(fabs(*IntegralAns-ExpectedIntegral) < Error0);
    // Testing for Differential
    DifferentialCommand->SetParameter(str, lowerbound);
    DifferentialCommand->Exec();
    QVERIFY(fabs(*DifferentialAns-ExpectedDifferential) < Error0);
}

void MiniGrapherTest::CubicTest()
{
    std::string str = "x^3";
    double lowerbound = -10;
    double upperbound = 10;
    const double ExpectedIntegral = 0;
    const double ExpectedDifferential = 300;
    // Testing for Coordinates
    PaintCommand->SetParameter(str, lowerbound, upperbound);
    PaintCommand->Exec();
    QCOMPARE((*x).size(), (*y).size());
    for(int i = 0; i < (*x).size()-1; ++i)
    {
        QVERIFY(fabs((*x)[i]*(*x)[i]*(*x)[i] - (*y)[i]) < Error0);
    }
    // Testing for Integral
    IntegralCommand->SetParameter(str, lowerbound, upperbound);
    IntegralCommand->Exec();
    QVERIFY(fabs(*IntegralAns-ExpectedIntegral) < Error0);
    // Testing for Differential
    DifferentialCommand->SetParameter(str, lowerbound);
    DifferentialCommand->Exec();
    QVERIFY(fabs(*DifferentialAns-ExpectedDifferential) < Error0);
}

void MiniGrapherTest::SineTest()
{
    std::string str = "sin(x)";
    double lowerbound = -10;
    double upperbound = 10;
    const double ExpectedIntegral = 0;
    const double ExpectedDifferential = -0.8391;
    // Testing for Coordinates
    PaintCommand->SetParameter(str, lowerbound, upperbound);
    PaintCommand->Exec();
    QCOMPARE((*x).size(), (*y).size());
    for(int i = 0; i < (*x).size()-1; ++i)
    {
        QVERIFY(fabs(sin((*x)[i]) - (*y)[i]) < Error0);
    }
    // Testing for Integral
    IntegralCommand->SetParameter(str, lowerbound, upperbound);
    IntegralCommand->Exec();
    QVERIFY(fabs(*IntegralAns-ExpectedIntegral) < Error0);
    // Testing for Differential
    DifferentialCommand->SetParameter(str, lowerbound);
    DifferentialCommand->Exec();
    QVERIFY(fabs(*DifferentialAns-ExpectedDifferential) < Error0);
}

void MiniGrapherTest::CosineTest()
{
    std::string str = "cos(x)";
    double lowerbound = -10;
    double upperbound = 10;
    const double ExpectedIntegral = -1.088;
    const double ExpectedDifferential = -0.544;
    // Testing for Coordinates
    PaintCommand->SetParameter(str, lowerbound, upperbound);
    PaintCommand->Exec();
    QCOMPARE((*x).size(), (*y).size());
    for(int i = 0; i < (*x).size()-1; ++i)
    {
        QVERIFY(fabs(cos((*x)[i]) - (*y)[i]) < Error0);
    }
    // Testing for Integral
    IntegralCommand->SetParameter(str, lowerbound, upperbound);
    IntegralCommand->Exec();
    QVERIFY(fabs(*IntegralAns-ExpectedIntegral) < Error0);
    // Testing for Differential
    DifferentialCommand->SetParameter(str, lowerbound);
    DifferentialCommand->Exec();
    QVERIFY(fabs(*DifferentialAns-ExpectedDifferential) < Error0);
}

void MiniGrapherTest::TangentTest()
{
    std::string str = "tan(x)";
    double lowerbound = -1;
    double upperbound = 1;
    const double ExpectedIntegral = 0;
    const double ExpectedDifferential = 3.4265;
    // Testing for Coordinates
    PaintCommand->SetParameter(str, lowerbound, upperbound);
    PaintCommand->Exec();
    QCOMPARE((*x).size(), (*y).size());
    for(int i = 0; i < (*x).size()-1; ++i)
    {
        QVERIFY(fabs(tan((*x)[i]) - (*y)[i]) < Error0);
    }
    // Testing for Integral
    IntegralCommand->SetParameter(str, lowerbound, upperbound);
    IntegralCommand->Exec();
    QVERIFY(fabs(*IntegralAns-ExpectedIntegral) < Error0);
    // Testing for Differential
    DifferentialCommand->SetParameter(str, lowerbound);
    DifferentialCommand->Exec();
    QVERIFY(fabs(*DifferentialAns-ExpectedDifferential) < Error0);
}

void MiniGrapherTest::lgTest()
{
    std::string str = "lg(x)";
    double lowerbound = 1;
    double upperbound = 10;
    const double ExpectedIntegral = 6.0913;
    const double ExpectedDifferential = 0.4343;
    // Testing for Coordinates
    PaintCommand->SetParameter(str, lowerbound, upperbound);
    PaintCommand->Exec();
    QCOMPARE((*x).size(), (*y).size());
    for(int i = 0; i < (*x).size()-1; ++i)
    {
        QVERIFY(fabs(log10((*x)[i]) - (*y)[i]) < Error0);
    }
    // Testing for Integral
    IntegralCommand->SetParameter(str, lowerbound, upperbound);
    IntegralCommand->Exec();
    QVERIFY(fabs(*IntegralAns-ExpectedIntegral) < Error0);
    // Testing for Differential
    DifferentialCommand->SetParameter(str, lowerbound);
    DifferentialCommand->Exec();
    QVERIFY(fabs(*DifferentialAns-ExpectedDifferential) < Error0);
}

void MiniGrapherTest::lnTest()
{
    std::string str = "ln(x)";
    double lowerbound = 1;
    double upperbound = 10;
    const double ExpectedIntegral = 14.0259;
    const double ExpectedDifferential = 1;
    // Testing for Coordinates
    PaintCommand->SetParameter(str, lowerbound, upperbound);
    PaintCommand->Exec();
    QCOMPARE((*x).size(), (*y).size());
    for(int i = 0; i < (*x).size()-1; ++i)
    {
        QVERIFY(fabs(log((*x)[i]) - (*y)[i]) < Error0);
    }
    // Testing for Integral
    IntegralCommand->SetParameter(str, lowerbound, upperbound);
    IntegralCommand->Exec();
    QVERIFY(fabs(*IntegralAns-ExpectedIntegral) < Error0);
    // Testing for Differential
    DifferentialCommand->SetParameter(str, lowerbound);
    DifferentialCommand->Exec();
    QVERIFY(fabs(*DifferentialAns-ExpectedDifferential) < Error0);
}

void MiniGrapherTest::AbsTest()
{
    std::string str = "abs(x)";
    double lowerbound = -10;
    double upperbound = 10;
    const double ExpectedIntegral = 100;
    const double ExpectedDifferential = -1;
    // Testing for Coordinates
    PaintCommand->SetParameter(str, lowerbound, upperbound);
    PaintCommand->Exec();
    QCOMPARE((*x).size(), (*y).size());
    for(int i = 0; i < (*x).size()-1; ++i)
    {
        QVERIFY(fabs(fabs((*x)[i]) - (*y)[i]) < Error0);
    }
    // Testing for Integral
    IntegralCommand->SetParameter(str, lowerbound, upperbound);
    IntegralCommand->Exec();
    QVERIFY(fabs(*IntegralAns-ExpectedIntegral) < Error0);
    // Testing for Differential
    DifferentialCommand->SetParameter(str, lowerbound);
    DifferentialCommand->Exec();
    QVERIFY(fabs(*DifferentialAns-ExpectedDifferential) < Error0);
}

void MiniGrapherTest::SqrtTest()
{
    std::string str = "sqrt(x)";
    double lowerbound = 1;
    double upperbound = 10;
    const double ExpectedIntegral = 20.4152;
    const double ExpectedDifferential = 0.5;
    // Testing for Coordinates
    PaintCommand->SetParameter(str, lowerbound, upperbound);
    PaintCommand->Exec();
    QCOMPARE((*x).size(), (*y).size());
    for(int i = 0; i < (*x).size()-1; ++i)
    {
        QVERIFY(fabs(pow((*x)[i], 0.5) - (*y)[i]) < Error0);
    }
    // Testing for Integral
    IntegralCommand->SetParameter(str, lowerbound, upperbound);
    IntegralCommand->Exec();
    QVERIFY(fabs(*IntegralAns-ExpectedIntegral) < Error0);
    // Testing for Differential
    DifferentialCommand->SetParameter(str, lowerbound);
    DifferentialCommand->Exec();
    QVERIFY(fabs(*DifferentialAns-ExpectedDifferential) < Error0);
}

void MiniGrapherTest::CompoundFuncTest()
{
    std::string str = "10*sin(x)/(x^2+1)";
    double lowerbound = -10;
    double upperbound = 10;
    const double ExpectedIntegral = 0;
    const double ExpectedDifferential = -0.0724;
    // Testing for Coordinates
    PaintCommand->SetParameter(str, lowerbound, upperbound);
    PaintCommand->Exec();
    QCOMPARE((*x).size(), (*y).size());
    for(int i = 0; i < (*x).size()-1; ++i)
    {
        QVERIFY(fabs(sin((*x)[i])*10/((*x)[i]*(*x)[i]+1) - (*y)[i]) < Error0);
    }
    // Testing for Integral
    IntegralCommand->SetParameter(str, lowerbound, upperbound);
    IntegralCommand->Exec();
    QVERIFY(fabs(*IntegralAns-ExpectedIntegral) < Error0);
    // Testing for Differential
    DifferentialCommand->SetParameter(str, lowerbound);
    DifferentialCommand->Exec();
    QVERIFY(fabs(*DifferentialAns-ExpectedDifferential) < Error0);
}

QTEST_APPLESS_MAIN(MiniGrapherTest)

#include "MiniGrapher_Test.moc"
