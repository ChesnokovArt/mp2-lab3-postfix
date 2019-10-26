#include <gtest.h>

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  int i = RUN_ALL_TESTS();
  char c;
  std::cin >> c;
  return i;
}
