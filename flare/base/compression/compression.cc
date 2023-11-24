#include "flare/base/compression/compression.h"

namespace flare {

FLARE_DEFINE_CLASS_DEPENDENCY_REGISTRY(compressor_registry, Compressor);
FLARE_DEFINE_CLASS_DEPENDENCY_REGISTRY(decompressor_registry, Decompressor);

}  // namespace flare
