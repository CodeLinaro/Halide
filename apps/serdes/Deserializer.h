#ifndef HALIDE_DESERIALIZER_H
#define HALIDE_DESERIALIZER_H

#include <string>
#include <vector>

#include "Halide.h"
#include "halide_ir_generated.h"

class Deserializer {
public:
    Deserializer() = default;

    Halide::Pipeline deserialize(const std::string &filename);

private:
    // helper functions to deserialize each type of object
    std::string deserialize_string(const flatbuffers::String *str);

    Halide::Type deserialize_type(const Halide::Serialize::Type *type);

    Halide::Internal::Function deserialize_function(const Halide::Serialize::Func *function);

    Halide::Internal::Stmt deserialize_stmt(uint8_t type_code, const void *stmt);

    Halide::Expr deserialize_expr(uint8_t type_code, const void *expr);

    Halide::Range deserialize_range(const Halide::Serialize::Range *range);
};

#endif
