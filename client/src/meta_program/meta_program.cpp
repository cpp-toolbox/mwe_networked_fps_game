#include "meta_program.hpp"

LazyConstruction<MetaProgram, std::vector<meta_utils::MetaType>> meta_program = LazyConstruction<MetaProgram, std::vector<meta_utils::MetaType>>(meta_utils::meta_types.get_concrete_types());

