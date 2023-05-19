#include "logger/log.h"

void foo() {
  LOG_FATAL << "fatal log";
}

void bar() {
  foo();
}

int main() {
  bar();
}
