#ifndef MODEL_H
#define MODEL_H

#include "../Common/etlbase.h"

class Model: public Proxy_PropertyNotification<Model>, public Proxy_CommandNotification<Model>
{
public:
    Model();
    ~Model();
private:

};

#endif // MODEL_H
