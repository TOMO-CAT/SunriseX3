#pragma once

#include <memory>
#include <sstream>
#include <string>

#include "cpptoml/cpptoml.h"

namespace util {

/*
 * 获取 TOML 配置中的值, 失败返回false
 * */
template <typename T>
bool ParseTomlValue(std::shared_ptr<cpptoml::table> g, const std::string& key, T* value) {
  auto val = g->get_qualified_as<T>(key);
  if (!val) {
    return false;
  }
  *value = *val;

  std::ostringstream oss;
  oss << value;
  return true;
}

}  // namespace util
