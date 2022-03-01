pkgname="openutils-sstring"
pkgver="1.6.0"
pkgrel="8"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('openutils-sstring')
depends=(gcc)
license=("MIT")
source=(
  "https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.h"
  "https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/prototype_err.h"
  "https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/binary.h"
  "https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/morse_code.h"
  "https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.hh")

sha512sums=(
  "91ed0dc3fde2fee8050cf22cc19387684e783a78ed38bbdd2dcfb7cd32801d111867572db5e8724c41d35547363656b49db53d23c9e5b3437f7edb1b1bc15a0e"
  "1184cd7f3a3ef1eef7fb305dc5d2cc4a62c742925852e4b761555a59c30d9c43bc0dd62aa02b62c8a9c7dff5a6046f7cf7d12d93b7845db70a7e7bbabfbdef37"
  "b555083430b0797f0b35b739340219ee997254268da2270fa276d3b3746fdf43ae8dff35f3e3fba5c2639621cda9d9b7deedfa4d4bfdfdf14b3b197265859f9e"
  "94e6cba05c144277212a6f2e4af98836475be792f44fd4d81fad067daed74a16b7b330973b465b8cd80271299aa4e3363798886a12cf6eaad3b3fb63faea69d3"
  "9694dffeefe43b021bd56d0956ca99c500595e309dfb4c54b4521cadce74d8b373fea2bf491b9f8997ad9d3d08dbc746a66a429ecc87d085257cdfd9bbde6dd9")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/openutils/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/openutils/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/openutils/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/openutils/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/openutils/sstring/morse_code.h"
  cp "${srcdir}/sstring.hh" "${pkgdir}/usr/include/openutils/sstring/sstring.hh"
  echo "Done!"
}
