#ifndef HALIDE_SERIALIZATION_H
#define HALIDE_SERIALIZATION_H

#include "Pipeline.h"
#include <string>
namespace Halide {

void serialize_pipeline(const Pipeline &pipeline, const std::string &filename);

}  // namespace Halide

#endif
