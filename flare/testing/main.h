#ifndef FLARE_TESTING_MAIN_H_
#define FLARE_TESTING_MAIN_H_

namespace flare::testing {

// Do a full initialization and run all tests (in worker pool).
int InitAndRunAllTests(int* argc, char** argv);

// It's possible to define a "weak" `main` and somehow instruct building system
// to link to our `main`, so as to provide end user with the same experience as
// of gtest (not requiring users to define `main` at all).
//
// But it's just too intrusive..
//
// If you need to do some initialization yourself before running UTs, call
// `InitAndRunAllTests(...)` (see above) yourself.
#define FLARE_TEST_MAIN                                       \
  int main(int argc, char** argv) {                           \
    return ::flare::testing::InitAndRunAllTests(&argc, argv); \
  }

}  // namespace flare::testing

#endif  // FLARE_TESTING_MAIN_H_
