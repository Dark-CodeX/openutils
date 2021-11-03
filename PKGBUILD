pkgname="sstring"
pkgver="41.0.0"
pkgrel="5"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=(
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/morse_code.h")

sha512sums=(
  "6e253e291d3e92d3e2aa01af30c2f8ab789a5b551e93e8d8341228e9b82901a2a2bd4413a0efb29521918de7028624645542314a863eb6cd6165c15fe045b452"
  "60e5bd923f45785059a0fcd0c60243e9ee7695c52c2d2c835c2cd6ff30918cdb105fe5fdb6ed230e3df1938a02bf4d962002bba257c586a2be94e5f77d4df0df"
  "853603de1b9884336a99cea7a3d0ad6b3106ccde04be3b85824440f9f6bc3e30b103d37d14bb8758c6916e113ed1fc37dc555ed83baebed86e20cb369786529d"
  "2ded8aa16151ff7f7d9264b51136a4dbdf5941725624a16447fc02bca9e3933aed2d9697366d2d7b2ca8e595b52d06743264737c8f4ffddca1926d19da0f62d4")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/sstring/morse_code.h"
  echo "Done!"
}
