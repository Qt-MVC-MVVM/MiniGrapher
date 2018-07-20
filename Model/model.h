#ifndef MODEL_H
#define MODEL_H

#include "../Common/etlbase.h"
#include "../Algorithm/lexer.h"
#include <memory>
#include <vector>
#include <QVector>
#include <string>

#define PointNumber 1000

class Model: public Proxy_PropertyNotification<Model>, public Proxy_CommandNotification<Model>
{
public:
    Model();
    ~Model();
    void cal(int a,int b);
    bool buildtree(const std::string str);
    double differential(double x);
    double integral(double a,double b);
    std::shared_ptr<QVector<double>> getX();
    std::shared_ptr<QVector<double>> getY();
    std::string getString();
private:
    std::shared_ptr<lexer> lexer;
    std::shared_ptr<QVector<double>> x,y;
};

#endif // MODEL_H
