pkgname="vector"
pkgver="26.0.0"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("3a0720063043b260bc6d97b217ceec7276c10751648321c169267dc58e059cb4c44254d74077ac4c8e1a8bf8569183731c73ec8e1d79adfe122c27d8ea08024a" "5e41a7dc28882312d7ea29d3ac4d0090414c4489b4e7422839f2df3705e96197590cb7592ff833bc9a3602a6503779edee0920759a5cb87a6f4432901a7522aa")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}