pkgname="openutils-vector"
pkgver="1.5.7"
pkgrel="4"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('openutils-vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("7faee4468fedbc8cdfb29fcd3686b566e8dbd1dea48d76b82579167f484aaa26d081e28af32ea7f828befb6211267287271fded85ec7d440b9cb288839801498" "0d68b67d164e17a9c58766e649b767e0e1b7f5fdbc279c89096c925523bd7e0f05c4b54ec7614d50b1f5ca44ad761d9e84be3aba3b54d945e160050aec95238b")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/openutils/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/openutils/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/openutils/vector/vector.hh"
  echo "Done!"
}