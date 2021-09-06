pkgname="sstring"
pkgver="4.1.5"
pkgrel="3"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h" "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h")
sha512sums=("d0590885dece181e8ad279554b81befdf3ec7365fc37871ee127b6d0201f0bd2c17935b2e1815d8f88fab5be2ac0b00580ea753823c0c31353033f400f53aa7c" "6be412ac354ed6ffae4b26eb90954cd230ff0ac9c6539fd563faf92126805aa9476fdb9ce71ec1edbce9f434b888b5ee9e844128ce8f3dcf894e4a7228b938cc")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  echo "Done!"
}
