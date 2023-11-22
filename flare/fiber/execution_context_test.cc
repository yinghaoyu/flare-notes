#include "flare/fiber/execution_context.h"

#include "gtest/gtest.h"

#include "flare/fiber/async.h"
#include "flare/fiber/future.h"
#include "flare/fiber/latch.h"
#include "flare/fiber/timer.h"
#include "flare/testing/main.h"

using namespace std::literals;

namespace flare::fiber {

TEST(ExecutionContext, NullContext) {
  ASSERT_EQ(nullptr, ExecutionContext::Current());
}

TEST(ExecutionContext, RunInContext) {
  ASSERT_EQ(nullptr, ExecutionContext::Current());
  auto ctx = ExecutionContext::Create();
  static ExecutionLocal<int> els_int;

  ctx->Execute([&] {
    ASSERT_EQ(ExecutionContext::Current(), ctx.Get());
    *els_int = 10;
    ASSERT_EQ(10, *els_int);
  });
  ctx->Execute([&] {
    ASSERT_EQ(ExecutionContext::Current(), ctx.Get());
    ASSERT_EQ(10, *els_int);
  });

  auto ctx2 = ExecutionContext::Create();
  ctx2->Execute([&] {
    ASSERT_EQ(ExecutionContext::Current(), ctx2.Get());
    *els_int = 5;
    ASSERT_EQ(5, *els_int);
  });
  ctx->Execute([&] {
    ASSERT_EQ(ExecutionContext::Current(), ctx.Get());
    ASSERT_EQ(10, *els_int);
  });
  ctx2->Execute([&] {
    ASSERT_EQ(ExecutionContext::Current(), ctx2.Get());
    ASSERT_EQ(5, *els_int);
  });
}

TEST(ExecutionContext, AsyncPropagation) {
  ASSERT_EQ(nullptr, ExecutionContext::Current());
  auto ctx = ExecutionContext::Create();
  static ExecutionLocal<int> els_int;

  ctx->Execute([&] {
    *els_int = 10;
    auto f1 = fiber::Async([&] {
      ASSERT_EQ(10, *els_int);
      fiber::BlockingGet(Async([&] { ASSERT_EQ(10, *els_int); }));
    });
    auto f2 = fiber::Async([&] { ASSERT_EQ(10, *els_int); });
    fiber::BlockingGet(WhenAll(&f1, &f2));
  });
}

TEST(ExecutionLocal, All) {
  ASSERT_EQ(nullptr, ExecutionContext::Current());
  auto ctx = ExecutionContext::Create();
  static ExecutionLocal<int> els_int;
  static ExecutionLocal<int> els_int2;
  static ExecutionLocal<double> els_dbl;

  ctx->Execute([&] {
    ASSERT_EQ(ExecutionContext::Current(), ctx.Get());
    *els_int = 10;
    *els_int2 = 11;
    *els_dbl = 12;
  });
  ctx->Execute([&] {
    ASSERT_EQ(ExecutionContext::Current(), ctx.Get());
    ASSERT_EQ(10, *els_int);
    ASSERT_EQ(11, *els_int2);
    ASSERT_EQ(12, *els_dbl);
  });

  auto ctx2 = ExecutionContext::Create();
  ctx2->Execute([&] {
    ASSERT_EQ(ExecutionContext::Current(), ctx2.Get());
    *els_int = 0;
    *els_int2 = 1;
    *els_dbl = 2;
  });
  ctx2->Execute([&] {
    ASSERT_EQ(ExecutionContext::Current(), ctx2.Get());
    ASSERT_EQ(0, *els_int);
    ASSERT_EQ(1, *els_int2);
    ASSERT_EQ(2, *els_dbl);
  });
  ctx->Execute([&] {
    ASSERT_EQ(ExecutionContext::Current(), ctx.Get());
    ASSERT_EQ(10, *els_int);
    ASSERT_EQ(11, *els_int2);
    ASSERT_EQ(12, *els_dbl);
  });
  ctx2->Execute([&] {
    ASSERT_EQ(ExecutionContext::Current(), ctx2.Get());
    ASSERT_EQ(0, *els_int);
    ASSERT_EQ(1, *els_int2);
    ASSERT_EQ(2, *els_dbl);
  });
}

}  // namespace flare::fiber

FLARE_TEST_MAIN
