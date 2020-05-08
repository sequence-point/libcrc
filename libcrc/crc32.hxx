#ifndef libcrc__crc32_hxx_
#define libcrc__crc32_hxx_

#include <cstdint>
#include <functional>
#include <iomanip>
#include <istream>
#include <iterator>
#include <sstream>
#include <string>

namespace crc {

class crc32 {
public:
  void
  reset();

  void
  update(char byte);
  void
  update(std::string const& str);
  void
  update(std::istream& in);

  void
  finalize();

  std::uint32_t
  checksum() const;

private:
  std::uint32_t checksum_{ 0xFFFFFFFF };
};

std::string
to_string(crc32 const& checksum);

std::string
to_hex(crc32 const& checksum);

} // namespace crc

#include <libcrc/crc32.ixx>

#endif
