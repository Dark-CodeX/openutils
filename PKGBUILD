pkgname="sstring"
pkgver="2.3.1"
pkgrel="1"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h")
sha512sums=("6a8f101a3de3514a2df70dc8d686f402fcb3de0165e0e7b1112af630aebb9794236518da5aea4a48b0b4c2cf2a8f8ed302be369229b10e8491bd6add8bd0f106")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  echo "Done!"
}
