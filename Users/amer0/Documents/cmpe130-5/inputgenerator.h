#ifndef INPUTGENERATOR_H
#define INPUTGENERATOR_H
#include<listnode.h>
#include<vector>
#include<QString>

typedef std::vector<QString> name_data;

class inputGenerator
{
public:
     name_data names;
public:
    inputGenerator();
    QString random_name();
};

#endif // INPUTGENERATOR_H
