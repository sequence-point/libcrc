#include <libunittest/unittest.hxx>

#include <libcrc/crc32.hxx>

DEFINE_TEST("crc32")
{
  crc::crc32 crc32;
  crc32.update("hello, world");
  crc32.finalize();

  auto checksum = to_hex(crc32);

  TEST_EQUAL(checksum, "ffab723a");
}
