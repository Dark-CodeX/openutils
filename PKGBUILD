pkgname="openutils-sstring"
pkgver="1.6.3"
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
  "27709511ddd06ebfa50e2ef6a004ab47ad3a0f257315d45847beac8a597b65dd5af6624a195169b1c212a9c77176c494a4eee866338671746232dabb3c887dc4"
  "b3b8f6a5dd3801f919211826f5daa1bb93aa77a3d7a654e47dfd109c92bbafaf8136f9318b64be8faad36619c04ecc0b6806b016682e5581f430b7485bb82d76"
  "9e9d2e81066d0814d7f87ceb49e3893279f20e2e94bd297064167354313d6bbe98f3ab6979cd460a1ac35fd9f4c909695b7502dc6042e301fbe1c98641c82d8d"
  "619796126a21363bcce38d306b7ed61dfa1b200ee9d87cae875091027253256fd30778940f8c8f025679449b2b13a4c42256c91abd1853c2e28e4cb1ba2c0cfc"
  "64fc2f83e17b7e6ede773a4705ec1d354cd2c2678c60a1f44799096fc0876e638c99cca33130440e79880b32bdc58ab97463c45abe9dfc21b16a92a8ffa8470b")

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
