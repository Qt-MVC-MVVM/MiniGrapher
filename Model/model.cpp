#include "model.h"


Model::Model()
{
    lexer = std::make_shared<class lexer>();
    x = std::make_shared<QVector<double>>();
    y = std::make_shared<QVector<double>>();
}

Model::~Model()
{

}

void Model::cal(double a,double b)
{

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

bool Model::buildtree(const string str)
{
    lexer->setstring(str);
    if(lexer->strtotree())return true;
    else return false;
}

double Model::differential(double x)
{
    Fire_OnPropertyChanged("Lexer");
    return lexer->differential(x);
}

double Model::integral(double a,double b)
{
    Fire_OnPropertyChanged("Lexer");
    return lexer->integral(a,b);
}

std::string Model::getString()
{
    return lexer->getString();
}
