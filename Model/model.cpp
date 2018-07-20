#include "model.h"


Model::Model()
{
    lexer = std::make_shared<class lexer>();
    x = std::make_shared<QVector<double>>();
    y = std::make_shared<QVector<double>>();
    IntegralAns = std::make_shared<double>();
    DifferentialAns = std::make_shared<double>();
}

Model::~Model()
{
}

void Model::cal(double a,double b)
{
    while(!x->empty())x->pop_back();
    while(!y->empty())y->pop_back();
    for(int i=0;i<PointNumber;i++)
    {
        x->push_back(a+(b-a)*i*1.0/PointNumber);
        y->push_back(lexer->calculate((*x)[i]));
    }
    Fire_OnPropertyChanged("Lexer");
}

std::shared_ptr<QVector<double>> Model::getX()
{
    return x;
}

std::shared_ptr<QVector<double>> Model::getY()
{
    return y;
}

std::shared_ptr<double> Model::getDifferential()
{
    return DifferentialAns;
}

std::shared_ptr<double> Model::getIntegral()
{
    return IntegralAns;
}

bool Model::buildtree(const string str)
{
    lexer->setstring(str);
    if(lexer->strtotree())return true;
    else return false;
}

void Model::differential(double x)
{
    *DifferentialAns=lexer->differential(x);
    Fire_OnPropertyChanged("Differential");
}

void Model::integral(double a,double b)
{
    *IntegralAns=lexer->integral(a,b);
    Fire_OnPropertyChanged("Integral");
}

std::string Model::getString()
{
    return lexer->getString();
}
