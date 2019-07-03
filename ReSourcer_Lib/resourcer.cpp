#include "resourcer.hpp"
#include <map>
#include <string>

extern std::map<std::string,std::vector<char> > __RCC__DATA__STORE__;

ReSourcer::ReSourcer()
{
}

std::vector<char> ReSourcer::getItem(std::string id)
{
    return __RCC__DATA__STORE__[id];
}

std::string ReSourcer::getItemText(std::string id)
{
    return &__RCC__DATA__STORE__[id][0];
}

size_t ReSourcer::itemSize(std::string id)
{
    return __RCC__DATA__STORE__[id].size();
}

void *ReSourcer::rawItem(std::string id)
{
    return &__RCC__DATA__STORE__[id].front();
}
