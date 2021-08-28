pkgname="sstring"
pkgver="1.1.2"
pkgrel="1"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h")
sha512sums=("b23d2a2ad915b538e50ea321b4a0314169ec1c56a3f76858ae63190f08a4ed1a2d2ec4538fe2880c375554020b43bb362fc949df714cda16dc3e4d654a309683")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  echo "Done!"
}
