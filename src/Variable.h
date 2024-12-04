#ifndef VARIABLE_H
#define VARIABLE_H

#include <vector>
#include "IMesh.h"


class Variable
{
private:
    /* data */
    IMesh*mesh;
    std::vector<double> values;

public:
    /**
     * @brief 构造函数，创造接引指针，初始化网格大小
     */
    Variable(IMesh*mesh);
    /**
     * @brief 重新加载opera
     */
    double& operator[](int i);
    //获取变量大小
    int size() const;
};



#endif