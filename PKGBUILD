pkgname="sstring"
pkgver="49.4.0"
pkgrel="7"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=(
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/morse_code.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.hh")

sha512sums=(
  "a4eea7b8cd56f5541a0a9446f696c4301f83224ab9c7dbdec920cf4c6b9fe0e506972c8d5d0a72f2a776ea3c3cc22ef1f35c06f8f4f34db37fdcf459251e3f2c"
  "ff4543baf8f1fd5ba7414d314adad74f83b940f55d4dbace60974dee1c38fbb8fcef9a2b92428deb42395c1ed8b281147bf007518f75f014e0789dabd35392d3"
  "9c2677da707b4fb753f0788c8b8b47d1572aad4e564951685894e56197331f3dc7ba739b71c655376ed633ef7ca62b5eee704c2a5931f34410e90fab9241ffaa"
  "86fd07121d62cae5f94c59b3cafff73f1de5409932acf0fdb87869c9093c16992102f4c0830280c05e967ef084f3ea26edf4e8b762906fd8ea5168fcf0d9ab69"
  "9d111d4e2ce39b154b7d3475210c7a2edd44e8da4f3aa88b5782c23ee36838506051e7c3e638f2c38f1f0c97202db4d975177883c746a6fbd8c530d9cecfe998")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/sstring/morse_code.h"
  cp "${srcdir}/sstring.hh" "${pkgdir}/usr/include/sstring/sstring.hh"
  echo "Done!"
}
