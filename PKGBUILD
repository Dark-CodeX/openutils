pkgname="vector"
pkgver="11.2.0"
pkgrel="2"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h")
sha512sums=("fc2e0f6a1fb3f2f9b889891e5c12c1c1dda839f3332072663d2e6fbedc5cd9854d5f1ec9445be813b91f2a4c17fac8f42e920ad2f1efe2f90e76a752171ce607")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  echo "Done!"
}