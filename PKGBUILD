pkgname="sstring"
pkgver="4.2.8"
pkgrel="3"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h")
sha512sums=("5616c0a3467f59d08e8d2ac58d9f6e8c2740e511ccf66ea1ed63502f43beb0e03c09ff7f8159fdc8d89634579bb7f9455390f2173d69553615e4cebc716e9ebf" "688e3eedcd826553e243aabff2c890801ae34b5b5d94e0fcebd84c49f15fb70a38e744dfd049f6625307c4862616d5da126cdd190f4dbc0d3e664c042291c0e4")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  echo "Done!"
}
