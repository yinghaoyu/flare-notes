#include "flare/base/hazptr/entry_cache.h"

#include <array>

#include "flare/base/internal/annotation.h"
#include "flare/base/internal/logging.h"

namespace flare::hazptr {

inline constexpr std::size_t kEntryCacheSize = 8;

struct EntryCacheSlow {
  std::array<Entry*, kEntryCacheSize> cache;
  Entry** current = cache.data();
  Entry** top = cache.data() + cache.size();

  ~EntryCacheSlow() {
    while (current != cache.data()) {
      PutEntryOfDefaultDomain(*--current);
    }
  }
};

EntryCacheSlow* GetEntryCacheSlow() {
  FLARE_INTERNAL_TLS_MODEL thread_local EntryCacheSlow cache;
  return &cache;
}

void EntryCache::InitializeOnceCheck() {
  if (current == nullptr) {
    auto&& cache = GetEntryCacheSlow();
    FLARE_CHECK(top == nullptr);
    FLARE_CHECK(bottom == nullptr);
    current = cache->current;
    bottom = cache->cache.data();
    top = cache->cache.data() + cache->cache.size();
  }
}

Entry* EntryCache::GetSlow() noexcept {
  InitializeOnceCheck();
  return GetEntryOfDefaultDomain();
}

void EntryCache::PutSlow(Entry* entry) noexcept {
  InitializeOnceCheck();
  return PutEntryOfDefaultDomain(entry);
}

Entry* GetEntryOfDefaultDomain() noexcept {
  return GetDefaultHazptrDomain()->GetEntry();
}

void PutEntryOfDefaultDomain(Entry* entry) noexcept {
  GetDefaultHazptrDomain()->PutEntry(entry);
}

}  // namespace flare::hazptr
