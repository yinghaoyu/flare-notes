#include "flare/base/hazptr/hazptr_object.h"

#include "flare/base/hazptr/hazptr_domain.h"

namespace flare::hazptr {

void Object::PushRetired(HazptrDomain* domain) { domain->Retire(this); }

}  // namespace flare::hazptr
