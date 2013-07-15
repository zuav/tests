#pragma once

extern "C" int foo();

int bar();

extern "C" {

    namespace A {

        int baz();
    }
}
