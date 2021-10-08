pkgname="vector"
pkgver="11.2.1"
pkgrel="2"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h")
sha512sums=("4fda2525e281b897531b9dbfd8befc9e1f724914c0ccf1d4e2fe432286b7ca2d0cdfd50b0230fdf6043c4fe20a61fa704df69582aa8496cd2097024a64107c53")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  echo "Done!"
}