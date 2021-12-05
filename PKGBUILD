pkgname="vector"
pkgver="1.4.2"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("5039e7ca926b1ccaecb6e701c70a619ba10499c3d38451e343086e81a2f8d2c4917796dfd12505c8884aad08eb77b19d0459f4ef46985bb2cf68dec9faa1e4ac" "afe7708bf4e7d5c5204c43b9c62bdf343e8d4472cb1e78750300fbe6e4f9c0bcb4f4f5b2be0e51186eed6791e47ad42d7ce4bc0f55fd80712b0bbaed1bbb7c40")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}