#ifndef MODEL_H
#define MODEL_H

#include "../Common/etlbase.h"
#include "../Algorithm/lexer.h"
#include <memory>
#include <vector>
#include <QVector>
#include <string>

#define PointNumber 1000

class Model: public Proxy_PropertyNotification<Model>
{
public:
    Model();
    ~Model();
    std::shared_ptr<QVector<double>> getX();
    std::shared_ptr<QVector<double>> getY();
    std::shared_ptr<double> getIntegral();
    std::shared_ptr<double> getDifferential();
    std::string getString();
    void differential(double x);
    void integral(double a,double b);
    void cal(double a,double b);
    bool buildtree(const std::string str);
private:
    std::shared_ptr<lexer> lexer;
    std::shared_ptr<QVector<double>> x,y;
    std::shared_ptr<double> IntegralAns,DifferentialAns;
};

#endif // MODEL_H
