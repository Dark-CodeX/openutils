pkgname="sstring"
pkgver="2.3.1"
pkgrel="1"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h")
sha512sums=("065ff06194c2d767c7fa89bf81b2cdd93f89d19fde95a6f7cb77e3347e31ae6d6fef34b751cc9558792f6f2ffad3c6b7d1d189a473f740fc70591f34d218224e")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  echo "Done!"
}
