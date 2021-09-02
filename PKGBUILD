pkgname="sstring"
pkgver="3.0.1"
pkgrel="2"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h")
sha512sums=("4fd02e0c5826e06efe6148f99f4afd7f6eb4f0c25e6c6afa2889498e7363ec3fc856ac6b74ea75aa3bbd6964cbd0759eed5eed47cc436c7fe9052ab0c0291c53")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  echo "Done!"
}
