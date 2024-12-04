#include "Variable.h"
/**
 * @brief 构造函数根据mesh大小初始化values大小
 * @param Imesh*mesh 接受Imesh的类型指针mesh
 */
Variable::Variable(IMesh* mesh) : mesh(mesh) {
    values.resize(mesh->x_size(), 0.0);  // 初始化为0
}

//重新加载operator，返回values中的第i个元素
double& Variable::operator[](int i){
    return values[i];
}

int Variable::size() const{
    return values.size();
}
