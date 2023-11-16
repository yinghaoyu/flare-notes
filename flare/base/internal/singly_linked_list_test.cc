#include "flare/base/internal/singly_linked_list.h"

#include "gtest/gtest.h"

namespace flare::internal {

struct C {
  SinglyLinkedListEntry chain;
  int x;
};

TEST(SinglyLinkedList, All) {
  SinglyLinkedList<C, &C::chain> list;
  list.push_back(new C{.x = 10});
  list.push_back(new C{.x = 11});
  list.push_front(new C{.x = 9});
  list.push_front(new C{.x = 8});
  ASSERT_FALSE(list.empty());
  ASSERT_EQ(4, list.size());
  ASSERT_EQ(8, list.front().x);
  ASSERT_EQ(11, list.back().x);

  C tmp{.x = 7};
  list.push_front(&tmp);
  list.push_front(new C{.x = 6});
  ASSERT_EQ(6, list.front().x);
  delete list.pop_front();
  ASSERT_EQ(7, list.front().x);
  list.pop_front();

  for (int i = 8; i <= 11; ++i) {
    ASSERT_EQ(i, list.front().x);
    delete list.pop_front();
  }
}

TEST(SinglyLinkedList, Splice) {
  SinglyLinkedList<C, &C::chain> list;
  list.push_back(new C{.x = 1});
  SinglyLinkedList<C, &C::chain> list2;
  ASSERT_EQ(1, list.front().x);
  ASSERT_EQ(1, list.back().x);
  list.splice(std::move(list2));
  ASSERT_EQ(1, list.front().x);
  ASSERT_EQ(1, list.back().x);
  list.push_back(new C{.x = 2});
  ASSERT_EQ(1, list.front().x);
  ASSERT_EQ(2, list.back().x);
  list.splice(std::move(list2));
  ASSERT_EQ(1, list.front().x);
  ASSERT_EQ(2, list.back().x);
  list2.push_back(new C{.x = 3});
  list.splice(std::move(list2));
  ASSERT_TRUE(list2.empty());
  ASSERT_EQ(1, list.front().x);
  ASSERT_EQ(3, list.back().x);
  list2.push_back(new C{.x = 4});
  list2.push_back(new C{.x = 5});
  list.splice(std::move(list2));
  ASSERT_TRUE(list2.empty());
  ASSERT_EQ(1, list.front().x);
  ASSERT_EQ(5, list.back().x);

  for (int i = 1; i <= 5; ++i) {
    ASSERT_EQ(i, list.front().x);
    delete list.pop_front();
  }
}

TEST(SinglyLinkedList, Swap) {
  SinglyLinkedList<C, &C::chain> list;
  list.push_back(new C{.x = 1});
  list.push_back(new C{.x = 2});
  list.push_back(new C{.x = 3});
  list.push_back(new C{.x = 4});
  ASSERT_EQ(4, list.size());
  ASSERT_EQ(1, list.front().x);
  ASSERT_EQ(4, list.back().x);

  SinglyLinkedList<C, &C::chain> list2;
  list.swap(list2);
  ASSERT_TRUE(list.empty());
  ASSERT_EQ(4, list2.size());
  ASSERT_EQ(1, list2.front().x);
  ASSERT_EQ(4, list2.back().x);

  list.swap(list2);
  ASSERT_TRUE(list2.empty());
  ASSERT_EQ(4, list.size());
  ASSERT_EQ(1, list.front().x);
  ASSERT_EQ(4, list.back().x);

  list2.push_back(new C{.x = 5});
  list2.push_back(new C{.x = 6});
  list2.push_back(new C{.x = 7});
  list2.push_back(new C{.x = 8});

  list.swap(list2);
  ASSERT_EQ(4, list2.size());
  ASSERT_EQ(1, list2.front().x);
  ASSERT_EQ(4, list2.back().x);
  ASSERT_EQ(4, list.size());
  ASSERT_EQ(5, list.front().x);
  ASSERT_EQ(8, list.back().x);

  for (int i = 1; i <= 4; ++i) {
    ASSERT_EQ(i, list2.front().x);
    delete list2.pop_front();
  }
  for (int i = 5; i <= 8; ++i) {
    ASSERT_EQ(i, list.front().x);
    delete list.pop_front();
  }

  ASSERT_TRUE(list.empty());
  ASSERT_TRUE(list2.empty());
}

TEST(SinglyLinkedList, Iterator) {
  SinglyLinkedList<C, &C::chain> list;
  list.push_back(new C{.x = 4});
  list.push_back(new C{.x = 5});
  list.push_back(new C{.x = 6});
  list.push_front(new C{.x = 3});
  list.push_front(new C{.x = 2});
  list.push_front(new C{.x = 1});

  int i = 1;
  for (auto v : list) {
    ASSERT_EQ(i++, v.x);
  }
  while (!list.empty()) {
    delete list.pop_front();
  }
}

TEST(SinglyLinkedList, ConstIterator) {
  SinglyLinkedList<C, &C::chain> list;
  list.push_back(new C{.x = 4});
  list.push_back(new C{.x = 5});
  list.push_back(new C{.x = 6});
  list.push_front(new C{.x = 3});
  list.push_front(new C{.x = 2});
  list.push_front(new C{.x = 1});

  int i = 1;
  for (auto v : std::as_const(list)) {
    ASSERT_EQ(i++, v.x);
  }
  while (!list.empty()) {
    delete list.pop_front();
  }
}

}  // namespace flare::internal
