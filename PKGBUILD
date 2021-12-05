pkgname="vector"
pkgver="1.4.4"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("542ca2ea983718e62b11ac4298972b69ed05acb15a30e88b71eafc704b48d86e0a0286b4f02dab28a52085e537fe93936b57cb09ecea5bf43cc8319b018768ca" "0855ae3540ccaf386c789e4fe702fc0444ebef06843df33d9bb0a5eec5d075c527deb5b376c1422d280a9a0d17fe404854fd9f6b127a7802b08526b17d340e39")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}