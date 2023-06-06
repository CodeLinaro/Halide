#ifndef HALIDE_SERIALIZER_H
#define HALIDE_SERIALIZER_H

#include <string>
#include <utility>
#include <vector>

#include "Halide.h"
#include "halide_ir_generated.h"

class Serializer {
public:
    Serializer() = default;

    void serialize(const Halide::Pipeline &pipeline, const std::string &filename);

private:
    // helper functions to serialize each type of object
    flatbuffers::Offset<flatbuffers::String> serialize_string(flatbuffers::FlatBufferBuilder &builder, const std::string &str);

    flatbuffers::Offset<Halide::Serialize::Type> serialize_type(flatbuffers::FlatBufferBuilder &builder, const Halide::Type &type);

    // Stmt is special because it is a union type so we need to return both the type and serialized object
    std::pair<Halide::Serialize::Stmt, flatbuffers::Offset<void>> serialize_stmt(flatbuffers::FlatBufferBuilder &builder, const Halide::Internal::Stmt &stmt);

    // similar to Stmt, Expr is a union type so we need to return both the type and serialized object
    std::pair<Halide::Serialize::Expr, flatbuffers::Offset<void>> serialize_expr(flatbuffers::FlatBufferBuilder &builder, const Halide::Expr &expr);

    flatbuffers::Offset<Halide::Serialize::Func> serialize_function(flatbuffers::FlatBufferBuilder &builder, const Halide::Internal::Function &function);

    flatbuffers::Offset<Halide::Serialize::Range> serialize_range(flatbuffers::FlatBufferBuilder &builder, const Halide::Range &range);

    flatbuffers::Offset<Halide::Serialize::Bound> serialize_bound(flatbuffers::FlatBufferBuilder &builder, const Halide::Internal::Bound &bound);

    flatbuffers::Offset<Halide::Serialize::StorageDim> serialize_storage_dim(flatbuffers::FlatBufferBuilder &builder, const Halide::Internal::StorageDim &storage_dim);

    flatbuffers::Offset<Halide::Serialize::LoopLevel> serialize_loop_level(flatbuffers::FlatBufferBuilder &builder, const Halide::LoopLevel &loop_level);

    flatbuffers::Offset<Halide::Serialize::FuncSchedule> serialize_func_schedule(flatbuffers::FlatBufferBuilder &builder, const Halide::Internal::FuncSchedule &func_schedule);
};

#endif
