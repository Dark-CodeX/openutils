pkgname="vector"
pkgver="1.4.2"
pkgrel="3"
pkgdesc="Vectors in C language."
arch=("x86_64" "i686")
conflicts=('vector')
depends=(gcc)
license=("MIT")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.h" "https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("5039e7ca926b1ccaecb6e701c70a619ba10499c3d38451e343086e81a2f8d2c4917796dfd12505c8884aad08eb77b19d0459f4ef46985bb2cf68dec9faa1e4ac" "c406d21b3a8448e9d0dcaea3f585498c11284304c0902279b77b5987ed6c0e33d9638c0a724b8e89126397ad832d924493168e27dfe0cdf4ac9510fddc614f47")

package() {
  echo "Vectors in C language."
  mkdir -p "${pkgdir}/usr/include/vector"
  cp "${srcdir}/vector.h" "${pkgdir}/usr/include/vector/vector.h"
  cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/vector/vector.hh"
  echo "Done!"
}